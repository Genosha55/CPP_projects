#include <iostream>
#include <string>
#include <cassert>
using namespace std;
#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
bool ticketsAreNotTheSame(MegaMillionsTicket t1, MegaMillionsTicket t2)
{
	return ( !( t1.getBall1() == t2.getBall1() &&
		 t1.getBall2() == t2.getBall2() &&
		 t1.getBall3() == t2.getBall3() &&
		 t1.getBall4() == t2.getBall4() &&
		 t1.getBall5() == t2.getBall5() &&
                 t1.getMegaBall() == t2.getMegaBall() ) );
}

void testone(int n)
{
    MegaMillionsLottery lottery( 23, 42, 17, 69, 1, 4 );

    switch (n)
    {
        case  1:
                assert( MegaMillionsTicket( 23, 42, 17, 69, 1, 4 ).getBall1() == 23);
                break;

        case  2:
                assert( MegaMillionsTicket( 23, 42, 17, 69, 1, 4 ).getBall2() == 42);
                break;

        case  3:
                assert( MegaMillionsTicket( 23, 42, 17, 69, 1, 4 ).getBall3() == 17);
                break;

        case  4:
                assert( MegaMillionsTicket( 23, 42, 17, 69, 1, 4 ).getBall4() == 69);
                break;

        case  5:
                assert( MegaMillionsTicket( 23, 42, 17, 69, 1, 4 ).getBall5() == 1);
                break;

        case  6:
                assert( MegaMillionsTicket( 23, 42, 17, 69, 1, 4 ).getMegaBall() == 4);
                break;

        case  7:

                assert( lottery.getBall1() == 23);
                break;

        case  8:
                assert( lottery.getBall2() == 42);
                break;

        case  9:
                assert( lottery.getBall3() == 17);
                break;

        case 10:
                assert( lottery.getBall4() == 69);
                break;

        case 11:
                assert( lottery.getBall5() == 1);
                break;

        case 12:
                assert( lottery.getMegaBall() == 4);
                break;
        case 13:
        {
            MegaMillionsTicket t(23, 42, 17, 69, 1, 4);
            assert(lottery.checkTicket(t) ==
                MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
            assert(lottery.whatHappened(t) == "You matched 5 balls plus the megaball!");
        }
                break;

        case 14:
                {
                MegaMillionsTicket t( 1, 69, 17, 23, 42, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 5 balls plus the megaball!" );
                }
                break;

        case 15:
                {
                MegaMillionsTicket t( 23, 42, 17, 69, 1, 12 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::FIVE);
                assert( lottery.whatHappened( t ) == "You matched 5 balls!" );
                }
                break;

        case 16:
                {
                MegaMillionsTicket t( 23, 9, 17, 69, 42, 12 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::FOUR);
                assert( lottery.whatHappened( t ) == "You matched 4 balls!" );
                }
                break;

        case 17:
                {
                MegaMillionsTicket t( 23, 42, 17, 69, 9, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 4 balls plus the megaball!" );
                }
                break;

        case 18:
                {
                MegaMillionsTicket t( 23, 42, 17, 8, 9, 12 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::THREE);
                assert( lottery.whatHappened( t ) == "You matched 3 balls!" );
                }
                break;

        case 19:
                {
                MegaMillionsTicket t( 9, 8, 17, 42, 23, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 3 balls plus the megaball!" );
                }
                break;

        case 20:
                {
                MegaMillionsTicket t( 7, 8, 69, 9, 42, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 2 balls plus the megaball!" );
                }
                break;

        case 21:
                {
                MegaMillionsTicket t( 6, 8, 23, 7, 9, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 1 ball plus the megaball!" );
                }
                break;

        case 22:
                {
                MegaMillionsTicket t( 8, 5, 9, 7, 6, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::MEGABALL);
                assert( lottery.whatHappened( t ) == "You matched the megaball!" );
                }
                break;

        case 23:
                {
                MegaMillionsTicket t( 5, 7, 8, 6, 9, 16 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::NOTWINNING);
                assert( lottery.whatHappened( t ) == "You didn't win anything at all!" );
                }
                break;

        case 24:
                // verify quickPick does not just return the same ball values
                // every time.  Odds that it would by chance are minuscule.
                assert( ticketsAreNotTheSame( lottery.quickPick(), lottery.quickPick() ) );
                break;

        case 25:
               // verify quickPick does not just return a precomputed answer
               // with ball values in range.
               assert( ticketsAreNotTheSame( lottery.quickPick(), lottery.quickPick() ) );
               {
                  const int NTRIALS = 6900;
                  for (int i = 0; i < NTRIALS; i++)
                  {
                      MegaMillionsTicket q = lottery.quickPick();
                      assert( q.getBall1() >= 1  &&  q.getBall1() <= 75 );
                      assert( q.getBall2() >= 1  &&  q.getBall2() <= 75 );
                      assert( q.getBall3() >= 1  &&  q.getBall3() <= 75 );
                      assert( q.getBall4() >= 1  &&  q.getBall4() <= 75 );
                      assert( q.getBall5() >= 1  &&  q.getBall5() <= 75 );
                      assert(q.getMegaBall() >= 1  &&  q.getMegaBall() <= 25);
                  }
               }
               break;
        case 26:
               {
               // verify uniform random distribution of ball picks
               int ballCounts[1+5][1+75] = { };
               int megaballCounts[1+25] = { };
               const int NTRIALS = 6900;
               for (int i = 0; i < NTRIALS; i++)
               {
                    MegaMillionsTicket q = lottery.quickPick();
                    int balls[1+5] = { 0, q.getBall1(), q.getBall2(),
                        q.getBall3(), q.getBall4(), q.getBall5() };
                    int megaball = q.getMegaBall();
                    for (int k = 1; k <= 5; k++)
                    {
                       if (balls[k] >= 1  &&  balls[k] <= 75)
                           ballCounts[k][balls[k]]++;
                    }
                    if (megaball >= 1  &&  megaball <= 25)
                        megaballCounts[megaball]++;
               }
               int expectedBallCount = NTRIALS / 75;
               int expectedMegaballCount = NTRIALS / 25;
               for (int k = 1; k <= 5; k++)
               {
                   for (int b = 1; b <= 75; b++)
                      assert(ballCounts[k][b] > 0.25 * expectedBallCount &&
                           ballCounts[k][b] < 1.75 * expectedBallCount );
               }
               for (int b = 1; b <= 25; b++)
                   assert(megaballCounts[b] > 0.25 * expectedMegaballCount &&
                       megaballCounts[b] < 1.75 * expectedMegaballCount );
            
               }
               break;

        case 27:
               {
               // verify quickPick does not just return a precomputed answer
               // with distinct balls.
               assert( ticketsAreNotTheSame( lottery.quickPick(), lottery.quickPick() ) );
               for (int i = 0; i < 100; i++)
               {
                   MegaMillionsTicket q = lottery.quickPick();
                   // all the ball numbers need to be different...
                   assert( q.getBall1() != q.getBall2() &&
                       q.getBall1() != q.getBall3() &&
                       q.getBall1() != q.getBall4() &&
                       q.getBall1() != q.getBall5() &&
                       q.getBall2() != q.getBall3() &&
                       q.getBall2() != q.getBall4() &&
                       q.getBall2() != q.getBall5() &&
                       q.getBall3() != q.getBall4() &&
                       q.getBall3() != q.getBall5() &&
                       q.getBall4() != q.getBall5() );
               }
               }
               break;

        default:
                cout << "Bad argument" ;
                break;
            
            
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed!" << endl;
    return( 0 );
}

