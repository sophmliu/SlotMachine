//
//  PayTable.cpp
//  Project 6
//
//  Created by Sophia Liu on 8/11/20.
//  Copyright © 2020 Sophia Liu. All rights reserved.
//

#include "PayTable.h"


PayTable::PayTable( char wheel1, char wheel2, char wheel3 )
{
    mWheel1 = wheel1;
    mWheel2 = wheel2;
    mWheel3 = wheel3;
}

// TODO:  For the wheel combination, determine the pay multiplier
PayTable::Multiplier PayTable::calculateMultiplier( )
{
    Multiplier result (ZERO);
    
    if ((mWheel1 == 'A' && mWheel2 != 'A' && mWheel2 != 'Q' && mWheel2 != 'K' && mWheel3 != 'A')
    || (mWheel1 != 'A' && mWheel1 != 'Q' && mWheel1 != 'K' && mWheel2 == 'A' && mWheel3 != 'A')
    || (mWheel1 != 'A' && mWheel1 != 'K' && mWheel1 != 'Q' && mWheel2 != 'A' && mWheel3 == 'A')) //a single Ace  as long as not a 5-to-1 straight
        {result = ONETIME;}
    
    if ((mWheel1 == 'A' && mWheel2 == 'A' && mWheel3 != 'A')
    || (mWheel1 == 'A' && mWheel2 != 'A' && mWheel3 == 'A')
    || (mWheel1 != 'A' && mWheel2 == 'A' && mWheel3 == 'A')) //two Aces
        {result = FIVETIME;}
    
    if ((mWheel1 == mWheel2 && mWheel2 != mWheel3 && mWheel1 != 'A' )
    || (mWheel1 == mWheel3 && mWheel3 != mWheel2 && mWheel1 != 'A')
    || (mWheel3 == mWheel2 && mWheel1 != mWheel3 && mWheel3 != 'A')) //any pair other than Aces
        {result = THREETIME;}
    
    if ((mWheel1 == mWheel2 && mWheel1 != 'A' && mWheel3 == 'A')
    || (mWheel1 == mWheel3 && mWheel1 != 'A' && mWheel2 == 'A')
    || (mWheel3 == mWheel2 && mWheel3 != 'A' && mWheel1 == 'A'))//any pair other than Aces + Ace
        {result = FOURTIME;}
    
    if (mWheel1 == 'A' && mWheel2 == 'A' && mWheel3 == 'A')//three Aces
        {result = TENTIME;}
    
    if (mWheel1 == mWheel2 && mWheel2 == mWheel3 && mWheel1 != 'A')//three of a kind other than Aces
        {result = SEVENTIME;}
    
    if ((mWheel1 == 'A' && mWheel2 == 'K' && mWheel3 == 'Q')
    || (mWheel1 == 'K' && mWheel2 == 'A' && mWheel3 == 'Q')
    || (mWheel1 == 'Q' && mWheel2 == 'K' && mWheel3 == 'A')
    || (mWheel1 == 'K' && mWheel2 == 'Q' && mWheel3 == 'A')
    || (mWheel1 == 'A' && mWheel2 == 'Q' && mWheel3 == 'K'))// AKQ, KAQ, QKA, KQA, QAK, AQK)
        {result = FIVETIME;}

    return(result);
}

// TODO: For the wheel combination and wager of the passed Bank, update the Bank's balance
void PayTable::manageWager( Bank& bank )
{
    // for the wager, adjust the Bank balance based on the pay multiplier
    double amount = bank.getWager();
    Multiplier multiplier = calculateMultiplier();
    
    // TODO: adjust the bank balance accordingly...
    if (multiplier == ONETIME)
        {bank.win(amount * 1);}
    if (multiplier == FIVETIME)
        {bank.win(amount * 5);}
    if (multiplier == THREETIME)
        {bank.win(amount * 3);}
    if (multiplier == FOURTIME)
        {bank.win(amount * 4);}
    if (multiplier == TENTIME)
        {bank.win(amount * 10);}
    if (multiplier == SEVENTIME)
        {bank.win(amount * 7);}
    if (multiplier == ZERO)
        {bank.lose(amount);}
    
}
