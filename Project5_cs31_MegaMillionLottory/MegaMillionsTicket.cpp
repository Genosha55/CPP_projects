//--------------------------------------------------------------------
// IMPLEMENTATION FILE: MegaMillionsTicket.cpp
//
// Implements 1. class MegaMillionsTicket member functions
//
//--------------------------------------------------------------------
#include "MegaMillionsTicket.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


//--constructors

MegaMillionsTicket::MegaMillionsTicket()
{
    mBall1 = 1;
    mBall2 = 2;
    mBall3 = 3;
    mBall4 = 4;
    mBall5 = 5;
    mMegaBall = 1;
}

MegaMillionsTicket::MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball)
{
    mBall1 = ball1;
    mBall2 = ball2;
    mBall3 = ball3;
    mBall4 = ball4;
    mBall5 = ball5;
    mMegaBall = megaball;

    if (!validTicket())             // tried to use an exception statement for catching bad ticket
    {
        std::logic_error e( "Bad ticket, please input again!" );
        throw( e );
    }
}


//--modifiers

bool MegaMillionsTicket::withinRange()          // function for checking if value of a ball is in range 
{
    if (mBall1<1||mBall1>75)
        ticketIsValid = false;
    else if (mBall2<1||mBall2>75)
        ticketIsValid = false;
    else if (mBall3<1||mBall3>75)
        ticketIsValid = false;
    else if (mBall4<1||mBall4>75)
        ticketIsValid = false; 
    else if (mBall5<1||mBall5>75)
        ticketIsValid = false;
    else if (mMegaBall<1||mMegaBall>25)
        ticketIsValid = false;  

    return (ticketIsValid);
}

bool MegaMillionsTicket::duplicate()        // function for checking if there is duplicate in ball 1-5
{
    bool result = false;
    int mBalls[] = { mBall1, mBall2, mBall3, mBall4, mBall5 };
    for (int i=0;i<5;i++)
    {
        for (int j=i+1;j<5;j++)
        {
            if ( mBalls[i]==mBalls[j] )
            {
                result = true;
            }
        }
    }
    return result;
}

bool MegaMillionsTicket::validTicket()      // return a bool for the check of ticket validity 
{
    if (withinRange()&&!duplicate())
    {
        return ticketIsValid;
    }
    else
    {
        ticketIsValid = false;
        return ticketIsValid;
    }    
}





//--accessors

int MegaMillionsTicket::getBall1() const
{
    return mBall1;
}

int MegaMillionsTicket::getBall2() const
{
    return mBall2;
}

int MegaMillionsTicket::getBall3() const
{
    return mBall3;
}

int MegaMillionsTicket::getBall4() const
{
    return mBall4;
}

int MegaMillionsTicket::getBall5() const
{
    return mBall5;
}

int MegaMillionsTicket::getMegaBall() const
{
    return mMegaBall;
}

