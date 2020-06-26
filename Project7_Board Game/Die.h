//
//  Die.h
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Die_h
#define Die_h

namespace cs31
{
    
/*
 This class supports a random die of some number of sides.
 This class is completely finished.  There is no work for CS 31 students here.
 */
class Die
{
public:
    Die( int sides = 6 ); // by default, a six sided die
    // randomly toss the die
    void roll();
    // return the value that was previously tossed, whether randomly or cheated
    int  getValue( ) const;
    // cheat by setting a desired value for the die
    void setValue( int amount );
private:
    int  mSides;  // the number of side for this die
    int  mValue;  // the value that was just tossed, whether randomly or cheated
};

    
}
#endif /* Die_h */
