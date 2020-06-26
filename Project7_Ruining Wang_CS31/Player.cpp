//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include "Board.h"
#include "Die.h"
#include <iostream>
#include <cassert>

namespace cs31
{
    // set up three six sided dies
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mDie3( 6 ), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {
        
    }       // default constructor    
    
    void Player::roll( Die d1, Die d2, Die d3 )
    {
        // assign each of the arguments to the Player's member variables to enable cheating...
        mDie1 = d1;
        mDie2 = d2;
        mDie3 = d3;

        value1 = d1.getValue();
        value2 = d2.getValue();
        value3 = d3.getValue();
        sum_12 = value1 + value2;
        sum_23 = value2 + value3;
        sum_13 = value1 + value3;
        sum_all = value1 + value2 + value3;

        
        updateHasRolled(value1,value2,value3,sum_12,sum_23,sum_13,sum_all);        
    }
    
    void Player::roll( )
    {
        // randomly roll each of the three Die member variables
        mDie1.roll();
        mDie2.roll();
        mDie3.roll();

        value1 = mDie1.getValue();
        value2 = mDie2.getValue();
        value3 = mDie3.getValue();
        sum_12 = value1 + value2;
        sum_23 = value2 + value3;
        sum_13 = value1 + value3;
        sum_all = value1 + value2 + value3;

        updateHasRolled(value1,value2,value3,sum_12,sum_23,sum_13,sum_all);        
    }

    void Player::updateHasRolled(int value1,int value2,int value3,int sum_12,int sum_23,int sum_13,int sum_all)
    {
        hasRolled1 = (hasRolled1)||(value1==1||value2==1||value3==1||sum_12==1||sum_23==1||sum_13==1||sum_all==1);
        hasRolled2 = hasRolled2||((hasRolled1)&&(value1==2||value2==2||value3==2||sum_12==2||sum_23==2||sum_13==2||sum_all==2));
        hasRolled3 = hasRolled3||((hasRolled2)&&(value1==3||value2==3||value3==3||sum_12==3||sum_23==3||sum_13==3||sum_all==3));
        hasRolled4 = hasRolled4||((hasRolled3)&&(value1==4||value2==4||value3==4||sum_12==4||sum_23==4||sum_13==4||sum_all==4));
        hasRolled5 = hasRolled5||((hasRolled4)&&(value1==5||value2==5||value3==5||sum_12==5||sum_23==5||sum_13==5||sum_all==5));
        hasRolled6 = hasRolled6||((hasRolled5)&&(value1==6||value2==6||value3==6||sum_12==6||sum_23==6||sum_13==6||sum_all==6));
        hasRolled7 = hasRolled7||((hasRolled6)&&(value1==7||value2==7||value3==7||sum_12==7||sum_23==7||sum_13==7||sum_all==7));
        hasRolled8 = hasRolled8||((hasRolled7)&&(value1==8||value2==8||value3==8||sum_12==8||sum_23==8||sum_13==8||sum_all==8));
        hasRolled9 = hasRolled9||((hasRolled8)&&(value1==9||value2==9||value3==9||sum_12==9||sum_23==9||sum_13==9||sum_all==9));
        hasRolled10 = hasRolled10||((hasRolled9)&&(value1==10||value2==10||value3==10||sum_12==10||sum_23==10||sum_13==10||sum_all==10));
        hasRolled11 = hasRolled11||((hasRolled10)&&(value1==11||value2==11||value3==11||sum_12==11||sum_23==11||sum_13==11||sum_all==11));
        hasRolled12 = hasRolled12||((hasRolled11)&&(value1==12||value2==12||value3==12||sum_12==12||sum_23==12||sum_13==12||sum_all==12));
    }       // updating the values of what has been rolled. Has to be continuous, meaning the previous has to be true for the next to be rolled
   
    int  Player::whatSpotIsNeededNext()
    {        
        int result = 1;
        bool arr[12] = {hasRolled1,hasRolled2,hasRolled3,hasRolled4,hasRolled5,hasRolled6,hasRolled7,hasRolled8,hasRolled9,hasRolled10,hasRolled11,hasRolled12};

        for (int i=0;i<11;i++)      // using an array to copy the values of the hasRolledX, and a for loop to find the first index of true/false change 
        {
            if (arr[i]==true&&arr[i+1]==false)
            result = i+2;
        }       
        return( result );
    }    
    
    void Player::rolled( int spot )     // for testing, using a switch statement to determine if the rolled is continuous
    {        
        switch (spot)
        {
            case 1:
                hasRolled1 = true;
                break;
            case 2:
                if (hasRolled1==true)
                hasRolled2 = true;
                break;
            case 3:
                if (hasRolled2 == true)
                hasRolled3 = true;
                break;
            case 4:
                if (hasRolled3 == true)
                hasRolled4 = true;
                break;
            case 5:
                if (hasRolled4 == true)
                hasRolled5 = true;
                break;
            case 6:
                if (hasRolled5 == true)
                hasRolled6 = true;
                break;
            case 7:
                if (hasRolled6 == true)
                hasRolled7 = true;
                break;
            case 8:
                if (hasRolled7 == true)
                hasRolled8 = true;
                break;
            case 9:
                if (hasRolled8 == true)
                hasRolled9 = true;
                break;
            case 10:
                if (hasRolled9 == true)
                hasRolled10 = true;
                break;
            case 11:
                if (hasRolled10 == true)
                hasRolled11 = true;
                break;
            case 12:
                if (hasRolled11 == true)
                hasRolled12 = true;
                break;
            default:
                break;
            }             
    }

   
    // trivial getter operation
    Die Player::getDie1() const
    {
        return( mDie1 );
    }
    
    // trivial getter operation
    Die Player::getDie2( ) const
    {
        return( mDie2 );
    }
    
    // trivial getter operation
    Die Player::getDie3( ) const
    {
        return( mDie3 );
    }
    
    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return( hasRolled1 );
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return( hasRolled2 );
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return( hasRolled3 );
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return( hasRolled4 );
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return( hasRolled5 );
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return( hasRolled6 );
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return( hasRolled7 );
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return( hasRolled8 );
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return( hasRolled9 );
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return( hasRolled10 );
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return( hasRolled11 );
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return( hasRolled12 );
    }
    
    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    // unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        s += " Die3: ";
        s += std::to_string( mDie3.getValue() );
        s += "\n";
        return( s );
    }      
    

}
