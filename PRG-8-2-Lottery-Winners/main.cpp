//
//  main.cpp
//  PRG-8-2-Lottery-Winners
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A lottery ticket buyer purchases ten tickets a week, always playing the same 5-digit
//  "lucky" combinations. Write a program that initializes an array or vector with these
//  numbers, then let the player enter this week's winning 5-digit number. The program
//  should perform a linear search through the list of the player's numbers and report
//  whether or not one of the tickets is a winner this week. Here are the numbers:
//
//  13579   26791   26792   33445   55555
//  62483   77777   79422   85647   93121

#include <iostream>

using namespace std;

const int INT_ARRAY_SIZE = 8;

int getLotteryWinner();
bool compareLotteryNumbers(const int[], const int, int);

int main()
{
    bool booIsWinner;
    
    int intLotteryWinner;
    int intLotteryChoices[INT_ARRAY_SIZE] = {13579, 26791, 33445, 55555,
                                             62483, 77777, 85647, 93121};
    
    intLotteryWinner = getLotteryWinner();
    
    booIsWinner = compareLotteryNumbers(intLotteryChoices, INT_ARRAY_SIZE, intLotteryWinner);
    
    if(booIsWinner != true)
    {
        cout << "Sorry, your numbers did not match this week's winning number.\n";
    }
    else if(booIsWinner == true)
    {
        cout << "Congratulations! One of your numbers matched this weeks winning number!\n";
    }
    else
    {
        cout << "ERROR CHECKING BOOL" << endl;
    }
    
    return 0;
}

int getLotteryWinner()
{
    int intWinningNumber;
    
    cout << "Please enter the winning lottery number this week: ";
    cin >> intWinningNumber;
    while(!intWinningNumber || intWinningNumber < 10000 || intWinningNumber > 99999)
    {
        cout << "Please enter a number between 10000 and 99999: ";
        cin.clear();
        cin.ignore();
        cin >> intWinningNumber;
    }
    
    return intWinningNumber;
}

bool compareLotteryNumbers(const int intArray[], const int INT_SIZE, int intWinner)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < INT_SIZE && !found)
    {
        if(intArray[index] == intWinner)
        {
            found = true;
            position = index;
            cout << intArray[index] << endl;
        }
        index++;
    }
    
    return found;
}

