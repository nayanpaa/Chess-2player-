//
//  pieces.cpp
//  chess1_game
//
//  Created by Nayan Paavalar on 12/24/22.
//


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>

const std::string ROWS[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};

const std::string COLS[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};

//const std::vector<std::pair<std::string, int>> ROWSKEY = { {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}};

const std::vector<std::pair<std::string, int>> COLSKEY = { {"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5}, {"f", 6}, {"g", 7}, {"h", 8}};


const std::string *rowPtr (std::string number, std::string letter) {
    int counter = 0;
    int i = 0;
    const std::string *numptr = nullptr;
    while (counter == 0){
        if (ROWS[i] == number) {
            counter++;
            numptr = &ROWS[i];
        }
        else {
            i++;
        }
    }
    return numptr;
}

const std::string *colPtr (std::string number, std::string letter) {
    int counter = 0;
    int j = 0;
    const std::string *letptr = nullptr;
    while (counter == 0){
        if (COLS[j] == letter) {
            counter++;
            letptr = &COLS[j];
        }
        else {
            j++;
        }
    }
    return letptr;
}

int findIndex(std::string number, std::string letter) {
    int length  = letter.length();
    char* char_array = new char[length + 1];
    std::strcpy(char_array, letter.c_str());
    int index = (((8 - std::stoi(number)) * 8) + (char_array[0] - 96));
    delete[] char_array;
    return index;
}




class pieces {
    //char color; //valid colors are b or w OR ""

    
public:
    //for empty
    char color; //valid colors are b or w OR e
    pieces(char color_in) : color(color_in) {}
    
    friend std::ostream & operator<<(std::ostream &os, const pieces &piece) {
        return os << ".";

    }
    
};

class King : public pieces {
public:
    King(char color_in)
    : pieces(color_in), check(false), checkmate(false)  {
    }
    
    //EEFECTS: validmoves
    void listMoves (std::string number, std::string letter) {
        validMoves.clear();
        if (number == "1") {
            if (letter == "a") {        //corner
                validMoves.push_back("1b");
                validMoves.push_back("2a");
                validMoves.push_back("2b");
            }
            else if (letter == "h") {   //corner
                validMoves.push_back("1g");
                validMoves.push_back("2h");
                validMoves.push_back("2g");
            }
            else {                      //bottom side
                king_helper_horizontal(number, letter);
            }
        }
        else if (number == "8") {
            if (letter == "a") {        //corner
                validMoves.push_back("8b");
                validMoves.push_back("7a");
                validMoves.push_back("7b");
            }
            else if (letter == "h") {   //corner
                validMoves.push_back("8g");
                validMoves.push_back("7h");
                validMoves.push_back("7g");
            }
            else {                      //top side
                king_helper_horizontal(number, letter);
            }
        }
        else if (letter == "a" || letter == "h") {       //left side
            king_helper_horizontal(number, letter);
        }
       // else if (letter == "h") {       //right side
            
      //  }
        else {                          //middle
            king_helper_middle(number, letter);
        }
    }
    
    void king_helper_horizontal(std::string number, std::string letter) {
        int counter = 0;
        int i = 0;
        const std::string *ptr = nullptr;
        while (counter == 0){
            if (COLS[i] == letter) {
                counter++;
                ptr = &COLS[i];
            }
            else {
                i++;
            }
        }
        --ptr;            //first letter
        const std::string *firstrow = ptr;
        std::string nextRowNum;
        for (int i = 0; i < 6; i++) {
            std::string moveLetter = "";
            if (i < 3) {
                moveLetter.append(number);
                moveLetter.append(*firstrow);
                if (*firstrow != letter) {
                    validMoves.push_back(moveLetter);
                }
                ++firstrow;
            }
            else {
                if (number == "1") {
                    nextRowNum = "2";
                }
                else {
                    nextRowNum = "7";
                }
                moveLetter.append(nextRowNum);
                moveLetter.append(*ptr);
                validMoves.push_back(moveLetter);
                ++ptr;
            }
        }
    }
    
    void king_helper_vert(std::string number, std::string letter) {
        int counter = 0;
        int i = 0;
        const std::string *ptr = nullptr;
        while (counter == 0){
            if (ROWS[i] == number) {
                counter++;
                ptr = &ROWS[i];
            }
            else {
                i++;
            }
        }
        --ptr;
        const std::string *firstcol = ptr;
        std::string nextRowLet;
        for (int i = 0; i < 6; i++) {
            std::string moveLetter = "";
            if (i < 3) {
                
                moveLetter.append(*firstcol);
                moveLetter.append(letter);
                if (*firstcol != number) {
                    validMoves.push_back(moveLetter);
                }
                ++firstcol;
            }
            else {
                if (letter == "a") {
                    nextRowLet = "b";
                }
                else {
                    nextRowLet = "g";
                }
                moveLetter.append(*ptr);
                moveLetter.append(nextRowLet);
                validMoves.push_back(moveLetter);
                ++ptr;
            }
        }
    }
    
    void king_helper_middle(std::string number, std::string letter) {
        int counter = 0;
        int i = 0;
        const std::string *numptr = nullptr;
        while (counter == 0){
            if (ROWS[i] == number) {
                counter++;
                numptr = &ROWS[i];
            }
            else {
                i++;
            }
        }
        int counter2 = 0;
        int j = 0;
        const std::string *letptr = nullptr;
        while (counter2 == 0){
            if (COLS[j] == letter) {
                counter2++;
                letptr = &COLS[j];
            }
            else {
                j++;
            }
        }
        --numptr;
        --letptr;
        const std::string *templetptr = letptr;
        const std::string *tempnumptr = numptr;
        for (int i = 0; i < 9; i++) {
            std::string moveLetter = "";
            if ((i > 0) && (i % 3 == 0)) {
                templetptr = letptr;
                ++tempnumptr;
            }
            moveLetter.append(*tempnumptr);
            moveLetter.append(*templetptr);
            if (*tempnumptr == number) {
                if (*templetptr != letter) {
                    validMoves.push_back(moveLetter);
                }
            }
            else {
                validMoves.push_back(moveLetter);
            }
            ++templetptr;
        }
    }
    
    void printMoves() {
        for (size_t i = 0; i < validMoves.size(); ++i) {
            std::cout << validMoves[i] << " ";
        }
        std::cout << "\n";
    }
    
    friend std::ostream & operator<<(std::ostream &os, const King &kingpiece) {
        if (kingpiece.color == 'b') {
            return os << "♔"; //black
        }
        return os << "♚"; //white

    }
    
    //cout operator for all pieces
    
private:
    std::vector<std::string> validMoves;
    bool check; //t or f
    bool checkmate; //t or f
};

class Rook : public pieces {
public:
    Rook(char color_in)
    : pieces(color_in) {}
    
    //a function that takes in the postion and adjusts valid moves to say the pieces'
    //valid moves
    //position must be in the form of numberletter
    // Ex: rook position: 3C
    //EEFECTS: validmoves
    void listMoves (std::string number, std::string letter) {
        //go through and add everything to valid moves
        //go through and add all the rows with the corrent column
            //go through and add all the columns with the current row
        validMoves.clear();
        for (int i = 0; i < 8; i++) {
            std::string move = "";
            if (ROWS[i] != number) {
                move.append(ROWS[i]);
                move.append(letter);
                validMoves.push_back(move);
            }
        }
        for (int i = 0; i < 8; i++) {
            std::string move = "";
            if (COLS[i] != letter) {
                move.append(number);
                move.append(COLS[i]);
                validMoves.push_back(move);
            }
        }
    }
    
    void printMoves() {
        for (size_t i = 0; i < validMoves.size(); ++i) {
            std::cout << validMoves[i] << " ";
        }
        std::cout << "\n";
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Rook &rookpiece) {
        if (rookpiece.color == 'b') {
            return os << "♖"; //black
        }
        return os << "♜"; //white

    }
    
private:
   // char *symbol; do i need this because base has this
    //char color; //valid colors are b or w     MIGHT NOT NEED THIS
    std::vector<std::string> validMoves;
};

class Bishop : public pieces {
public:
    Bishop(char color_in)
    : pieces(color_in) {}
    
    void listMoves (std::string number, std::string letter) {
        validMoves.clear();
        bishop_helper_upR(number, letter);
        bishop_helper_upL(number, letter);
        bishop_helper_downR(number, letter);
        bishop_helper_downL(number, letter);
    }
    
    void bishop_helper_upR (std::string number, std::string letter) {
       const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS + 7) && (letptr != COLS + 7)) {
            ++numptr;
            ++letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void bishop_helper_upL (std::string number, std::string letter) {
        const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS + 7) && (letptr != COLS)) {
            ++numptr;
            --letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void bishop_helper_downR (std::string number, std::string letter) {
       const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS) && (letptr != COLS + 7)) {
            --numptr;
            ++letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void bishop_helper_downL (std::string number, std::string letter) {
       const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS) && (letptr != COLS)) {
            --numptr;
            --letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void printMoves() {
        for (size_t i = 0; i < validMoves.size(); ++i) {
            std::cout << validMoves[i] << " ";
        }
        std::cout << "\n";
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Bishop &bishoppiece) {
        if (bishoppiece.color == 'b') {
            return os << "♗"; //black
        }
        return os << "♝"; //white

    }
    
    
    
private:
    std::vector<std::string> validMoves;
};

class Queen : public pieces {
public:
    Queen(char color_in)
    : pieces(color_in) {}
    
    void listMoves (std::string number, std::string letter) {
        validMoves.clear();
        queen_helper_upR(number, letter);
        queen_helper_upL(number, letter);
        queen_helper_downR(number, letter);
        queen_helper_downL(number, letter);
        queen_helper_straights(number, letter);
    }
    
    void queen_helper_upR (std::string number, std::string letter) {
       const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS + 7) && (letptr != COLS + 7)) {    //FIX
            ++numptr;
            ++letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void queen_helper_upL (std::string number, std::string letter) {
        const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS + 7) && (letptr != COLS)) {    //FIX
            ++numptr;
            --letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void queen_helper_downR (std::string number, std::string letter) {
       const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS) && (letptr != COLS + 7)) {    //FIX
            --numptr;
            ++letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void queen_helper_downL (std::string number, std::string letter) {
       const std::string *numptr = rowPtr(number, letter);
        const std::string *letptr = colPtr(number, letter);
        while ((numptr != ROWS) && (letptr != COLS)) {  //FIX
            --numptr;
            --letptr;
            std::string move = "";
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void queen_helper_straights (std::string number, std::string letter) {
        //go through and add everything to valid moves
        //go through and add all the rows with the corrent column
            //go through and add all the columns with the current row
        for (int i = 0; i < 8; i++) {
            std::string move = "";
            if (ROWS[i] != number) {
                move.append(ROWS[i]);
                move.append(letter);
                validMoves.push_back(move);
            }
        }
        for (int i = 0; i < 8; i++) {
            std::string move = "";
            if (COLS[i] != letter) {
                move.append(number);
                move.append(COLS[i]);
                validMoves.push_back(move);
            }
        }
    }
    
    void printMoves() {
        for (size_t i = 0; i < validMoves.size(); ++i) {
            std::cout << validMoves[i] << " ";
        }
        std::cout << "\n";
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Queen &queenpiece) {
        if (queenpiece.color == 'b') {
            return os << "♕"; //black
        }
        return os << "♛"; //white
    }
    
private:
    std::vector<std::string> validMoves;
};

class Knight : public pieces {
public:
    Knight(char color_in)
    : pieces(color_in) {}
    
    void listMoves (std::string number, std::string letter) {
        validMoves.clear();
        knight_helper_up(number, letter);
        knight_helper_right(number, letter);
        knight_helper_left(number, letter);
        knight_helper_down(number, letter);
    }
    
    void knight_helper_up(std::string number, std::string letter) {
        const std::string *numptr = rowPtr(number, letter);  //height
        const std::string *letptr = colPtr(number, letter);  //side-side
        ++numptr;
        if (numptr != ROWS + 8) {
            ++numptr;
            ++letptr;
            if ((numptr != ROWS + 8) && (letptr != COLS + 8)) {
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
            --letptr;
            if ((numptr != ROWS + 8) && (letptr != COLS)) {
                --letptr;
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
        }
    }
    
    void knight_helper_right(std::string number, std::string letter) {
        const std::string *numptr = rowPtr(number, letter);  //height
        const std::string *letptr = colPtr(number, letter);  //side-side
        ++letptr;
        if (letptr != COLS + 8) {
            ++numptr;
            ++letptr;
            if ((numptr != ROWS + 8) && (letptr != COLS + 8)) {
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
            --numptr;
            if ((numptr != ROWS) && (letptr != COLS + 8)) {
                --numptr;
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
        }
    }
    
    void knight_helper_left(std::string number, std::string letter) {
        const std::string *numptr = rowPtr(number, letter);  //height
        const std::string *letptr = colPtr(number, letter);  //side-side
        
        if (letptr != COLS) {
            --letptr;
            ++numptr;
            --letptr; //new
            if ((numptr != ROWS + 8) && (letptr != COLS - 1)) {
                //--letptr;
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
            ++letptr;
            --numptr;
            if ((numptr != ROWS) && (letptr != COLS)) {
                --letptr;
                --numptr;
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
        }
    }
    
    void knight_helper_down(std::string number, std::string letter) {
        const std::string *numptr = rowPtr(number, letter);  //height
        const std::string *letptr = colPtr(number, letter);  //side-side
        if (numptr != ROWS) {
            --numptr;
            ++letptr;
            --numptr; // new
            if ((numptr != ROWS - 1) && (letptr != COLS + 8)) {
                //--numptr;
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
            --letptr;
            if ((numptr != ROWS) && (letptr != COLS)) {
                --letptr;
                std::string move = "";
                move.append(*numptr);
                move.append(*letptr);
                validMoves.push_back(move);
            }
        }
    }
    
    void printMoves() {
        for (size_t i = 0; i < validMoves.size(); ++i) {
            std::cout << validMoves[i] << " ";
        }
        std::cout << "\n";
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Knight &knightpiece) {
        if (knightpiece.color == 'b') {
            return os << "♘"; //black
        }
        return os << "♞"; //white
    }
    
private:
    std::vector<std::string> validMoves;
};

class Pawn : public pieces {
public:
    Pawn(char color_in)
    : pieces(color_in), firstmove(true) {}
    
    void listMoves (std::string number, std::string letter) {
        validMoves.clear();
        if (firstmove) {
            std::string fmove = "";
            if (number == "2") {
                fmove.append("4");
            }
            else {
                fmove.append("5");
            }
            fmove.append(letter);
            validMoves.push_back(fmove);
            firstmove = false;
        }
        const std::string *letptr = colPtr(number, letter);
        const std::string *numptr = rowPtr(number, letter);
        std::string move = "";
        if (color == 'w') {
            ++numptr;
        }
        else {
            --numptr;
        }
        if (letptr != COLS) {
            --letptr;
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
            ++letptr;
            move = "";
        }
        move.append(*numptr);
        move.append(*letptr);
        validMoves.push_back(move);
        move = "";
        ++letptr;
        if (letptr != COLS + 8) {
            move.append(*numptr);
            move.append(*letptr);
            validMoves.push_back(move);
        }
    }
    
    void printMoves() {
        for (size_t i = 0; i < validMoves.size(); ++i) {
            std::cout << validMoves[i] << " ";
        }
        std::cout << "\n";
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Pawn &pawnpiece) {
        if (pawnpiece.color == 'b') {
            return os << "♙"; //black
        }
        return os << "♟︎"; //white
    }
    
private:
    std::vector<std::string> validMoves;
    bool firstmove;
};
    

//TESTING FUNCTION

void test() {
    
    std::cout << "TESTING ROOK \n\n";
    
    Rook *rook1 = new Rook('b');
    rook1->listMoves("3", "c");
    std::cout << "rook at position 3c: \n";
    rook1->printMoves();
    std::cout << "SHOULD NOT CONTAIN 3C \n";
    delete rook1;
    
    
    std::cout << "\n\nTESTING KING \n\n";
    
    King *king1 = new King('w');
    king1->listMoves("4", "c");
    std::cout << "king at position 4c: \n";
    king1->printMoves();
    std::cout << "SHOULD CONTAIN 4b and 4d \n";
    
    std::cout << "king at position 1c: \n";
    king1->listMoves("1", "c");
    king1->printMoves();
    std::cout << "SHOULD CONTAIN 2C \n";
    
    std::cout << "king at position 1c: \n";
    king1->listMoves("5", "h");
    king1->printMoves();
    
    std::cout << "king at position 1a: \n";
    king1->listMoves("1", "a");
    king1->printMoves();
    delete king1;
    
    
    std::cout << "\n\nTESTING BISHOP \n\n";

    Bishop *bishop1 = new Bishop('b');
    std::cout << "bishop at position 1a: \n";
    bishop1->listMoves("1", "a");
    bishop1->printMoves();
    
    std::cout << "bishop at position 8h: \n";
    bishop1->listMoves("8", "h");
    bishop1->printMoves();
    
    std::cout << "bishop at position 6h: \n";
    bishop1->listMoves("6", "h");
    bishop1->printMoves();
    
    std::cout << "bishop at position 4d: \n";
    bishop1->listMoves("4", "d");
    bishop1->printMoves();
    delete bishop1;
    
    
    std::cout << "\n\nTESTING QUEEN \n\n";
    
    Queen *queen1 = new Queen('w');
    std::cout << "queen at position 1a: \n";
    queen1->listMoves("1", "a");
    queen1->printMoves();
    
    std::cout << "queen at position 8h: \n";
    queen1->listMoves("8", "h");
    queen1->printMoves();
    
    std::cout << "queen at position 6h: \n";
    queen1->listMoves("6", "h");
    queen1->printMoves();
    
    std::cout << "queen at position 4d: \n";
    queen1->listMoves("4", "d");
    queen1->printMoves();
    delete queen1;

    //FIX KNIGHT
    std::cout << "\n\nTESTING KNIGHT \n\n";
    Knight *knight1 = new Knight('b');
    std::cout << "knight at position 1a: \n";
    knight1->listMoves("1", "a");
    knight1->printMoves();
    
    std::cout << "knight at position 8a: \n";
    knight1->listMoves("8", "a");
    knight1->printMoves();
    
    std::cout << "knight at position 8h: \n";
    knight1->listMoves("8", "h");
    knight1->printMoves();
    
    std::cout << "knight at position 1h: \n";
    knight1->listMoves("1", "h");
    knight1->printMoves();
    
    std::cout << "knight at position 6h: \n";
    knight1->listMoves("6", "h");
    knight1->printMoves();
    
    std::cout << "knight at position 4d: \n";
    knight1->listMoves("4", "d");
    knight1->printMoves();
    delete knight1;
    
    
    std::cout << "\n\nTESTING PAWN \n\n";
    Pawn *pawnW = new Pawn('w');
    Pawn *pawnB = new Pawn('b');
    
    std::cout << "pawnW at position 2a: \n";
    pawnW->listMoves("2", "a");
    pawnW->printMoves();
    
    std::cout << "pawnB at position 7c: \n";
    pawnB->listMoves("7", "c");
    pawnB->printMoves();
    
    std::cout << "pawnW at position 4a: \n";
    pawnW->listMoves("4", "a");
    pawnW->printMoves();
    
    std::cout << "pawnB at position 5c: \n";
    pawnB->listMoves("5", "c");
    pawnB->printMoves();
    
    delete pawnW;
    delete pawnB;
    
    //TESTING PRINTING
    std::cout << "\n\nTESTING PRINT \n\n";
    pieces *e1 = new pieces('e');
    //pieces e1('e');
    std::cout << *e1 << std::endl;
    
    delete e1;
    
    Rook *rw1 = new Rook('w');
    Knight *kw1 = new Knight('w');
    Bishop *bb1 = new Bishop('b');
    
    std::cout << *rw1 << " " << *kw1 << " " << *bb1 << std::endl;
    
    delete rw1;
    delete kw1;
    delete bb1;
}
