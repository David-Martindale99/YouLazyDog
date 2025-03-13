#include "inventory.h"
#include <cstdlib> // For exit()

// Prototype
Inventory::Inventory() : dogLicense(""), dogName(""), ownerPhone(""), priceQuoted(-1.0f) {}

// Setters
void Inventory::setDogLicense(std::string license)
{
    if (license.length() >= 10)
        exit(EXIT_FAILURE);
    else
        this->dogLicense = license;
}

void Inventory::setDogName(std::string name)
{
    if (name.length() >= 14)
        exit(EXIT_FAILURE);
    else
        this->dogName = name;
}

void Inventory::setOwnerPhone(std::string phone)
{
    if (phone.length() != 10)
        exit(EXIT_FAILURE);
    else
        this->ownerPhone = phone;
}

void Inventory::setPriceQuoted(float price)
{
    if (price < 0)
        exit(EXIT_FAILURE);
    else
        this->priceQuoted = price;
}

// Getters
std::string Inventory::getDogLicense() const
{
    return dogLicense.empty() ? "License NOT set" : dogLicense;
}

std::string Inventory::getDogName() const
{
    return dogName.empty() ? "Dog name NOT set" : dogName;
}

std::string Inventory::getOwnerPhone() const
{
    return ownerPhone.empty() ? "Owner phone NOT set" : ownerPhone;
}

float Inventory::getPriceQuoted() const
{
    return (priceQuoted <= 0.0f) ? -1.0f : priceQuoted;
}