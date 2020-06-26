//
//  Centennial.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Centennial.h"
#include "Player.h"
#include "Board.h"
#include "Die.h"
#include <iostream>
#include <string>

namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn( true )
    {
        
    }
    
    // prints the state of the game play with each round of play
    std::string Centennial::display( std::string msg )
    {
        using namespace std;
        std::string s( "" );
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return( s );
    }       
    
    // randomly play a human turn in the game
    void Centennial::humanPlay( )
    {
        // mark that it is the human's turn
        // let the human player randomly roll
        // look at what was rolled and update the board spots accordingly

        isHumanTurn = true;                
        mHuman.roll();
        if (!isGameOver())      // if game is not over, updating the position on the board by Next-1
        {
            mBoard.setHumanSpot(mHuman.whatSpotIsNeededNext()-1);
        }       
        else        // if game is over, set the position of player to be 12, telling Board game is over and who is the winner
        {
            mBoard.setHumanSpot(12);
            mBoard.setGameOver(true);
            mBoard.markHumanAsWinner();
        }       
        mBoard.display();
    }
    
    // force a certain roll in the human's turn of the game by cheating...
    void Centennial::humanPlay( Die d1, Die d2, Die d3 )    // same logic with the humanPlay (default)
    {
        // mark that it is the human's turn
        // force the human player to cheat
        // look at what was rolled and update the board spots accordingly    
        
        isHumanTurn = true;
        mHuman.roll(d1,d2,d3);
        if (!isGameOver())
        {
            mBoard.setHumanSpot(mHuman.whatSpotIsNeededNext()-1);
        }       
        else
        {
            mBoard.setHumanSpot(12);
            mBoard.setGameOver(true);
            mBoard.markHumanAsWinner();
        }        
        mBoard.display();
    }

    // randomly play a computer turn in the game
    void Centennial::computerPlay( )    // same logic with the humanPlay
    {
        // mark that it is no longer the human's turn
        // let the computer player randomly roll
        // look at what was rolled and update the board spots accordingly
        
        isHumanTurn = false;
        mComputer.roll();
        if (!isGameOver())
        {
            mBoard.setComputerSpot(mComputer.whatSpotIsNeededNext()-1);
        }       
        else
        {
            mBoard.setComputerSpot(12);
            mBoard.setGameOver(true);
            mBoard.markComputerAsWinner();
        }         
        mBoard.display();
    }
    
    // force a certain roll in the computer's turn of the game by cheating...
    void Centennial::computerPlay( Die d1, Die d2, Die d3 )     // same logic with the humanPlay
    {
        // mark that it is no longer the human's turn
        // force the computer player to cheat
        // look at what was rolled and update the board spots accordingly
        
        isHumanTurn = false;
        mComputer.roll(d1,d2,d3);
        if (!isGameOver())
        {
            mBoard.setComputerSpot(mComputer.whatSpotIsNeededNext()-1);
        }       
        else
        {
            mBoard.setComputerSpot(12);
            mBoard.setGameOver(true);
            mBoard.markComputerAsWinner();
        }        
        mBoard.display();
    }
    
    // determine the current state of the game
    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;

        if (mHuman.hasRolledTwelve())
            result = GAMEOUTCOME::HUMANWONGAME;        
        else if(mComputer.hasRolledTwelve())
            result = GAMEOUTCOME::COMPUTERWONGAME;

        return( result );
    }
    
    // determine if the game has ended
    // HINT: call determineGameOutcome( )
    bool Centennial::isGameOver()
    {        
        bool result = false;
        switch (determineGameOutcome())     // using a switch statement with two conditions of game has finished or not
        {
            case HUMANWONGAME:
            case COMPUTERWONGAME:
                result = true;
                break;
            default:
                break;     
        }
        return( result );
    }

    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return( mHuman );
    }
    
    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return( mComputer );
    }
    
    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return( mBoard );
    }
}
