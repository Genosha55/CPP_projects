//
//  Board.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mHumanSpot(0), mComputerSpot(0), mGameOver(false), mHumanWon(false)
    {

    }    // default constructor
  
    void Board::setGameOver( bool value )   // telling board if game is over by set function
    {
        mGameOver = value;
    }
    
    // trivial getter operation
    bool Board::isGameOver( ) const
    {       
        return( mGameOver );
    }
   
    void Board::markHumanAsWinner()
    {
        mHumanWon = true;
    }    
  
    void Board::markComputerAsWinner()  // marking player to be winner by mark function
    {
        mHumanWon = false;
        mGameOver = true;
    }
    
    // trivial getter operation
    bool Board::isHumanWinner() const
    {        
        return( mHumanWon );
    }
    
    // remember how far along the board the human player is
    void Board::setHumanSpot( int spot )
    {
        // the only legal spots are values between 0 and 12
        if (spot >= 0 && spot <= 12)
        {
            mHumanSpot = spot;
        }
    }
    
    // trivial getter operation
    int  Board::getHumanSpot()
    {
        return( mHumanSpot );
    }
    
    // trivial getter operation
    int  Board::getComputerSpot()
    {
        return( mComputerSpot );
    }
    
    // remember how far along the board the computer player is
    void Board::setComputerSpot( int spot )
    {
        // the only legal spots are values between 0 and 12
        if (spot >= 0 && spot <= 12)
        {
            mComputerSpot = spot;
        }
    }
    
    // print the state of the board
    // called by Centennial to show the state of game play with each round of play
    std::string Board::display( ) const
    {
        std::string s = "\t--Centennial Game--\n";
        for (int i = 1; i <= 9 && i <= mHumanSpot; i++)
        {
            s += "  ";
        }
        for (int i = 10; i <= 12 && i <= mHumanSpot; i++)
        {
            s += "   ";
        }
        s += "H";
        if (mGameOver && mHumanWon)
        {
            s+= "  << WINNER!";
        }
        s += "\n";
        s += "  1 2 3 4 5 6 7 8 9 10 11 12\n";
        for (int i = 1; i <= 9 && i <= mComputerSpot; i++)
        {
            s += "  ";
        }
        for (int i = 10; i <= 12 && i <= mComputerSpot; i++)
        {
            s += "   ";
        }
        s += "C";
        if (mGameOver && !mHumanWon)
        {
            s += "  << WINNER!";
        }
        s += "\n";
        s += "\n";
        
        return( s );
    }    
}
