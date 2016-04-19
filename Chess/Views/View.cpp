//
//  View.cpp
//  Chess
//
//  Created by Adnan Zahid on 3/7/16.
//  Copyright © 2016 Adnan Zahid. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include "../Others/ViewDelegate.cpp"
#include "../Others/InputDelegate.cpp"
#include "../Others/Constants.cpp"
#include "../Models/Board.cpp"
#include "../Models/Pieces/Piece.cpp"

class View {
    
private:
    ViewDelegate *viewDelegate;
    InputDelegate *inputDelegate;
    
public:
    View(ViewDelegate *viewDelegate, InputDelegate *inputDelegate, Board *board) {
        this->viewDelegate = viewDelegate;
        this->inputDelegate = inputDelegate;
        this->board = board;
    }
    
    void display() {
//        this->displayHelp();
        this->displayPieceBoard();
//        this->displayMobility();
//        this->displayValue();
//        this->displayOrder();
        this->displayEvaluationValue();
//        this->displayPresenceBoards();
    }
    
    void takeInput() {
        while(1) {
            
            std::string inputByUser;
            getline(std::cin, inputByUser);
            
            if (inputByUser.substr(0, 4) == "exit" || inputByUser.substr(0, 5) == "abort" || inputByUser.substr(0, 4) == "quit") {
                
                break;
                
            } else if (inputByUser.substr(0, 5) == "display") {
                
                this->displayPieceBoard();
                
            } else if (inputByUser.substr(0, 3) == "new") {
                
                this->viewDelegate->startNewGame();
                
            }
            
            if (inputByUser.substr(0, 1) >= "a" && inputByUser.substr(0, 1) <= "h" && inputByUser.substr(1, 1) >= "1" && inputByUser.substr(1, 1) <= "8" && inputByUser.substr(2, 1) >= "a" && inputByUser.substr(2, 1) <= "h" && inputByUser.substr(3, 1) >= "1" && inputByUser.substr(3, 1) <= "8") {
                
                Position from;
                Position to;
                
                from.file = inputByUser[0];
                from.rank = inputByUser[1];
                
                to.file = inputByUser[2];
                to.rank = inputByUser[3];
                
                this->inputDelegate->inputTaken(from, to);
            } else {
                this->displayError(DESTINATION_OUT_OF_BOARD_STRING);
            }
        }
    }
    
    void displayError(std::string message) {
        
        std::cout << message << std::endl;
    }
    
private:
    Board *board;
    
    void displayHelp() {
        std::cout << "Please enter your moves in 4 letter algebraic" << std::endl << "e2e4 in lower case only" << std::endl;
        std::cout << "Commands: exit = quit, abort = quit, display = displays the board," << std::endl << "new = new game" << std::endl << std::endl;
    }
    
    void displayPresenceBoards() {
//        this->displayPresenceBoardForColor(this->board->whitePresenceArray, 'W');
//        this->displayPresenceBoardForColor(this->board->whitePawnPresenceArray, 'P');
//        this->displayPresenceBoardForColor(this->board->whiteKnightPresenceArray, 'N');
//        this->displayPresenceBoardForColor(this->board->whiteBishopPresenceArray, 'B');
//        this->displayPresenceBoardForColor(this->board->whiteRookPresenceArray, 'R');
//        this->displayPresenceBoardForColor(this->board->whiteQueenPresenceArray, 'Q');
//        this->displayPresenceBoardForColor(this->board->whiteKingPresenceArray, 'K');
        
        this->displayPresenceBoardForColor(this->board->whiteMovesArray, 'M');
//        this->displayPresenceBoardForColor(this->board->whitePawnMovesArray, 'P');
//        this->displayPresenceBoardForColor(this->board->whiteKnightMovesArray, 'N');
//        this->displayPresenceBoardForColor(this->board->whiteBishopMovesArray, 'B');
//        this->displayPresenceBoardForColor(this->board->whiteRookMovesArray, 'R');
//        this->displayPresenceBoardForColor(this->board->whiteQueenMovesArray, 'Q');
//        this->displayPresenceBoardForColor(this->board->whiteKingMovesArray, 'K');
//
//        this->displayPresenceBoardForColor(this->board->blackPresenceArray, 'B');
//        this->displayPresenceBoardForColor(this->board->blackPawnPresenceArray, 'P');
//        this->displayPresenceBoardForColor(this->board->blackKnightPresenceArray, 'N');
//        this->displayPresenceBoardForColor(this->board->blackBishopPresenceArray, 'B');
//        this->displayPresenceBoardForColor(this->board->blackRookPresenceArray, 'R');
//        this->displayPresenceBoardForColor(this->board->blackQueenPresenceArray, 'Q');
//        this->displayPresenceBoardForColor(this->board->blackKingPresenceArray, 'K');
        
        this->displayPresenceBoardForColor(this->board->blackMovesArray, 'm');
//        this->displayPresenceBoardForColor(this->board->blackPawnMovesArray, 'p');
//        this->displayPresenceBoardForColor(this->board->blackKnightMovesArray, 'n');
//        this->displayPresenceBoardForColor(this->board->blackBishopMovesArray, 'b');
//        this->displayPresenceBoardForColor(this->board->blackRookMovesArray, 'r');
//        this->displayPresenceBoardForColor(this->board->blackQueenMovesArray, 'q');
//        this->displayPresenceBoardForColor(this->board->blackKingMovesArray, 'k');
    }
    
    void displayPresenceBoardForColor(bool array[8][8], char colorCharacter) {
        for (int a = 7; a > -1; a--) {
            std::cout << std::endl;
            for (int b = 0; b < 8; b++) {
                char character = '-';
                bool value = array[a][b];
                if (value == true) {
                    character = colorCharacter;
                }
                std::cout << ' ' << character << ' ';
            }
        }
        std::cout << std::endl << std::endl;
    }
    
    void displayMobility() {
        for (int a = 7; a > -1; a--) {
            std::cout << std::endl;
            for (int b = 0; b < 8; b++) {
                int character = 0;
                
                Position position = this->board->indexToPosition(b, a);
                Piece *piece = this->board->getPieceOnPosition(position);
                if (piece != nullptr) {
                    character = piece->pieceStrategy->mobility;
                }
                std::cout << ' ' << character << ' ';
            }
        }
        std::cout << std::endl << std::endl;
    }
    
    void displayValue() {
        for (int a = 7; a > -1; a--) {
            std::cout << std::endl;
            for (int b = 0; b < 8; b++) {
                int character = 0;
                
                Position position = this->board->indexToPosition(b, a);
                Piece *piece = this->board->getPieceOnPosition(position);
                if (piece != nullptr) {
                    character = piece->value;
                }
                std::cout << ' ' << character << ' ';
            }
        }
        std::cout << std::endl << std::endl;
    }
    
    void displayOrder() {
        for (int a = 7; a > -1; a--) {
            std::cout << std::endl;
            for (int b = 0; b < 8; b++) {
                int character = 0;
                
                Position position = this->board->indexToPosition(b, a);
                Piece *piece = this->board->getPieceOnPosition(position);
                if (piece != nullptr) {
                    character = piece->order;
                }
                std::cout << ' ' << character << ' ';
            }
        }
        std::cout << std::endl << std::endl;
    }
    
    void displayEvaluationValue() {
        std::cout << this->board->evaluationValue << std::endl;
    }
    
    void displayPieceBoard() {
        for (int a = 7; a > -1; a--) {
            std::cout << std::endl;
            for (int b = 0; b < 8; b++) {
                char character = '-';
                Position position = this->board->indexToPosition(b, a);
                Piece *piece = this->board->getPieceOnPosition(position);
                if (piece != nullptr) {
                    if (piece->color == white) {
                        switch (piece->value) {
                            case PAWN:
                                character = 'P';
                                break;
                            case KNIGHT:
                                character = 'N';
                                break;
                            case BISHOP:
                                character = 'B';
                                break;
                            case ROOK:
                                character = 'R';
                                break;
                            case QUEEN:
                                character = 'Q';
                                break;
                            case KING:
                                character = 'K';
                                break;
                        }
                    } else {
                        switch (piece->value) {
                            case PAWN:
                                character = 'p';
                                break;
                            case KNIGHT:
                                character = 'n';
                                break;
                            case BISHOP:
                                character = 'b';
                                break;
                            case ROOK:
                                character = 'r';
                                break;
                            case QUEEN:
                                character = 'q';
                                break;
                            case KING:
                                character = 'k';
                                break;
                        }
                    }
                }
                std::cout << ' ' << character << ' ';
            }
        }
        std::cout << std::endl << std::endl;
    }
};