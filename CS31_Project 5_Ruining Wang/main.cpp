#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include "MegaMillionsTicket.h"
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"
using namespace std;



int main()
{


            // test code
           MegaMillionsTicket ticket( 1, 2, 3, 4, 5, 6 );
           assert( ticket.getBall1() == 1);
           assert( ticket.getBall2() == 2);
           assert( ticket.getBall3() == 3); 
           assert( ticket.getBall4() == 4);
           assert( ticket.getBall5() == 5);
           assert( ticket.getMegaBall() == 6);
           MegaMillionsLottery lottery( 1, 2, 3, 4, 5, 6 );
           assert( lottery.getBall1() == 1);
           assert( lottery.getBall2() == 2); 
           assert( lottery.getBall3() == 3);
           assert( lottery.getBall4() == 4);
           assert( lottery.getBall5() == 5);
           assert( lottery.getMegaBall() == 6);
           assert( lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
           assert( lottery.whatHappened( ticket ) == "You matched 5 balls plus the megaball!" );
           ticket = MegaMillionsTicket( 1, 2, 3, 4, 5, 12 );
           assert( lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
           assert( lottery.whatHappened( ticket ) == "You matched 5 balls!" );
           ticket = MegaMillionsTicket( 1, 2, 3, 4, 15, 12 );



           MegaMillionsTicket quickPickTicket( 1, 2, 3, 4, 5, 6);
           for (int i = 0; i < 20; i++)
           { 
               quickPickTicket = lottery.quickPick();
               // all the ball numbers need to be different...
               assert( quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
                       quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
                       quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
                       quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
                       quickPickTicket.getBall4() != quickPickTicket.getBall5());
          }

	  RandomNumber r( 1, 75 );  /// balls 1-5
	  cout << r.random() << endl;
	  cout << r.random() << endl;
	  cout << r.random() << endl;
	  cout << r.random() << endl;
	  cout << r.random() << endl;
	  cout << r.random() << endl;
	  cout << r.random() << endl;
	  cout << r.random() << endl;


          cout << "all tests passed!" << endl;



        
    return (0);
}