/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuItem.cpp
 * Author: asus
 * 
 * Created on April 23, 2024, 6:17 PM
 */

#include "MenuItem.h"
#include <sstream>
#include <random>
#include <time.h>

// Default constructor for the MenuItem class
// Initializes member variables with default values (typically empty string, 0 price, etc.)
// This constructor is useful when you want to create a MenuItem object and set its properties later.

MenuItem::MenuItem() {
    itemId = 0;
    itemName = "";
    itemPrice = 0.0;
    itemType = '\0';
    itemCategory = '\0';
    itemComponents.clear();
}

// Constructor with all arguments
// Creates a MenuItem object with the provided properties.
// This constructor allows you to create a MenuItem object in one step by specifying all its properties.

MenuItem::MenuItem(int itemId, string itemName, double itemPrice,
        char itemType, char itemCategory,
        ItemComponents components = {}) {
    configureItem(itemId, itemName, itemPrice, itemType, itemCategory, components);
}

// Copy constructor
// Creates a deep copy of another MenuItem object.
// This constructor is used when you want to create a new MenuItem object that is a complete copy of another existing MenuItem object.
// It ensures that changes made to the new object won't affect the original object.

MenuItem::MenuItem(const MenuItem &menuItem) {
    configureItem(menuItem.itemId, menuItem.itemName, menuItem.itemPrice,
            menuItem.itemType, menuItem.itemCategory, menuItem.itemComponents);
}

// Destructor
// Deallocates memory associated with the MenuItem object's components list.
// The destructor is called automatically when a MenuItem object goes out of scope or is explicitly deleted.
// It's important to properly deallocate memory to avoid memory leaks.

MenuItem::~MenuItem() {
    itemComponents.clear();
}

// Setter function to set all item properties at once
// Calls individual setter functions for each property.
// This function allows you to set all the properties of a MenuItem object in one call.

void MenuItem::configureItem(int itemId, string itemName, double itemPrice,
        char itemType, char itemCategory,
        ItemComponents components ) {
    setItemId(itemId);
    setItemName(itemName);
    setItemPrice(itemPrice);
    setItemType(itemType);
    setItemCategory(itemCategory);
    setItemComponents(components);
}

// Sets the MenuItem's ID.
// Input: Positive integer.

void MenuItem::setItemId(int itemId) {
    this->itemId = itemId;
}

// Retrieves the MenuItem's ID.
// Output: Integer ID of the MenuItem.

int MenuItem::getItemId() const {
    return itemId;
}

// Sets the MenuItem's name.
// Input: Non-empty string.

void MenuItem::setItemName(string itemName) {
    this->itemName = itemName;
}

// Retrieves the MenuItem's name.
// Output: String name of the MenuItem.

string MenuItem::getItemName() const {
    return itemName;
}

// Sets the MenuItem's price.
// Input: Non-negative double.

void MenuItem::setItemPrice(double itemPrice) {
    if (itemPrice >= 0.0) {
        this->itemPrice = itemPrice;
    } else {
        this->itemPrice = 0.0; // Ensures the item price cannot be negative
    }
}

// Retrieves the MenuItem's price.
// Output: Double price of the MenuItem.

double MenuItem::getItemPrice() const {
    return itemPrice;
}

// Sets the MenuItem's type.
// Input: 'N' for Normal, 'V' for Vegetarian, 'G' for Vegan; defaults to 'N' if invalid.

void MenuItem::setItemType(char itemType) {
    char upperType = toupper(itemType);
    if (upperType == 'N' || upperType == 'V' || upperType == 'G') {
        this->itemType = upperType;
    } else {
        this->itemType = 'N'; // Default to 'N' if invalid input is provided
    }
}

// Retrieves the MenuItem's type.
// Output: Char representing the MenuItem's type.

char MenuItem::getItemType() const {
    return itemType;
}

// Sets the MenuItem's category.
// Input: 'A' for Appetizers, 'M' for Main Dishes, 'D' for Desserts, 'B' for Beverages; defaults to 'A' if invalid.

void MenuItem::setItemCategory(char itemCategory) {
    char upperCategory = toupper(itemCategory);
    if (upperCategory == 'A' || upperCategory == 'M' || upperCategory == 'D' || upperCategory == 'B') {
        this->itemCategory = upperCategory;
    } else {
        this->itemCategory = 'A'; // Default to 'A' if invalid input is provided
    }
}

// Retrieves the MenuItem's category.
// Output: Char representing the MenuItem's category.

char MenuItem::getItemCategory() const {
    return itemCategory;
}

// Sets the MenuItem's components.
// Input: Vector of strings representing the components.

void MenuItem::setItemComponents(ItemComponents components) {
    this->itemComponents = components;
}

// Retrieves the MenuItem's components.
// Output: Vector of strings representing the components.

ItemComponents MenuItem::getItemComponents() const {
    return itemComponents;
}


// Overloaded stream insertion operator (<<) to write MenuItem object to output stream
// This operator allows you to easily output a MenuItem object to a stream (e.g., cout) in a formatted way.

ostream & operator<<(ostream &out, const MenuItem &menuItem) {
    out << "Item ID: " << menuItem.itemId << ", Name: " << menuItem.itemName
            << ", Type: " << menuItem.itemType << ", Price: " <<
            menuItem.itemPrice << ", Category: " << menuItem.itemCategory;

    if (!menuItem.itemComponents.empty()) {
        out << ", Components: ";
        for (const auto &component : menuItem.itemComponents) {
            out << component << " ";
        }
    }

    out << endl;
    return out;
}

// Overloaded stream extraction operator (>>) to read data from input stream and populate MenuItem object
// This operator allows you to create a MenuItem object by reading data from a stream (e.g., cin) in a user-interactive way.

istream & operator>>(istream &input, MenuItem &menuItem) {
    cout << "Enter item properties:\n";

    cout << "Item ID: ";
    input >> menuItem.itemId;

    cout << "Item Name: ";
    input.ignore(); // Ignores the newline character left by cin
    getline(input, menuItem.itemName);

    cout << "Item Price: ";
    input >> menuItem.itemPrice;
    while (menuItem.itemPrice < 0) {
        cout << "Price must be non-negative. Enter again: ";
        input >> menuItem.itemPrice;
    }

    cout << "Item Type (N for Normal, V for Vegetarian, G for Vegan): ";
    input >> menuItem.itemType;
    menuItem.setItemType(menuItem.itemType); // Validates and sets the item type

    cout << "Item Category (A for Appetizers, M for Main Dishes, D for Desserts,"
            " B for Beverages): ";
    input >> menuItem.itemCategory;
    menuItem.setItemCategory(menuItem.itemCategory); // Validates and sets the item category

    char choice;
    cout << "Add components? (y/n): ";
    input >> choice;

    if (tolower(choice) == 'y') {
        cout << "Enter components (separated by commas): ";
        string components;
        input.ignore(); // Ignores the newline character left by cin
        getline(input, components);
        stringstream ss(components);
        string component;
        while (getline(ss, component, ',')) {
            menuItem.itemComponents.push_back(component);
        }
    }

    return input;
}