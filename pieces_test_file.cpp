//
//  pieces_test_file.cpp
//  chess1_game
//
//  Created by Nayan Paavalar on 12/24/22.
//

#include <stdio.h>
#include "pieces.cpp"


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
