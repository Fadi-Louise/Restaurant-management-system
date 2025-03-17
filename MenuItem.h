/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuItem.h
 * Author: asus
 *
 * Created on April 23, 2024, 6:17 PM
 */

/*-- MENUITEM_H ---------------------------------------------------------
This header file defines the MenuItem class, which represents an item in a
 *  menu with 
various properties.

The MenuItem class is assumed to be used as the ElementType for the Menu class 
(see MENU_H). It provides functionalities for the following constructors
 *  and functions:

 Constructors:
 * MenuItem();
 * MenuItem(int itemId, string itemName, double itemPrice, char itemType,
 *  char itemCategory, ItemComponents);
 * MenuItem(const MenuItem &);
 
 Destructor:
 * ~MenuItem();
 
 Setters:
 * void configureItem(int itemId, string itemName, double itemPrice,
 *  char itemType, char itemCategory, ItemComponents);
 * void setItemId(int itemId);
 * void setItemName(string itemName);
 * void setItemPrice(double itemPrice);
 * void setItemType(char itemType);
 * void setItemCategory(char itemCategory);
 * void setItemComponents(ItemComponents itemComponents);
 
 Getters:
 * int getItemId() const;
 * string getItemName() const;
 * double getItemPrice() const;
 * char getItemType() const;  
 * char getItemCategory() const; 
 * ItemComponents getItemComponents() const;
 
 Overloaded Operators:
 * friend ostream & operator<<(ostream&, const MenuItem &);
 * friend istream & operator>>(istream&, MenuItem &);

 Data Fields:
 * int itemId;
 * string itemName;
 * double itemPrice;
 * char itemType;
 * char itemCategory;
 * ItemComponents itemComponents;
-------------------------------------------------------------------------*/

#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<string> ItemComponents;

class MenuItem {
public:
    /*** Function Members ***/

    // Default constructor
    MenuItem();

    /*----------------------------------------------------------------------
    Construct an empty MenuItem object with default values.

    Precondition: None.

    Postcondition: An empty MenuItem object is created with default values for 
                   all properties.
    ---------------------------------------------------------------------*/

    // Constructor with parameters
    MenuItem(int itemId, string itemName, double itemPrice, char itemType,
            char itemCategory, ItemComponents components);

    /*----------------------------------------------------------------------
    Construct a MenuItem object with the provided properties.

    Precondition: All arguments are valid (e.g., itemId is a positive integer, 
                   itemPrice is non-negative, etc.).

    Postcondition: A MenuItem object is created with the specified properties.
    ---------------------------------------------------------------------*/

    // Copy constructor
    MenuItem(const MenuItem &);

    /*----------------------------------------------------------------------
    Create a deep copy of another MenuItem object.

    Precondition: The source MenuItem object exists.

    Postcondition: A new MenuItem object is created as a deep copy of the source.
    ---------------------------------------------------------------------*/

    // Destructor
    ~MenuItem();

    /*----------------------------------------------------------------------
    Destroy the MenuItem object and deallocate its memory.

    Precondition: The MenuItem object exists.

    Postcondition: The MenuItem object is destroyed and its memory is released.
    ---------------------------------------------------------------------*/

    // Setters
    void configureItem(int itemId, string itemName, double itemPrice,
            char itemType, char itemCategory, ItemComponents components);

    /*----------------------------------------------------------------------
    Set all properties of the MenuItem object.

    Precondition: All arguments are valid (same as constructor with all arguments).

    Postcondition: The properties of the MenuItem object are updated with 
                   the provided values.
    ---------------------------------------------------------------------*/

    void setItemId(int itemId);

    /*----------------------------------------------------------------------
    Set the ID of the MenuItem object.

    Precondition: The argument (itemId) is a valid positive integer.

    Postcondition: The ID property of the MenuItem object is updated.
    ---------------------------------------------------------------------*/

    void setItemName(string itemName);

    /*----------------------------------------------------------------------
    Set the name of the MenuItem object.

    Precondition: The argument (itemName) is a valid string.

    Postcondition: The name property of the MenuItem object is updated with 
                   the provided string.
    ---------------------------------------------------------------------*/

    void setItemPrice(double itemPrice);

    /*----------------------------------------------------------------------
    Set the price of the MenuItem object.

    Precondition: The argument (itemPrice) is a non-negative double value.

    Postcondition: The price property of the MenuItem object is updated with 
                   the provided value.
    ---------------------------------------------------------------------*/

    void setItemType(char itemType);

    /*----------------------------------------------------------------------
    Set the type of the MenuItem object (e.g., 'D' for drink, 'F' for food).

    Precondition: The argument (itemType) is a valid character representing 
                   the item type.

    Postcondition: The type property of the MenuItem object is updated with 
                   the provided character.
    ---------------------------------------------------------------------*/

    void setItemCategory(char itemCategory);

    /*----------------------------------------------------------------------
    Set the category of the MenuItem object (e.g., 'A' for appetizer, 'M' for main course).

    Precondition: The argument (itemCategory) is a valid character representing 
                   the item category.

    Postcondition: The category property of the MenuItem object is updated with 
                   the provided character.
    ---------------------------------------------------------------------*/

    void setItemComponents(ItemComponents components);

    /*----------------------------------------------------------------------
    Set the list of components for the MenuItem object.

    Precondition: The argument (components) is a valid vector<string> 
                   containing component names.

    Postcondition: The components property of the MenuItem object is updated with 
                   the provided component list.
    ---------------------------------------------------------------------*/

    // Getters
    int getItemId() const;

    /*----------------------------------------------------------------------
    Retrieve the ID of the MenuItem object.

    Precondition: The MenuItem object exists.

    Postcondition: Returns the ID of the MenuItem object.
    ---------------------------------------------------------------------*/

    string getItemName() const;

    /*----------------------------------------------------------------------
    Retrieve the name of the MenuItem object.

    Precondition: The MenuItem object exists.

    Postcondition: Returns the name of the MenuItem object.
    ---------------------------------------------------------------------*/

    double getItemPrice() const;

    /*----------------------------------------------------------------------
    Retrieve the price of the MenuItem object.

    Precondition: The MenuItem object exists.

    Postcondition: Returns the price of the MenuItem object.
    ---------------------------------------------------------------------*/

    char getItemType() const;

    /*----------------------------------------------------------------------
    Retrieve the type of the MenuItem object.

    Precondition: The MenuItem object exists.

    Postcondition: Returns the type character of the MenuItem object.
    ---------------------------------------------------------------------*/

    char getItemCategory() const;

    /*----------------------------------------------------------------------
    Retrieve the category of the MenuItem object.

    Precondition: The MenuItem object exists.

    Postcondition: Returns the category character of the MenuItem object.
    ---------------------------------------------------------------------*/

    ItemComponents getItemComponents() const;

    /*----------------------------------------------------------------------
    Retrieve the list of components for the MenuItem object.

    Precondition: The MenuItem object exists.

    Postcondition: Returns the component list (vector<string>) of the MenuItem object.
    ---------------------------------------------------------------------*/

    // Overloading stream operators
    friend ostream & operator<<(ostream&, const MenuItem &);
    friend istream & operator>>(istream&, MenuItem &);

    /*----------------------------------------------------------------------
    Overload the stream insertion operator (<<) to allow writing a MenuItem object 
    to an output stream.

    Precondition: The MenuItem object exists and the output stream is valid.

    Postcondition: The properties of the MenuItem object are formatted and written 
                   to the output stream.
    ---------------------------------------------------------------------*/

    /*----------------------------------------------------------------------
    Overload the stream extraction operator (>>) to allow reading data 
    from an input stream and populating a MenuItem object.

    Precondition: The input stream is valid and contains data in a format 
                   compatible with the MenuItem object's properties.

    Postcondition: The MenuItem object's properties are populated with the data 
                   read from the input stream.
    ---------------------------------------------------------------------*/

private:
    /*** Data Members ***/
    int itemId;
    string itemName;
    double itemPrice;
    char itemType;
    char itemCategory;
    ItemComponents itemComponents;
};

#endif /* MENUITEM_H */