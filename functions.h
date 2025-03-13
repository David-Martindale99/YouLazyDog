#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "inventory.h"

#include <iostream>
#include <string>

void createNewJob(Inventory inventoryList[], int &currentCount);
void listJobs(Inventory inventoryList[], int currentCount);
void exitMenu();

#endif