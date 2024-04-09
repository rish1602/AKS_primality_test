// AKSClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"AKSLibrary.h"
#include <iostream>
#include<climits>

int main(void)
{
    std::cout << "Enter any random number less than equals to " << ULLONG_MAX << ": ";
    unsigned long long number_; std::cin >> number_;

    if (number_ > std::numeric_limits<unsigned long long>::max())  { std::cout << "\n Number has OVERFLOWED!!! You were asked to enter a number less than equal to " << ULLONG_MAX << " and you couldn't do that also!!!!"; exit; }
    
    if(aks(number_)) std::cout << "\n The number " << number_ << " is PRIME NUMBER. \n";
    else std::cout << "\n The number " << number_ << " is NOT a PRIME NUMBER. \n";
    
     
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
