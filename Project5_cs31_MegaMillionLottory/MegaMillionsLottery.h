
#ifndef MEGAMILLIONSLOTTERY_H
#define MEGAMILLIONSLOTTERY_H
#include <iostream>
#include <string>
#include "MegaMillionsTicket.h"
using namespace std;


class MegaMillionsLottery{

public:

// class member functions
    enum WinningPossibility { MEGABALL, ONEPLUSMEGABALL, TWOPLUSMEGABALL, THREE, THREEPLUSMEGABALL, FOUR, FOURPLUSMEGABALL, FIVE, FIVEPLUSMEGABALL, NOTWINNING };

//--constructors
    MegaMillionsLottery();

    MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);
   

//--accessors

    int getBall1() const;
    int getBall2() const;
    int getBall3() const;
    int getBall4() const;
    int getBall5() const;
    int getMegaBall() const;  

    MegaMillionsTicket quickPick();
    WinningPossibility checkTicket( MegaMillionsTicket ticket );
    string whatHappened( MegaMillionsTicket ticket );


private:
    int mBall1;
    int mBall2;
    int mBall3;
    int mBall4;
    int mBall5;
    int mMegaBall;
    bool withinRange();
    bool duplicate();
    bool validTicket();
    bool ticketIsValid = true;

    int num_Ball1to5Match(MegaMillionsTicket ticket);
    bool megaBallMatch(MegaMillionsTicket ticket);

}; 

#endif