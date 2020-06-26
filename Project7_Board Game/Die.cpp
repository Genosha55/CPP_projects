//
//  Die.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Die.h"
#include <random>

namespace cs31
{
    
    Die::Die( int sides ) : mSides( sides ), mValue( 1 )
    {

    }
    
    // randomly toss this die
    void Die::roll()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_int_distribution<> dist(1, mSides);
        mValue = dist(e2);
    }
    
    // acquire the value that was just tossed, whether randomly or cheated
    int  Die::getValue( ) const
    {
        return( mValue );
    }
  
    // force a value into the die by cheating...
    void Die::setValue( int amount )
    {
        // cheating...
        if (amount <= mSides && amount >= 1)
        {
            mValue = amount;
        }
    }

}
