//
//  Controller.cpp
//  Chess
//
//  Created by Adnan Zahid on 3/7/16.
//  Copyright © 2016 Adnan Zahid. All rights reserved.
//

#include "../Models/GameLogic.cpp"
#include "../Views/View.cpp"
#include "../Others/ViewDelegate.cpp"
#include "../Others/InputDelegate.cpp"

#include <string>

class Controller : ErrorDelegate, ViewDelegate, InputDelegate {
    
private:
    GameLogic *gameLogic;
    View *view;
    
public:
    Controller() {
        
        this->gameLogic = new GameLogic(this, this);
        Board *board = gameLogic->getBoard();
        
        this->view = new View(this, this, board);
        
        this->view->display();
        this->takeInputOrGenerateMove();
    }
    
    void takeInputOrGenerateMove() {
        if (this->gameLogic->shouldTakeInputFromHuman() == true) {
            this->view->takeInput();
        } else {
            this->gameLogic->askAIToGenerateMove();
        }
    }
    
    void inputTaken(Position from, Position to) {
        
        if (this->gameLogic->movePiece(from, to) == true) {
            
            this->view->display();
            this->takeInputOrGenerateMove();
        }
    }
    
    void error(std::string message) {
        this->view->displayError(message);
    }
    
    void startNewGame() {
        
    }
};