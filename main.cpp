/***************************************************************************
 * Program: You're a dog walker! Here's a program to help you out :)
 * Author: David Martindale
 * Date: 12 March 2025
 * Description:
 *   This program displays a menu to help your doggy business and has
 *   the following functionalities:
 *     1. Input a new walking job
 *     2. List all of your current jobs
 *     3. Remove compleated job profiles
 *     4. Exit the program
 *
 * How exciting!
***************************************************************************/

#include "functions.h"
#include "inventory.h"
#include <iostream>
#include <limits>
#include <vector>

int main() {
    int selection = 0;
    bool running = true;
    std::vector<Inventory> inventoryList;

    while (running)
    {
        //Display Menu
        std::cout << "\nYou Lazy Dog Menu" << "\n\n";
        std::cout << "1. Enter a new job\n"
                  << "2. List all current jobs\n"
                  << "3. Remove a profile\n" 
                  << "4. Exit\n\n"
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
                if (inventoryList.size() >= 10) {
                    std::cout << "\nInventory is full!\n";
                    float total = 0;
                    for (int i = 0; i < inventoryList.size(); i++) {
                        total += inventoryList[i].getPriceQuoted();
                    }

                    std::cout << "---------------------------\n"
                              << "You currently have " 
                              << inventoryList.size() 
                              << " job(s)\n@ a total of $" 
                              << total 
                              << "\n---------------------------" 
                              << std::endl;
                    break;
                }
                createNewJob(inventoryList);
                break;
            case 2:
                listJobs(inventoryList);
                break;
            case 3:
                removeDog(inventoryList);
                break;
            case 4:
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