#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

/**
 * Class Inventory
 * Purpose:
 *      Represents a dog inventory entry with information such as dog license,
 *      dog's name, owner's phone, and price quoted.
 */
class Inventory
{
    private:
        // Member vars
        std::string dogLicense;
        std::string dogName;
        std::string ownerPhone;
        float priceQuoted;

    public:
        Inventory(); //Prototype

        // Setters
        void setDogLicense(std::string license);
        void setDogName(std::string name);
        void setOwnerPhone(std::string phone);
        void setPriceQuoted(float price);

        // Getters
        std::string getDogLicense() const;
        std::string getDogName() const;
        std::string getOwnerPhone() const;
        float getPriceQuoted() const;
};

#endif