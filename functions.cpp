#include "functions.h"
#include <iostream>
#include <limits>

/**
 * Function createNewJob
 * Purpose: To create a new job using the YouLazyDog class and store it in an object array
 *  
*/
void createNewJob(std::vector<Inventory>& inventoryList)
{
    Inventory newInventory;
    std::string license, name, phone;
    float price;

    // Dog license
    while (true)
    {
        std::cout << "\nEnter Dog License: ";
        std::cin >> license;

        if (license.length() >= 10)
        {
            std::cout << "\nInvalid Entry: Must be 9 characters, try again...\n";
        }
        else
        {
            newInventory.setDogLicense(license);
            break;
        }
    }

    // Dog Name
    while (true)
    {
        std::cout << "\nEnter Dog Name: ";
        std::cin >> name;

        if (name.length() >= 14)
        {
            std::cout << "\nInvalid Entry: Must be fewer then 14 letters, please try again...\n";
        }
        else
        {
            newInventory.setDogName(name);
            break;
        }
    }
    
    // Owner Phone
    while (true)
    {
        std::cout << "\nEnter Owner Phone (10 digits): ";
        std::cin >> phone;

        if (phone.length() != 10)
        {
            std::cout << "\nInvalid Entry: Must be 10 digits, please try again...\n";
        }    
        else
        {
            newInventory.setOwnerPhone(phone);
            break;
        }
            
    }

    // Price Quoted
    while (true) {
        std::cout << "\nEnter Price Quoted: ";

        if (!(std::cin >> price)) {
            std::cout << "\nPrice must be numeric. Try again...\n";
            std::cin.clear();  // Clears error flag.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush invalid input.
            continue;  // Retry loop.
        }

        if (price < 0) {
            std::cout << "\nPrice can't be negative. Try again...\n";
            continue;
        }

        newInventory.setPriceQuoted(price);
        break;
    }
    
    inventoryList.push_back(newInventory);
}

/**
 * Function listJobs
 * Purpose: To list all current jobs stored in the jobs object array
*/
void listJobs(const std::vector<Inventory>& inventoryList)
{
    if (inventoryList.empty()) {
        std::cout << "\nNo jobs to list.\n";
        return;
    }

    std::cout << "\n------- Current Jobs ------\n\n";

    for (int i = 0; i < inventoryList.size(); i++) {
        std::cout << "Job ID #" << (i + 1) << ":\n"
                  << "License: " << inventoryList[i].getDogLicense() << "\n"
                  << "Name: " << inventoryList[i].getDogName() << "\n"
                  << "Owner Phone: " << inventoryList[i].getOwnerPhone() << "\n"
                  << "Price Quoted: $" << inventoryList[i].getPriceQuoted() << "\n"
                  << "---------------------------\n";
    }

    float total = 0;
    for (int i = 0; i < inventoryList.size(); i++) {
        total += inventoryList[i].getPriceQuoted();
    }

    std::cout << "You currently have " 
              << inventoryList.size() 
              << " job(s)\n@ a total of $" 
              << total 
              << "\n"
              << "---------------------------\n" << std::endl;
    
}

/**
 * Function removeDog
 * Purpose: To remove a profile from the inventory
*/
void removeDog(std::vector<Inventory>& inventoryList)
{
    int idDog;

    if (inventoryList.size() == 0) {
        std::cout << "\nThere are no profiles to remove." << std::endl;
        return;
    }
   
    while (true)
    {
        std::cout << "\nSelect a profile ID to remove: ";
        if (!(std::cin >> idDog)) {
                std::cout << "\nID must be numeric. Try again...\n";
                std::cin.clear();  // Clears error flag.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush invalid input.
                continue;
            }
        if (idDog < 1 || inventoryList.size() <= idDog) {
            std::cout << "\nInvalid Entry: ID out of range, try again...";
            continue;
        }

        if (inventoryList.size() > idDog) {
            inventoryList.erase(inventoryList.begin() + (idDog - 1));
            std::cout << "\nProfile #" << idDog << " removed.\n";
            break;
        }
    }
}

/**
 * Function exitMenu
 * Purpose: To exit the program menu
*/
void exitMenu()
{
    std::cout << "Exiting...\n" << "Have a nice day :)" << std::endl;
    exit(EXIT_SUCCESS);
}