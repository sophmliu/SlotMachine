//
//  SlotMachine.cpp
//  Project 6
//
//  Created by Sophia Liu on 8/11/20.
//  Copyright © 2020 Sophia Liu. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include "SlotMachine.h"
#include "RandomNumber.h"
#include "Bank.h"
#include "PayTable.h"


SlotMachine::SlotMachine( std::string seq )
   : sequence( seq ), display( true )
{
// typically body of constructor is empty 
}

// TODO: force a specific set of wheels to be played and display the screen if requested to do so
void SlotMachine::play( Bank & bank, char w1, char w2, char w3 )  // cheating
{
    // TODO: update the wheel1, wheel2 and wheel3 members from the passed cheating values
    wheel1 = w1;
    wheel2 = w2;
    wheel3 = w3;
    
    // TODO: Draw the machine by calling spinWheels
    spinWheels();
    
    // TODO: Update the bank and display results by calling updateBankFromSpinAndDisplay
    updateBankFromSpinAndDisplay(bank);
}

// TODO: randomly spin the wheels and display the screen if requested to do so
void SlotMachine::play( Bank & bank )
{
    // TODO: pick three random letters for the sequence of available letters on this machine
    int size = sequence.size() - 1;
    RandomNumber r(0, size);
    char mWheel1 = sequence.at(r.random()) ;
    char mWheel2 = sequence.at(r.random()) ;
    char mWheel3 = sequence.at(r.random()) ;
    
    // TODO: update the wheel1, wheel2 and wheel3 members
    wheel1 = mWheel1;
    wheel2 = mWheel2;
    wheel3 = mWheel3;

    // TODO: Draw the machine by calling spinWheels
    spinWheels();
    
    // TODO: Update the bank and display results by calling updateBankFromSpinAndDisplay
    updateBankFromSpinAndDisplay(bank);
}

// spin the wheels
void SlotMachine::spinWheels( )
{
    // Draw the machine
    if (display)
    {
        Screen screen;
        screen.displayScreen(wheel1, wheel2, wheel3, sequence);
    }
}

// show the wager after one round of play
void SlotMachine::displayWager( int wager, int before, int after )
{
    // Show the wager information
    if (display)
    {
        Screen screen;
        screen.displayWager( wager, before, after );
    }
}

// update the bank for one round of play
void SlotMachine::updateBankFromSpinAndDisplay( Bank & b )
{
    int balanceBefore = b.balance();
    int wager = b.getWager( );
    
    PayTable p( wheel1, wheel2, wheel3 );
    p.manageWager( b );
    
    int balanceAfter = b.balance();
    
    // Display the wager lines
    displayWager( wager, balanceBefore, balanceAfter );
}

// trivial getter
char SlotMachine::getWheel1() const
{
    return( wheel1 );
}

// trivial getter
char SlotMachine::getWheel2() const
{
    return( wheel2 );
}

// trivial getter
char SlotMachine::getWheel3() const
{
    return( wheel3 );
}

void SlotMachine::showDisplay()
{
    display = true;
}

void SlotMachine::noDisplay()
{
    display = false;
}
