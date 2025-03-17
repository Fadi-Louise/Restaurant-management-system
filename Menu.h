/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Menu.h
 * Author: asus
 *
 * Created on April 24, 2024, 3:28 PM
 */

/*---------------------- MENU_H ----------------------
This header file defines a generic Menu class that uses a linked list to manage elements of any type (ElementType).
It offers basic functionality for inserting, deleting, searching, and displaying elements.

The Menu class consists of:
    - Nested Node class to represent individual elements in the linked list.
    - Various operations for managing the linked list, including:
 * isEmpty(): Checks if the menu is empty.
 * searchGetItem(int): Retrieves an item by its unique ID.
 * searchByElementType(): Returns a new Menu with certain item types.
 * searchMenuItemById(int): Determines if an item with a specific ID exists.
 * insertItem(const ElementType &): Inserts a new item into the menu.
 * deleteMenuItemById(int): Deletes an item by its unique ID.
 * display(ostream &): Displays the contents of the Menu.
    - Operator overloading for:
 * Assignment operator (=) to assign one Menu to another.
 * Stream insertion operator (<<) to display the Menu.
-----------------------------------------------------*/

#ifndef MENU_H
#define MENU_H

#include <iostream>  // Includes basic I/O operations
#include <vector>    // Includes the vector container
#include <cassert>   // Provides assert for debugging
#include <new>       // Provides nothrow for safe memory allocation
#include "MenuItem.h" // Header file for the MenuItem class

using namespace std;

// Template class for a menu that uses a linked list to manage elements of type ElementType

template <typename ElementType>
class Menu {
public:

    /* Nested Node class for representing each element in the linked list */
    class Node {
    public:
        // Constructor to initialize a Node with a given element and a pointer to the next Node

        Node(const ElementType &element)
        /*----------------------------------------------------------------------
        Constructor to create a Node object containing an element.

        Precondition: The element to be stored is valid.

        Postcondition: A Node object is created with the provided element.
        ---------------------------------------------------------------------*/

        : data(element), next(nullptr) {
        }

        ElementType data; // The element stored in the Node
        Node *next; // Pointer to the next Node in the list
    };

    // Default constructor to create an empty Menu

    Menu() : firstNode(nullptr), size(0) {
    }
    /*----------------------------------------------------------------------
            Construct an empty Menu object.

            Precondition: None.

            Postcondition: An empty Menu object is created.
            ---------------------------------------------------------------------*/
    // Copy constructor to create a deep copy of another Menu object

    Menu(const Menu<ElementType> &source) {
        // If the source Menu has nodes, initialize the new Menu with a deep copy
        if (source.firstNode) {
            // Create the first node for the new Menu
            firstNode = new Node(source.firstNode->data);
            assert(firstNode != nullptr); // Ensure memory allocation succeeded

            // Variables to traverse the linked list
            Node *sourcePtr = source.firstNode->next;
            Node *currentPtr = firstNode;

            // Copy the entire linked list from the source Menu
            while (sourcePtr) {
                // Create a new Node and link it to the previous Node
                currentPtr->next = new Node(sourcePtr->data);
                assert(currentPtr->next != nullptr); // Check memory allocation
                // Move to the next Node in both lists
                currentPtr = currentPtr->next;
                sourcePtr = sourcePtr->next;
                size++; // Increment the size of the new Menu
            }
        }
    }
    /*----------------------------------------------------------------------
    Copy constructor to create a deep copy of another Menu object.

    Precondition: The source Menu object exists.

    Postcondition: A new Menu object is created as a deep copy of the source.
    ---------------------------------------------------------------------*/


    // Destructor to release memory by deleting all Nodes in the linked list

    ~Menu() {
        // Traverse the linked list and delete each Node
        while (firstNode) {
            Node *temp = firstNode; // Temporary pointer to the current Node
            firstNode = firstNode->next; // Move to the next Node
            delete temp; // Deallocate memory
        }
    }
    /*----------------------------------------------------------------------
        Destroy the Menu object and deallocate its memory.

        Precondition: The Menu object exists.

        Postcondition: The Menu object is destroyed and its memory is released.
        ---------------------------------------------------------------------*/
    // Function to check if the Menu is empty

    bool isEmpty() const {
        // Returns true if the size is zero, indicating there are no Nodes
        return size == 0;
    }
    /*----------------------------------------------------------------------
        Check if there are no elements in the Menu.

        Precondition: The Menu object exists.

        Postcondition: Returns true if the Menu is empty, false otherwise.
        ---------------------------------------------------------------------*/

    // Function to retrieve an item from the Menu by its ID

    ElementType searchGetItem(int id) const {
        // Start from the first Node and traverse the linked list
        Node *current = firstNode;

        // Loop through the list to find the Node with the specified ID
        while (current) {
            if (current->data.getItemId() == id) {
                // If found, return the data (element)
                return current->data;
            }
            current = current->next; // Move to the next Node
        }

        // Return a default ElementType if not found
        return ElementType();
    }
    /*----------------------------------------------------------------------
    Retrieve the element from the Menu that has the specified ID.

    Precondition: The Menu object exists. The ID to be searched is valid.

    Postcondition: Returns the element with the matching ID (if it exists),
                   or throws an exception if not found.
    ---------------------------------------------------------------------*/

    // Function to search for vegetarian (G) or vegan (V) items and return a new Menu

    Menu<ElementType> searchByElementType() const {
        Menu<ElementType> resultMenu; // Create a new Menu for results

        Node *current = firstNode; // Start from the first Node
        while (current) // Traverse the linked list
        {
            // If the current item's type is vegetarian or vegan
            if (current->data.getItemType() == 'V' || current->data.getItemType() == 'G') {
                // Add it to the result Menu
                resultMenu.insertItem(current->data);
            }
            current = current->next; // Move to the next Node
        }

        // Return the new Menu containing vegetarian/vegan items
        return resultMenu;
    }
    /*----------------------------------------------------------------------
        This function is assumed to search for and return a new Menu containing
        elements of a specific type within the original Menu.

        Precondition: The Menu object exists.

        Postcondition: A new Menu containing elements of the specified type is returned.
        ---------------------------------------------------------------------*/
    // Function to check if an item exists in the Menu by its ID

    bool searchMenuItemById(int id) const {
        Node *current = firstNode; // Start from the first Node

        // Traverse the linked list to find the specified ID
        while (current) {
            if (current->data.getItemId() == id) {
                // Return true if found
                return true;
            }
            current = current->next; // Move to the next Node
        }
        // Return false if not found
        return false;
    }
    /*----------------------------------------------------------------------
        Search for an element in the Menu based on its ID.

        Precondition: The Menu object exists. The ID to be searched is valid.

        Postcondition: Returns true if an element with the matching ID is found,
                       false otherwise.
        ---------------------------------------------------------------------*/

    // Function to insert a new item into the Menu while maintaining order by price

    void insertItem(const ElementType &item) {
        Node *newNode = new Node(item); // Create a new Node with the provided item
        assert(newNode != nullptr); // Check for successful memory allocation

        if (!firstNode) // If the Menu is empty
        {
            // Set firstNode to newNode
            firstNode = newNode;
        } else {
            Node *current = firstNode; // Pointer to traverse the list
            Node *previous = nullptr; // Pointer to keep track of the previous Node

            // Find the correct position to insert the newNode based on price
            while (current && current->data.getItemPrice() <= newNode->data.getItemPrice()) {
                previous = current; // Update previous to current
                current = current->next; // Move to the next Node
            }

            if (previous) // If previous is not null
            {
                // Insert newNode between previous and current
                previous->next = newNode;
                newNode->next = current;
            } else {
                // Insert at the beginning if smaller than the first item
                newNode->next = firstNode; // Link newNode to firstNode
                firstNode = newNode; // Update firstNode
            }
        }
        size++; // Increment the size of the list
    }

    // Function to delete an item by ID

    void deleteMenuItemById(int id) {
        if (firstNode) // If the Menu is not empty
        {
            if (firstNode->data.getItemId() == id) // If the first Node has the matching ID
            {
                Node *temp = firstNode; // Temporary pointer to the current Node
                firstNode = firstNode->next; // Update the firstNode
                delete temp; // Deallocate memory
            } else // If the ID is not the first Node
            {
                Node *current = firstNode; // Pointer to traverse the list
                while (current->next && current->next->data.getItemId() != id) {
                    current = current->next; // Move to the next Node
                }
                if (current->next) // If the ID is found
                {
                    Node *toDelete = current->next; // Node to be deleted
                    current->next = current->next->next; // Bypass the Node to delete
                    delete toDelete; // Deallocate memory
                }
            }
            size--; // Decrement the size after deletion
        }
    }

    // Function to display the Menu's contents

    void display(ostream &out) const {
        if (isEmpty()) // If the Menu is empty
        {
            out << "Menu is currently empty." << endl; // Display a message
        } else {
            Node *current = firstNode; // Start from the first Node
            while (current) // Traverse the linked list
            {
                out << current->data; // Display the data of each Node
                current = current->next; // Move to the next Node
            }
        }
    }

    // Assignment operator to perform a deep copy from another Menu

    Menu<ElementType> &operator=(const Menu<ElementType> &rightSide) {
        if (this != &rightSide) // Avoid self-assignment
        {
            // Clear existing content by deleting all Nodes
            while (firstNode) {
                Node *temp = firstNode; // Temporarily hold the current Node
                firstNode = firstNode->next; // Move to the next Node
                delete temp; // Deallocate memory
            }

            // Copy new content from the right-side Menu
            if (rightSide.firstNode) // If there are Nodes to copy
            {
                firstNode = new Node(rightSide.firstNode->data); // Initialize firstNode
                assert(firstNode != nullptr); // Ensure memory allocation

                Node *rightPtr = rightSide.firstNode->next; // Start copying
                Node *currentPtr = firstNode; // Pointer for the new Menu

                while (rightPtr) // Copy all Nodes
                {
                    currentPtr->next = new Node(rightPtr->data); // Create new Nodes
                    assert(currentPtr->next != nullptr); // Ensure memory allocation
                    currentPtr = currentPtr->next; // Move to the next Node
                    rightPtr = rightPtr->next; // Move to the next Node in the source
                }
                size = rightSide.size; // Update the size of the new Menu
            }
        }
        return *this; // Return the current object
    }

private:
    Node *firstNode; // Pointer to the first Node in the linked list
    int size; // The number of elements in the list
};

// Overload the stream insertion operator to display a Menu

template <typename ElementType>
ostream &operator<<(ostream &out, const Menu<ElementType> &menu) {
    menu.display(out); // Use the display method to output the Menu
    return out; // Return the output stream
}
/*----------------------------------------------------------------------
This function overloads the stream insertion operator (<<)
to allow printing the contents of a Menu object to an output stream.

Precondition: The Menu object exists and the output stream is valid.

Postcondition: The elements of the Menu are formatted and written
               to the output stream.
---------------------------------------------------------------------*/

#endif /* MENU_H */