//
//  EvaluationValueHandler.cpp
//  Chess
//
//  Created by Adnan Zahid on 4/2/16.
//  Copyright © 2016 Adnan Zahid. All rights reserved.
//

#include "Pieces/Piece.cpp"

class EvaluationValueHandler {

private:
    
    
public:
    int getEvaluationValue(std::vector<Piece *> piecesList) {
        
        int mobility = 0;
        int value = 0;
        
        for(std::vector<Piece *>::iterator iterator = piecesList.begin(); iterator != piecesList.end(); iterator++) {
            mobility += (*iterator)->pieceStrategy->mobility;
            value += (*iterator)->value;
        }
        
        return mobility + value;
    }
};