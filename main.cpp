
// headers
#include "pieces.cpp"
#include <stdio.h>
#include "string"
#include <iostream>

/*
// piece encoding
enum {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};

// ascii pieces
char ascii_pieces[] = ".PNBRQKpnbrqk";

// unicode pieces
char *unicode_pieces[] = {".", "♙", "♘", "♗", "♖", "♕", "♔", "♟︎", "♞", "♝", "♜", "♛", "♚"};

// chess board representation
int board[128] = {
    r, n, b, q, k, b, n, r,  o, o, o, o, o, o, o, o,
    p, p, p, p, p, p, p, p,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    P, P, P, P, P, P, P, P,  o, o, o, o, o, o, o, o,
    R, N, B, Q, K, B, N, R,  o, o, o, o, o, o, o, o
};

// print board
void print_board() {
    // print new line
    //printf("\n");
    std::cout << "\n";

    // loop over board ranks
    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 16; file++)
        {
            // init square
            int square = rank * 16 + file;
            
            // print ranks
            if (file == 0)
                //printf(" %d  ", 8 - rank);
                std::cout << " " << (8 - rank) << "  " ;
            
            // if square is on board
            if ((square & 0x88) == 0)
                //printf("%c ", ascii_pieces[board[square]]);
                //printf("%s ", unicode_pieces[board[square]]); //orig
                std::cout << unicode_pieces[board[square]] << " ";
        }
        
        // print new line every time new rank is encountered
        //printf("\n");
        std::cout << "\n";
    }
    
    // print files
    //printf("\n    a b c d e f g h\n\n");
    std::cout << "\n    a b c d e f g h\n\n";
}

//REQUIRES: rank and file
//EFFECTS: returns true with valid rank and file, otherwise returns false
//MODIFIES:
bool checkAccess (int rank, char file) {
    if ((rank > 0 && rank < 9) && (file == 'a' || file == 'b' || file == 'c' ||
                                   file == 'd' || file == 'e' || file == 'f' ||
                                   file == 'g' || file == 'h' )) {
        return true;
    }
    return false;
}

//REQUIRES: rank and file
//EFFECTS: returns index at given rank and file
//MODIFIES
int boardIndex (int rank, char file) {
    int fileNum = file - 65;
    int access = rank * 16 + fileNum;
    return access;
}

//REQUIRES:
//EFFECTS:
//MODIFIES: board, cout
void movePiece() {
  //  std::cout << 
}

*/

class Board {
public:
    Board() {
        //BLACK PIECES
        Rook *rb1 = new Rook('b');
        Knight *kb1 = new Knight('b');
        Bishop *bb1 = new Bishop('b');
        Queen *qb1 = new Queen('b');
        King *Kb1 = new King('b');
        Bishop *bb2 = new Bishop('b');
        Knight *kb2 = new Knight('b');
        Rook *rb2 = new Rook('b');
        Pawn *pb1 = new Pawn('b');
        Pawn *pb2 = new Pawn('b');
        Pawn *pb3 = new Pawn('b');
        Pawn *pb4 = new Pawn('b');
        Pawn *pb5 = new Pawn('b');
        Pawn *pb6 = new Pawn('b');
        Pawn *pb7 = new Pawn('b');
        Pawn *pb8 = new Pawn('b');
        
        //WHITE PIECES
        Rook *rw1 = new Rook('w');
        Knight *kw1 = new Knight('w');
        Bishop *bw1 = new Bishop('w');
        Queen *qw1 = new Queen('w');
        King *Kw1 = new King('w');
        Bishop *bw2 = new Bishop('w');
        Knight *kw2 = new Knight('w');
        Rook *rw2 = new Rook('w');
        Pawn *pw1 = new Pawn('w');
        Pawn *pw2 = new Pawn('w');
        Pawn *pw3 = new Pawn('w');
        Pawn *pw4 = new Pawn('w');
        Pawn *pw5 = new Pawn('w');
        Pawn *pw6 = new Pawn('w');
        Pawn *pw7 = new Pawn('w');
        Pawn *pw8 = new Pawn('w');
        
        //EMPTY PLACES
        pieces *e1 = new pieces('e');
        pieces *e2 = new pieces('e');
        pieces *e3 = new pieces('e');
        pieces *e4 = new pieces('e');
        pieces *e5 = new pieces('e');
        pieces *e6 = new pieces('e');
        pieces *e7 = new pieces('e');
        pieces *e8 = new pieces('e');
        pieces *e9 = new pieces('e');
        pieces *e10 = new pieces('e');
        pieces *e11 = new pieces('e');
        pieces *e12 = new pieces('e');
        pieces *e13 = new pieces('e');
        pieces *e14 = new pieces('e');
        pieces *e15 = new pieces('e');
        pieces *e16 = new pieces('e');
        pieces *e17 = new pieces('e');
        pieces *e18 = new pieces('e');
        pieces *e19 = new pieces('e');
        pieces *e20 = new pieces('e');
        pieces *e21 = new pieces('e');
        pieces *e22 = new pieces('e');
        pieces *e23 = new pieces('e');
        pieces *e24 = new pieces('e');
        pieces *e25 = new pieces('e');
        pieces *e26 = new pieces('e');
        pieces *e27 = new pieces('e');
        pieces *e28 = new pieces('e');
        pieces *e29 = new pieces('e');
        pieces *e30 = new pieces('e');
        pieces *e31 = new pieces('e');
        pieces *e32 = new pieces('e');
        
        std::vector<pieces> *whitePieces;
        
        
        
        pieces *board[64] = {
            rb1, kb1, bb1, qb1, Kb1, bb2, kb2, rb2,
            pb1, pb2, pb3, pb4, pb5, pb6, pb7, pb8,
            e1, e2, e3, e4, e5, e6, e7, e8,
            e9, e10, e11, e12, e13, e14, e15, e16,
            e17, e18, e19, e20, e21, e22, e23, e24,
            e25, e26, e27, e28, e29, e30, e31, e32,
            pw1, pw2, pw3, pw4, pw5, pw6, pw7, pw8,
            rw1, kw1, bw1, qw1, Kw1, bw2, kw2, rw2,
        };
    }
    
    //need to write a print board funtion
    
    //need to write playing chess function
/*
    So we go into the game and the board is printed
            we could get each plaers name
            we could say a basic instruction on how to insert and something like that
            kind of an intro of some sort
 
            player makes first play
            they say what they want to move
                they say what move they want to take
                enter that into the listmoves function for that piece,
                alter the valid moves, everything on the list that is incapable must be taken out. (function needed)
                print the options
                they move the piece (function needed to alter the board)
                they move to that location, the place that was empty should transfer to wear it was.
 
 but how is a checkmate found
        if every pieces new valid move surrounds the king?
        for now, what if i just ask them to say if its a checkmate
        omg im a genius
            what is the structure like
            while (checkmate == false) {
                ask for move from white
                they choose the piece they want to move
                (cin >> string >> string)
                location is entered into the listmoves function for the validmoves to be adjusted
                function from main filters the valid moves
                they say move
                move is entered into the listmoves function for the corr
            }
        
 while (checkmate == false) {
 
    ask for move from white
    
    function to alter list (the pieces valid moves)
        alters list checking based off board.
 
    show options
 
    take in option
 
    Here's what happens
        either they choose an empty square
            replace empty square with piece, and empty piece goes where piece was
        they choose a piece of opposite color
            replace opposite colored piece with the piece, and an empty piece goes where piece was
    
    
    
    
    
    
 
     they choose the piece they want to move
     (cin >> string >> string)
     location is entered into the listmoves function for the validmoves to be adjusted
     function from main filters the valid moves
     they say move
     move is entered into the listmoves function for the corr
 }
 
 
 
 
 */

private:
    pieces *board[64];
};


// main driver
int main(int argc, const char * argv[]) {
    int selection;
    std::cout << "Welcome to Chess Simulator \n";
    std::cout << "Select: \n";
    std::cout << "'1' for testing Pieces \n";
    std::cout << "'2' to run Simulator \n";
    std::cout << "Select: ";
    std::cin >> selection;
    if (selection == 1) {
        test();
    }
    else if (selection == 2) {
        
    }
    else {
        std::cout << "ERROR: Invalid Response \n";
        return 0;
    }
    //print_board();
    //std::cout << board[0];   prints 10
    return 0;
}

/*
 so you play the game
 there are two players and we start at the initial board
 
 a player selects a thing to move
    checks for validity
 they say where to move it
    if they say something they can't do this is labeled as invalid
    old place is labeled as empty
    new place is the piece
 
 Then the other player does this
 
 then this keeps going until there's a checkmate
 */
