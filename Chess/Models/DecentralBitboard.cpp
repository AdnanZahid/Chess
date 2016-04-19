//
//  DecentralBitboard.cpp
//  Chess
//
//  Created by Adnan Zahid on 3/18/16.
//  Copyright © 2016 Adnan Zahid. All rights reserved.
//

#pragma once

#include "Bitboard.cpp"

class DecentralBitboard : public Bitboard {
    
public:
    void setPosition(Position position) {
        this->position = this->computeBitboardFromPosition(position);
    }
    
    void setMoves(std::vector<Position> moves) {
        this->moves = 0;
        for(std::vector<Position>::iterator iterator = moves.begin(); iterator != moves.end(); iterator++) {
            this->moves |= this->computeBitboardFromPosition(*iterator);
        }
    }
};