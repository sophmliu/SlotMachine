//
//  Bank.cpp
//  Project 6
//
//  Created by Sophia Liu on 8/11/20.
//  Copyright © 2020 Sophia Liu. All rights reserved.
//

#include "Bank.h"


// The purpose of this class is to implement a bank of funds and a wager than can be won or lost
Bank::Bank( int amount )
{
    bankAmount = amount;
    wager = 0;
}
    
// TODO: adjust the bank balance for the amount won or lost
void Bank::win( int amount )
{
    bankAmount = bankAmount + amount;// add to the balance
    wager = 0;//set wager to zero
}
    
// TODO: adjust the bank balance for the amount won or lost
void Bank::lose( int amount )
{
    bankAmount = bankAmount - amount;// subtract from the balance
    wager = 0;//set the wager to zero
}

// TODO: adjust the bank balance for the amount being added to the bank
void Bank::deposit( int amount )
{
    bankAmount = bankAmount + amount;// add to the balance
}
 
// trivial getter
int Bank::balance() const
{
    return( bankAmount );
}
    
// TODO: return the bank balance and set it bank to zero
int Bank::cashOut( )
{
    int balance = bankAmount;// return the balance
    wager = 0; bankAmount = 0;// set both the wager and the balance to zero
    return( balance );
}

// TODO: can the amount be wagered??
bool Bank::canWager( int amount ) const
{
     // should return true when there are sufficient funds (that is, the wager being equal to or less than the available bankAmount); false otherwise
    if (amount <= bankAmount)
        {return true;}
    else
        return( false );
}
    
// trivial setter
void Bank::setWager( int amount )
{
    wager = amount;
}
 
// trivial getter
int Bank::getWager() const
{
    return( wager );
}
