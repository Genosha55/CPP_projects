//--------------------------------------------------------------------
// IMPLEMENTATION FILE: MegaMillionsTicket.cpp
//
// Implements 1. class MegaMillionsTicket member functions
//
//--------------------------------------------------------------------
#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


//--constructors

MegaMillionsLottery::MegaMillionsLottery()
{
    RandomNumber mBall1to5(1,75,true,true);
    RandomNumber mMegaBall6(1,25,true,true);
    mBall1 = mBall1to5.random();
    mBall2 = mBall1;
    mBall3 = mBall1;
    mBall4 = mBall1;
    mBall5 = mBall1;
    while (mBall2 == mBall1)                    // randomly creating balls from 1-5 so that no duplicate balls are created
    {
        mBall2 = mBall1to5.random();
    }
    while (mBall3 == mBall1 || mBall3 == mBall2)
    {
        mBall3 = mBall1to5.random();
    }
    while (mBall4 == mBall1 || mBall4 == mBall2 || mBall4 == mBall3)
    {
        mBall4 = mBall1to5.random();
    }
    while (mBall5 == mBall1 || mBall5 == mBall2 || mBall5 == mBall3 || mBall5 == mBall4)
    {
        mBall5 = mBall1to5.random();
    }
        
    mMegaBall = mMegaBall6.random();    
}

MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball)
{
    mBall1 = ball1;
    mBall2 = ball2;
    mBall3 = ball3;
    mBall4 = ball4;
    mBall5 = ball5;
    mMegaBall = megaball;

    if (!validTicket())
    {
        std::logic_error e( "Bad ticket, please input again!" );
        throw( e );
    }
}


//--modifiers

bool MegaMillionsLottery::withinRange()
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

bool MegaMillionsLottery::duplicate()
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

bool MegaMillionsLottery::validTicket()
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

int MegaMillionsLottery::getBall1() const
{
    return mBall1;
}

int MegaMillionsLottery::getBall2() const
{
    return mBall2;
}

int MegaMillionsLottery::getBall3() const
{
    return mBall3;
}

int MegaMillionsLottery::getBall4() const
{
    return mBall4;
}

int MegaMillionsLottery::getBall5() const
{
    return mBall5;
}

int MegaMillionsLottery::getMegaBall() const
{
    return mMegaBall;
}


MegaMillionsTicket MegaMillionsLottery::quickPick()
{
    RandomNumber mBall1to5(1,75,true,true);
    RandomNumber mMegaBall6(1,25,true,true);
    mBall1 = mBall1to5.random();
    mBall2 = mBall1;
    mBall3 = mBall1;
    mBall4 = mBall1;
    mBall5 = mBall1;
    while (mBall2 == mBall1)
    {
        mBall2 = mBall1to5.random();
    }
    while (mBall3 == mBall1 || mBall3 == mBall2)
    {
        mBall3 = mBall1to5.random();
    }
    while (mBall4 == mBall1 || mBall4 == mBall2 || mBall4 == mBall3)
    {
        mBall4 = mBall1to5.random();
    }
    while (mBall5 == mBall1 || mBall5 == mBall2 || mBall5 == mBall3 || mBall5 == mBall4)
    {
        mBall5 = mBall1to5.random();
    }
        
    mMegaBall = mMegaBall6.random();
    
    MegaMillionsTicket randomTicket(mBall1, mBall2, mBall3, mBall4, mBall5, mMegaBall);
    return randomTicket;
}

MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket( MegaMillionsTicket ticket )
{
    MegaMillionsLottery::WinningPossibility result;
    
    if (num_Ball1to5Match(ticket)==5&&ticket.getMegaBall()==mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL;     // accessing the possiblity class as if the condition meets the spec
    else if (num_Ball1to5Match(ticket)==4&&ticket.getMegaBall()==mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL;
    else if (num_Ball1to5Match(ticket)==3&&ticket.getMegaBall()==mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL;
    else if (num_Ball1to5Match(ticket)==2&&ticket.getMegaBall()==mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL;
    else if (num_Ball1to5Match(ticket)==1&&ticket.getMegaBall()==mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL;
    else if (num_Ball1to5Match(ticket)==0&&ticket.getMegaBall()==mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::MEGABALL;
    else if (num_Ball1to5Match(ticket)==5&&ticket.getMegaBall()!=mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::FIVE;
    else if (num_Ball1to5Match(ticket)==4&&ticket.getMegaBall()!=mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::FOUR;
    else if (num_Ball1to5Match(ticket)==3&&ticket.getMegaBall()!=mMegaBall)
    result = MegaMillionsLottery::WinningPossibility::THREE;
    else
    result = MegaMillionsLottery::WinningPossibility::NOTWINNING;

    return result;   
}




string MegaMillionsLottery::whatHappened( MegaMillionsTicket ticket )
{
    string result="";

    switch (checkTicket(ticket))
    {
    case NOTWINNING:
        result = "You didn't win anything at all!";        
        break;
    case MEGABALL:
        result = "You matched the megaball!";        
        break;
    case ONEPLUSMEGABALL:
        result = "You matched 1 ball plus the megaball!";        
        break;
    case THREEPLUSMEGABALL:
        result = "You matched 2 balls plus the megaball!";        
        break;
    case THREE:
        result = "You matched 3 balls!";        
        break;
    case FOURPLUSMEGABALL:
        result = "You matched 4 balls plus the megaball!";        
        break;
    case FOUR:
        result = "You matched 4 balls!";        
        break;
    case FIVE:
        result = "You matched 5 balls!";        
        break;    
    case FIVEPLUSMEGABALL:
        result = "You matched 5 balls plus the megaball!";        
        break;
    default:
        break;
    }
    cout << result << endl;
    return result;
}

int MegaMillionsLottery::num_Ball1to5Match(MegaMillionsTicket ticket)
{
    int mTicket[] = { ticket.getBall1(), ticket.getBall2(), ticket.getBall3(), ticket.getBall4(), ticket.getBall5() };
    int lottery[] = {mBall1, mBall2, mBall3, mBall4, mBall5};
    int num_match = 0;

    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            if (mTicket[i]==lottery[j])
            {
                num_match++;
            }
        }       
    }
    return num_match;
}



