/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: asus
 *
 * Created on April 25, 2024, 5:48 PM
 */
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include <time.h>

using namespace std;

// Header for the function that trims spaces before and after a string 
string trim(const string& str);

// Main function of the code 

int main(int argc, char** argv) {
    // Variable specifying if an admin or user is using the application
    char adminOrUser;

    // Variable representing the choice in the switch case
    int choice;

    // Variable indicating if the menu is modified 
    bool modifiedMenu = false;

    // Variable that will hold values for random numbers
    int nb = 0;

    /* Defining two arrays that will be holding pointers for objects of type Menu,
     * one for the main menu and the other for the vegan-vegetarian menu*/
    Menu<MenuItem> menuArray[4];
    Menu<MenuItem> veganMenu[4];

    // Defining a vector of type Item that will represent the special offer menu
    vector <MenuItem> specialOffer;
    
    /* Making the first element in the main menu pointing to the menu object that
     * will represent the appetizers in the menu*/
    menuArray[0] = Menu<MenuItem>();

    /* Making the second element in the main menu pointing to the menu object that
     * will represent the main dishesin the menu*/
    menuArray[1] = Menu<MenuItem>();

    /* Making the third element in the main menu pointing to the menu object that
     * will represent the desssers in the menu*/
    menuArray[2] = Menu<MenuItem>();

    /* Making the fourth position in the main menu pointing to the menu object that
     * will represent the beverages in the menu*/
    menuArray[3] = Menu<MenuItem>();

    // Opening the menuitems file to read from it
    ifstream inputFile("C:\\Users\\asus\\Desktop\\menuItems.txt");

    // Output file to write on
    ofstream outputFile;

    // If the initial menu items is not empty, enter to the if block
    if (inputFile.peek() != std::ifstream::traits_type::eof()) {
        
        // Opening the file to write the main menu on it
        outputFile.open("C:\\Users\\asus\\Desktop\\originalMenu.txt");
        
        string line;
        
        // While there is still lines remained in the file
        while (getline(inputFile, line)) {
            vector <string> substrings;

            stringstream ss(line);

            string token;

            while (getline(ss, token, ',')) {
                substrings.push_back(token);
            }

            vector <string> words;

            stringstream ss1(substrings[1]);

            string word;

            while (ss1 >> word) {
                words.push_back(word);
            }

            char cat = words[1][0];

            string name;
            char type;
            double price;
            vector <string> ingredients;

            time_t t;
            srand(time(&t));
            MenuItem item;
            switch (cat) {
                case 'a':
                    nb = rand() % 100 + 100;
                    while (menuArray[0].searchMenuItemById(nb)) {
                        nb = rand() % 100 + 100;
                    }

                    name = substrings[0];

                    if (words[0][0] == 'o') {
                        type = 'N';
                    }
                    if (words[0][0] == 'v') {
                        type = 'V';
                    }
                    if (words[0][0] == 'g') {
                        type = 'G';
                    }

                    price = stod(words[2]);

                    if (words.size() == 5) {
                        string firstIng;
                        firstIng = words[3] + " " + words.back();
                        ingredients.push_back(firstIng);
                    } else {
                        ingredients.push_back(words.back());
                    }

                    for (auto it = substrings.begin() + 2; it != substrings.end(); ++it) {
                        ingredients.push_back(*it);
                    }

                    item = MenuItem(nb, name, price, type, cat, ingredients);
                    menuArray[0].insertItem(item);
                    break;

                case 'm':
                    nb = rand() % 100 + 200;

                    while (menuArray[1].searchMenuItemById(nb)) {
                        nb = rand() % 100 + 200;
                    }

                    name = substrings[0];

                    if (words[0][0] == 'o') {
                        type = 'N';
                    }
                    if (words[0][0] == 'v') {
                        type = 'V';
                    }
                    if (words[0][0] == 'g') {
                        type = 'G';
                    }

                    price = stod(words[2]);

                    if (words.size() == 5) {
                        string firstIng;
                        firstIng = words[3] + " " + words.back();
                        ingredients.push_back(firstIng);
                    } else {
                        ingredients.push_back(words.back());
                    }

                    for (auto it = substrings.begin() + 2; it != substrings.end(); ++it) {
                        ingredients.push_back(*it);
                    }

                    item = MenuItem(nb, name, price, type, cat, ingredients);
                    menuArray[1].insertItem(item);
                    break;

                case 'd':
                    nb = rand() % 100 + 300;

                    while (menuArray[2].searchMenuItemById(nb)) {
                        nb = rand() % 100 + 300;
                    }

                    name = substrings[0];

                    if (words[0][0] == 'o') {
                        type = 'N';
                    }
                    if (words[0][0] == 'v') {
                        type = 'V';
                    }
                    if (words[0][0] == 'g') {
                        type = 'G';
                    }

                    price = stod(words[2]);

                    if (words.size() == 5) {
                        string firstIng;
                        firstIng = words[3] + " " + words.back();
                        ingredients.push_back(firstIng);
                    } else {
                        ingredients.push_back(words.back());
                    }

                    for (auto it = substrings.begin() + 2; it != substrings.end(); ++it) {
                        ingredients.push_back(*it);
                    }

                    item = MenuItem(nb, name, price, type, cat, ingredients);
                    menuArray[2].insertItem(item);
                    break;

                case 'b':
                    nb = rand() % 100 + 400;

                    while (menuArray[3].searchMenuItemById(nb)) {
                        nb = rand() % 100 + 400;
                    }

                    name = substrings[0];

                    if (words[0][0] == 'o') {
                        type = 'N';
                    }
                    if (words[0][0] == 'v') {
                        type = 'V';
                    }
                    if (words[0][0] == 'g') {
                        type = 'G';
                    }

                    price = stod(words[2]);

                    if (words.size() == 5) {
                        string firstIng;
                        firstIng = words[3] + " " + words.back();
                        ingredients.push_back(firstIng);
                    } else {
                        ingredients.push_back(words.back());
                    }

                    for (auto it = substrings.begin() + 2; it != substrings.end(); ++it) {
                        ingredients.push_back(*it);
                    }

                    item = MenuItem(nb, name, price, type, cat, ingredients);
                    menuArray[3].insertItem(item);
                    break;
            }
        }

        inputFile.close();

        outputFile << "The main menu have:\n";

        outputFile << "Appetizers:\n";
        outputFile << menuArray[0];
        outputFile << endl;

        outputFile << "Main Dishes:\n";
        outputFile << menuArray[1];
        outputFile << endl;

        outputFile << "Desserts:\n";
        outputFile << menuArray[2];
        outputFile << endl;

        outputFile << "Beverages:\n";
        outputFile << menuArray[3];
        outputFile << endl;

        outputFile.close();

        ofstream emptyTheFile("C:\\Users\\asus\\Desktop\\menuItems.txt", std::ios::trunc);

    } else {
        ifstream checkingFile("C:\\Users\\asus\\Desktop\\originalMenu.txt");
        string line;
        while (getline(checkingFile, line)) {
            if (line == "Appetizers:" || line == "Main Dishes:" || line == "Desserts:"
                    || line == "Beverages:" || line == "The main menu contains:" || line.empty()) {
                continue;
            }

            vector <string> substrings;

            stringstream ss(line);

            string token;

            while (getline(ss, token, ',')) {
                substrings.push_back(token);
            }

            int id;
            string name;
            char type;
            char cat;
            double price;
            vector <string> ing;
            MenuItem item;


            stringstream geek;
            geek << substrings[0];
            geek >> id;
            id = stoi(substrings[0]);

            switch (id / 100) {
                case 1:
                    name = trim(substrings[1]);
                    type = substrings[2][1];
                    cat = 'A';
                    price = stod(trim(substrings[3]));

                    for (auto it = substrings.begin() + 4; it != substrings.end(); ++it) {
                        ing.push_back(trim(*it));
                    }
                    item = MenuItem(id, name, price, type, cat, ing);
                    menuArray[0].insertItem(item);
                    break;
                case 2:
                    name = trim(substrings[1]);
                    type = substrings[2][1];
                    cat = 'M';
                    price = stod(trim(substrings[3]));

                    for (auto it = substrings.begin() + 4; it != substrings.end(); ++it) {
                        ing.push_back(trim(*it));
                    }
                    item = MenuItem(id, name, price, type, cat, ing);
                    menuArray[1].insertItem(item);
                    break;
                case 3:
                    name = trim(substrings[1]);
                    type = substrings[2][1];
                    cat = 'D';
                    price = stod(trim(substrings[3]));

                    for (auto it = substrings.begin() + 4; it != substrings.end(); ++it) {
                        ing.push_back(trim(*it));
                    }
                    item = MenuItem(id, name, price, type, cat, ing);
                    menuArray[2].insertItem(item);
                    break;
                case 4:
                    name = trim(substrings[1]);
                    type = substrings[2][1];
                    cat = 'B';
                    price = stod(trim(substrings[3]));

                    for (auto it = substrings.begin() + 4; it != substrings.end(); ++it) {
                        ing.push_back(trim(*it));
                    }
                    item = MenuItem(id, name, price, type, cat, ing);
                    menuArray[3].insertItem(item);
                    break;
            }
        }
    }

    int nb1 = 0;
    int nb2 = 0;
    int a[8];

    for (int i = 0; i < 4; ++i) {
        time_t t;
        srand(time(&t));

        nb1 = rand() % 100 + (100 * (i + 1));

        while (!menuArray[i].searchMenuItemById(nb1)) {
            nb1 = rand() % 100 + (100 * (i + 1));
        }

        nb2 = rand() % 100 + (100 * (i + 1));

        while (!menuArray[i].searchMenuItemById(nb2) || nb1 == nb2) {
            nb2 = rand() % 100 + (100 * (i + 1));
        }

        specialOffer.push_back(menuArray[i].searchGetItem(nb1));
        specialOffer.push_back(menuArray[i].searchGetItem(nb2));
    }

    for (int i = 0; i < 8; ++i) {
        a[i] = rand() % 6 + 3;
    }

    string password = "fadi";
    string passEnter = "";
    cout << "Enter U for user and A for admin:\n";
    cin >> adminOrUser;

    if (adminOrUser == 'a' || adminOrUser == 'A') {
        do {
            cout << "Please enter the password" << endl;
            cin >> passEnter;
            if (passEnter != password)
                cout << "Password is incorrect." << endl;
        } while (passEnter != password);

        bool found;
        MenuItem NewItem;

        do {
            cout << "\nWelcome dear admin to the menu application: " << endl;
            cout << "Please choose an option:" << endl;
            cout << "1: Insert item" << endl;
            cout << "2: Update item" << endl;
            cout << "3: Delete item" << endl;
            cout << "4: Display the original menu" << endl;
            cout << "5: Display the vegan/vegetarian menu" << endl;
            cout << "6: Exit Program" << endl << endl;
            cout << "Enter your choice: ";

            cin >> choice;

            switch (choice) {
                case 1:
                    time_t t;
                    srand(time(&t));
                    cout << "Input the item to insert: " << endl;
                    cin >> NewItem;
                    found = true;
                    modifiedMenu = false;
                    if (NewItem.getItemCategory() == 'A') {
                        found = menuArray[0].searchMenuItemById(NewItem.getItemId());
                        while (found) {
                            nb = rand() % 100 + 100;
                            NewItem.setItemId(nb);
                            cout << endl << nb << endl;
                            found = false;
                            found = menuArray[0].searchMenuItemById(NewItem.getItemId());
                        }

                        menuArray[0].insertItem(NewItem);
                        modifiedMenu = true;


                    } else if (NewItem.getItemCategory() == 'M') {
                        found = menuArray[1].searchMenuItemById(NewItem.getItemId());
                        while (found) {
                            nb = rand() % 100 + 200;
                            NewItem.setItemId(nb);
                            cout << endl << nb << endl;
                            found = false;
                            found = menuArray[1].searchMenuItemById(NewItem.getItemId());
                        }

                        menuArray[1].insertItem(NewItem);
                        modifiedMenu = true;
                    } else if (NewItem.getItemCategory() == 'D') {
                        found = menuArray[2].searchMenuItemById(NewItem.getItemId());
                        while (found) {
                            nb = rand() % 100 + 300;
                            NewItem.setItemId(nb);
                            cout << endl << nb << endl;
                            found = false;
                            found = menuArray[2].searchMenuItemById(NewItem.getItemId());
                        }

                        menuArray[2].insertItem(NewItem);
                        modifiedMenu = true;
                    } else if (NewItem.getItemCategory() == 'B') {
                        found = menuArray[3].searchMenuItemById(NewItem.getItemId());
                        while (found) {
                            nb = rand() % 100 + 400;
                            NewItem.setItemId(nb);
                            cout << endl << nb << endl;
                            found = false;
                            found = menuArray[3].searchMenuItemById(NewItem.getItemId());
                        }

                        menuArray[3].insertItem(NewItem);
                        modifiedMenu = true;

                        cout << "\nNew item added to the menu successfully." << endl;
                    } else {
                        cout << "Item already exists. ID can not be duplicated." << endl;
                    }
                    break;

                case 2:
                    int idUpdate;
                    cout << "\nUpdate item" << endl;
                    cout << "Enter element ID: ";
                    cin >> idUpdate;
                    found = false;
                    modifiedMenu = false;
                    if (idUpdate <= 499 && idUpdate >= 100) {
                        switch (idUpdate / 100) {
                            case 1:
                                found = menuArray[0].searchMenuItemById(idUpdate);
                                if (found) {
                                    cout << "Input the item to update: " << endl;
                                    cin >> NewItem;
                                    NewItem.setItemId(idUpdate);
                                    menuArray[0].deleteMenuItemById(idUpdate);
                                    menuArray[0].insertItem(NewItem);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully updated." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            case 2:
                                found = menuArray[1].searchMenuItemById(idUpdate);
                                if (found) {
                                    cout << "Input the item to update: " << endl;
                                    cin >> NewItem;
                                    NewItem.setItemId(idUpdate);
                                    menuArray[1].deleteMenuItemById(idUpdate);
                                    menuArray[1].insertItem(NewItem);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully updated." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            case 3:
                                found = menuArray[2].searchMenuItemById(idUpdate);
                                if (found) {
                                    cout << "Input the item to update: " << endl;
                                    cin >> NewItem;
                                    NewItem.setItemId(idUpdate);
                                    menuArray[2].deleteMenuItemById(idUpdate);
                                    menuArray[2].insertItem(NewItem);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully updated." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            case 4:
                                found = menuArray[3].searchMenuItemById(idUpdate);
                                if (found) {
                                    cout << "Input the item to update: " << endl;
                                    cin >> NewItem;
                                    NewItem.setItemId(idUpdate);
                                    menuArray[3].deleteMenuItemById(idUpdate);
                                    menuArray[3].insertItem(NewItem);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully updated." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            default:
                                cout << "Element ID not found.";
                                break;
                        }
                    }
                    break;
                case 3:
                    int id;
                    cout << "\nDelete item" << endl;
                    cout << "Enter element ID: ";
                    cin >> id;
                    found = false;
                    modifiedMenu = false;
                    if (id <= 499 && id >= 100) {
                        switch (id / 100) {
                            case 1:
                                found = menuArray[0].searchMenuItemById(id);
                                if (found) {
                                    menuArray[0].deleteMenuItemById(id);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully deleted." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            case 2:
                                found = menuArray[1].searchMenuItemById(id);
                                if (found) {
                                    menuArray[1].deleteMenuItemById(id);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully deleted." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            case 3:
                                found = menuArray[2].searchMenuItemById(id);
                                if (found) {
                                    menuArray[2].deleteMenuItemById(id);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully deleted." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            case 4:
                                found = menuArray[3].searchMenuItemById(id);
                                if (found) {
                                    menuArray[3].deleteMenuItemById(id);
                                    modifiedMenu = true;
                                    cout << "\nItem successfully deleted." << endl;
                                } else {
                                    cout << "Element ID not found." << endl;
                                }
                                break;
                            default:
                                cout << "Element ID not found.";
                                break;
                        }
                    }
                    break;
                case 4:
                    outputFile.open("C:\\Users\\asus\\Desktop\\originalMenu.txt");

                    outputFile << "The main menu contains:\n";

                    outputFile << "Appetizers:\n";
                    outputFile << menuArray[0];
                    outputFile << endl;

                    outputFile << "Main Dishes:\n";
                    outputFile << menuArray[1];
                    outputFile << endl;

                    outputFile << "Desserts:\n";
                    outputFile << menuArray[2];
                    outputFile << endl;

                    outputFile << "Beverages:\n";
                    outputFile << menuArray[3];
                    outputFile << endl;

                    outputFile.close();

                    system("start C:\\Users\\asus\\Desktop\\originalMenu.txt");
                    break;
                case 5:
                    veganMenu[0] = (menuArray[0].searchByElementType());

                    veganMenu[1] = (menuArray[1].searchByElementType());

                    veganMenu[2] = (menuArray[2].searchByElementType());

                    veganMenu[3] = (menuArray[3].searchByElementType());

                    outputFile.open("C:\\Users\\asus\\Desktop\\VeganMenu.txt");

                    outputFile << "The vegan-vegetarian menu contains:\n";
                    outputFile << "Appetizers:\n" << veganMenu[0];
                    outputFile << "\nMain Dishes:\n" << veganMenu[1];
                    outputFile << "\nDesserts:\n" << veganMenu[2];
                    outputFile << "\nBeverages:\n" << veganMenu[3];

                    outputFile.close();

                    system("start C:\\Users\\asus\\Desktop\\VeganMenu.txt");

                    break;
                case 6:
                    if (modifiedMenu) {
                        outputFile.open("C:\\Users\\asus\\Desktop\\originalMenu.txt");

                        outputFile << "The main menu contains:\n";

                        outputFile << "Appetizers:\n";
                        outputFile << menuArray[0];
                        outputFile << endl;

                        outputFile << "Main Dishes:\n";
                        outputFile << menuArray[1];
                        outputFile << endl;

                        outputFile << "Desserts:\n";
                        outputFile << menuArray[2];
                        outputFile << endl;

                        outputFile << "Beverages:\n";
                        outputFile << menuArray[3];
                        outputFile << endl;

                        outputFile.close();
                    }
                    cout << "Thank you Admin." << endl;
                    break;
                default:
                    cout << "Please enter a valid choice." << endl;
            }
        } while (choice != 6);
    } else {
        ofstream bill;
        ofstream outputFile;
        double totalToPay = 0;
        int item;
        MenuItem orderedItem;
        int qte;
        int nb = 0;
        do {
            cout << "\nWelcome to our Menu" << endl;
            cout << "Please choose an option:" << endl;
            cout << "1: Display the original menu" << endl;
            cout << "2: Display the vegan/vegetarian menu" << endl;
            cout << "3: Display special offer menu" << endl;
            cout << "4: Place order" << endl;
            cout << "5: Exit Program" << endl << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    system("start C:\\Users\\asus\\Desktop\\originalMenu.txt");
                    break;
                case 2:
                    veganMenu[0] = (menuArray[0].searchByElementType());

                    veganMenu[1] = (menuArray[1].searchByElementType());

                    veganMenu[2] = (menuArray[2].searchByElementType());

                    veganMenu[3] = (menuArray[3].searchByElementType());

                    outputFile.open("C:\\Users\\asus\\Desktop\\VeganMenu.txt");

                    outputFile << "The vegan-vegetarian menu contains:\n";
                    outputFile << "Appetizers:\n" << veganMenu[0];
                    outputFile << "Main Dishes:\n" << veganMenu[1];
                    outputFile << "Desserts:\n" << veganMenu[2];
                    outputFile << "Beverages:\n" << veganMenu[3];

                    outputFile.close();

                    system("start C:\\Users\\asus\\Desktop\\VeganMenu.txt");

                    break;
                case 3:
                    outputFile.open("C:\\Users\\asus\\Desktop\\specialOffer.txt");

                    nb = 0;

                    for (auto it = specialOffer.begin(); it != specialOffer.end(); ++it) {
                        if (nb == 0) {
                            outputFile << "Appetizers:" << endl;
                        }
                        if (nb == 2) {
                            outputFile << "Main Dishes:" << endl;
                        }
                        if (nb == 4) {
                            outputFile << "Desserts:" << endl;
                        }
                        if (nb == 6) {
                            outputFile << "Beverages:" << endl;
                        }

                        outputFile << (*it).getItemId() << ", " << (*it).getItemName() << endl;
                        outputFile << "After discount: " << (*it).getItemPrice() * 0.7 << endl;
                        outputFile << "Qunatity: " << a[nb++] << endl << endl;
                    }

                    outputFile.close();

                    system("start C:\\Users\\asus\\Desktop\\specialOffer.txt");

                    break;
                case 4:
                    int menunb;
                    cout << "\nEnter the number of the menu you like to order from\n"
                            << "1 for the main menu, 2 for vegan/vegetarian menu,"
                            << "3 for special offer, and 0 to exit: ";
                    cin >> menunb;
                    cout << endl;
                    bill.open("C:\\Users\\asus\\Desktop\\bill.txt");
                    bill.clear();
                    bill << "You ordered:" << endl;
                    while (menunb != 0) {
                        if (menunb == 1 || menunb == 2) {
                            if (menunb == 1) {
                                system("start C:\\Users\\asus\\Desktop\\originalMenu.txt");
                            } else {
                                veganMenu[0] = (menuArray[0].searchByElementType());

                                veganMenu[1] = (menuArray[1].searchByElementType());

                                veganMenu[2] = (menuArray[2].searchByElementType());

                                veganMenu[3] = (menuArray[3].searchByElementType());

                                outputFile.open("C:\\Users\\asus\\Desktop\\VeganMenu.txt");

                                outputFile << "Appetizers:\n" << veganMenu[0];
                                outputFile << "Main Dishes:\n" << veganMenu[1];
                                outputFile << "Desserts:\n" << veganMenu[2];
                                outputFile << "Beverages:\n" << veganMenu[3];

                                outputFile.close();

                                system("start C:\\Users\\user\\Desktop\\VeganMenu.txt");
                            }

                            cout << "Enter the item ID you wish to order, 0 to quit: " << endl;
                            cin >> item;

                            while (item != 0) {
                                if (menuArray[0].searchMenuItemById(item)) {
                                    orderedItem = menuArray[0].searchGetItem(item);
                                } else if (menuArray[1].searchMenuItemById(item)) {
                                    orderedItem = menuArray[1].searchGetItem(item);
                                } else if (menuArray[2].searchMenuItemById(item)) {
                                    orderedItem = menuArray[2].searchGetItem(item);
                                } else if (menuArray[3].searchMenuItemById(item)) {
                                    orderedItem = menuArray[3].searchGetItem(item);
                                } else {
                                    cout << "\nItem not found, enter ID again, 0 to quit: ";
                                    cin >> item;
                                    continue;
                                }

                                cout << "\nEnter the quantity of " << orderedItem.getItemName() << ": ";
                                cin >> qte;

                                while (qte <= 0) {
                                    cout << "\nQuantity must be greater than zero, enter it again: ";
                                    cin >> qte;
                                }

                                totalToPay += qte * orderedItem.getItemPrice();
                                bill << qte << " " << orderedItem.getItemName() << " for " << qte * orderedItem.getItemPrice() << "$" << endl;

                                cout << "\nEnter the item ID you wish to add to the order, 0 to quit: " << endl;
                                cin >> item;
                            }
                        } else if (menunb == 3) {
                            outputFile.open("C:\\Users\\asus\\Desktop\\specialOffer.txt");

                            nb = 0;

                            for (auto it = specialOffer.begin(); it != specialOffer.end(); ++it) {
                                if (nb == 0) {
                                    outputFile << "Appetizers:" << endl;
                                }
                                if (nb == 2) {
                                    outputFile << "Main Dishes:" << endl;
                                }
                                if (nb == 4) {
                                    outputFile << "Desserts:" << endl;
                                }
                                if (nb == 6) {
                                    outputFile << "Beverages:" << endl;
                                }

                                outputFile << (*it).getItemId() << ", " << (*it).getItemName() << endl;
                                outputFile << "After discount: " << (*it).getItemPrice() * 0.7 << endl;
                                outputFile << "Quantity: " << a[nb++] << endl << endl;
                            }

                            outputFile.close();

                            system("start C:\\Users\\asus\\Desktop\\specialOffer.txt");
                            cout << "Enter the item ID you wish to order, 0 to quit: " << endl;

                            cin >> item;

                            while (item != 0) {
                                int i = 0;
                                while (i < 8) {
                                    if (specialOffer[i].getItemId() == item)
                                        break;
                                    i++;
                                }
                                if (i < 8) {
                                    cout << "Enter the quantity of " << specialOffer[i].getItemName() << ": ";
                                    cin >> qte;
                                    while (qte <= 0) {
                                        cout << "\nQuantity must be greater than zero, enter it again: ";
                                        cin >> qte;
                                    }
                                    if (qte <= a[i]) {
                                        totalToPay += qte * specialOffer[i].getItemPrice() * 0.7;
                                        bill << qte << " " << specialOffer[i].getItemName() << " in offer, for " << qte * specialOffer[i].getItemPrice() * 0.7 << "$" << endl;
                                        a[i] = a[i] - qte;
                                        if (a[i] == 0) {
                                            nb = rand() % 100 + (((i / 2) + 1) * 100);
                                            if (i % 2 == 0) {
                                                while (!menuArray[i / 2].searchMenuItemById(nb) || specialOffer[i + 1].getItemId() == nb) {
                                                    nb = rand() % 100 + (((i / 2) + 1) * 100);
                                                }
                                            } else {
                                                while (!menuArray[i / 2].searchMenuItemById(nb) || specialOffer[i - 1].getItemId() == nb) {
                                                    nb = rand() % 100 + (((i / 2) + 1) * 100);
                                                }
                                            }
                                            specialOffer[i] = menuArray[i / 2].searchGetItem(nb);
                                            a[i] = rand() % 6 + 3;
                                        }

                                    } else {
                                        cout << "\nNot Enough quantity";
                                    }
                                }
                                cout << "\nEnter the item ID you wish to add to the order, 0 to quit: " << endl;
                                cin >> item;
                            }
                        }

                        cout << "\nEnter the number of the menu you like to order from\n"
                                << "1 for the main menu, 2 for vegan/vegetarian menu,"
                                << "3 for special offer, and 0 to exit: ";

                        cin >> menunb;
                    }

                    bill << "\nTotal to pay: " << totalToPay << "$";
                    bill.close();
                    system("start C:\\Users\\asus\\Desktop\\bill.txt");
                    break;
                case 5:
                    if (totalToPay != 0) {
                        cout << "\nYour food is being prepared." << endl;
                    } else {
                        cout << "\nThank you for visiting." << endl;
                    }
                    break;
                default:
                    cout << "\nPlease enter a valid choice." << endl;
                    break;
            }

        } while (choice != 5);
        cout << "\nThank you for using this program.";
    }
    return 0;
}

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos) {
        // If the string consists only of spaces, return an empty string
        return "";
    } else {
        // Extract the substring containing non-space characters
        return str.substr(start, end - start + 1);
    }
}