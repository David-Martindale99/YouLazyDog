#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "inventory.h"

#include <iostream>
#include <string>

void createNewJob(std::vector<Inventory>& inventoryList);
void listJobs(const std::vector<Inventory>& inventoryList);
void removeDog(std::vector<Inventory>& inventoryList);
void exitMenu();

#endif