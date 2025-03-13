/***************************************************************************
 * Program: You're a dog walker! Here's a program to help you out :)
 * Author: David Martindale
 * Date: 12 March 2025
 * Description:
 *   This program displays a menu to help your doggy business and has
 *   the following functionalities:
 *     1. Input a new walking job
 *     2. List all of your current jobs
 *     3. Exit the program
 *
 * How exciting!
***************************************************************************/

#include "functions.h"
#include "inventory.h"
#include <iostream>
#include <limits>

int main() {
    const int MAX = 5;
    int selection = 0;
    bool running = true;

    Inventory inventoryList[MAX];
    int currentCount = 0;

    while (running)
    {
        //Display Menu
        std::cout << "\nYou Lazy Dog Menu" << "\n\n";
        std::cout << "1. Enter a new job\n"
                  << "2. List all current jobs\n"
                  << "3. Exit\n\n" 
                  << "Selection: ";  

        if (!(std::cin >> selection))
        {
            std::cout << "\n\nInvalid selection!\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove invalid input
            continue; // Retry
        }
        
        switch (selection)
        {
            case 1:
                if (currentCount >= 5) {
                    std::cout << "\nInventory is full!\n";
                    float total = 0;
                    for (int i = 0; i < currentCount; i++) {
                        total += inventoryList[i].getPriceQuoted();
                    }

                    std::cout << "---------------------------\n"
                              << "You currently have " 
                              << currentCount 
                              << " job(s)\n@ a total of $" 
                              << total 
                              << "\n---------------------------" 
                              << std::endl;
                    break;
                }
                createNewJob(inventoryList, currentCount);
                break;
            case 2:
                listJobs(inventoryList, currentCount);
                break;
            case 3:
                exitMenu();
                running = false;
                break;
            default:
                std::cout << "Invalid selsection. Please try again." << std::endl;
                break;
        }
    }
    return 0;
}