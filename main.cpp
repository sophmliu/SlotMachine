//
//  main.cpp
//  Project 6
//
//  Created by Sophia Liu on 8/11/20.
//  Copyright © 2020 Sophia Liu. All rights reserved.
//
#include <iostream>
#include <string>
#include <cassert>
    #include "Bank.h"
    #include "PayTable.h"
    #include "SlotMachine.h"
    #include "RandomNumber.h"

using namespace std;

int main()
{
       using namespace std;

       // test code
       int r(0);
       RandomNumber n(8,3);
       r = n.random();
       cout << r << endl;
       Bank b;
       b.balance( );       // returns 0
       b.canWager( 100 );  // returns false because there aren't sufficient funds in this Bank
       b.deposit( 50 );
       b.balance( );       // returns 50
       b.canWager( 100 );  // returns false because there aren't sufficient funds in this Bank
       b.deposit( 50 );
      // b.canWager( 100 );  // returns true because there are sufficient funds
      // b.setWager( 100 );  // $100 has now been bet
      // b.getWager( );      // returns 100
      // b.balance( );       // returns 100 because the bet wager has not yet been won or lost
      // b.win( 100 );       // the wager was won
     //  cout << b.cashOut( ) << endl;       // returns 200
       assert (b.balance() == 100);
    
       PayTable p( 'A', 'A', 'A' );
       PayTable::Multiplier m = p.calculateMultiplier( );  // 3 Aces is a 10-1 winner
       assert( m == PayTable::Multiplier::TENTIME );
       SlotMachine s( "AKQJ987" );   // cheating...
       b.setWager( 100 );
       assert (b.balance() == 100);
       s.play( b, 'A', 'A', 'A' );
       
       assert( b.balance() == 1100 ); // 3 Aces is 10-1 winner and a round of play adjusts the bank */
        
       s.play(b);

       cout << "all tests passed!" << endl;
       return 0;

    }
