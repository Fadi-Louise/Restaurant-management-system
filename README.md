# Restaurant Menu Management System

## Project Overview
This C++ project implements a restaurant menu management system that allows both administrators and regular users to interact with restaurant menus. The system uses a linked list-based data structure to store and manage menu items, offering different functionalities depending on the user type.

## Features

### Administrator Features
- **Authentication**: Secure access with password protection.
- **Menu Management**:
  - Insert new menu items with details (name, price, type, category, ingredients).
  - Update existing menu items by ID.
  - Delete menu items by ID.
- **Menu Display**:
  - View complete menu with all items.
  - View specialized vegetarian/vegan menu.

### Customer Features
- **Menu Browsing**:
  - View the complete restaurant menu.
  - View specialized vegetarian/vegan menu.
  - View special offers with discounted items.
- **Order Placement**:
  - Select items from any menu.
  - Specify quantities for each item.
  - View generated bill with order details and total cost.

## Technical Implementation

### Data Structures
- **Custom templated `Menu<T>` class** implementing a linked list.
- **`MenuItem` class** with properties for food/beverage items.

### File Operations
- Reads menu data from text files.
- Writes menus and orders to output files.

### Memory Management
- Proper dynamic memory allocation.
- Deep copying for object duplication.

## Menu Item Categories
- **Appetizers** (IDs 100-199)
- **Main Dishes** (IDs 200-299)
- **Desserts** (IDs 300-399)
- **Beverages** (IDs 400-499)

## Menu Item Types
- **N**: Normal items
- **V**: Vegetarian items
- **G**: Vegan items

## Usage
1. **Run the application**.
2. **Select user type**:
   - Administrator (A): Requires password (default: "fadi").
   - Customer (U): No authentication required.
3. **Follow on-screen prompts** to navigate through available options.

## Output Files
The program generates several output files:
- `originalMenu.txt`: Complete menu listing.
- `VeganMenu.txt`: Filtered vegetarian/vegan options.
- `specialOffer.txt`: Discounted menu items.
- `bill.txt`: Customer order details and total.

## Build Instructions
The project uses a standard C++ build system with MinGW on Windows:

### Project Structure
- `main.cpp`: Main application logic and user interface.
- `MenuItem.h` & `MenuItem.cpp`: Menu item class definition and implementation.
- `Menu.h`: Templated linked list implementation for menu management.

© 2023 Fadi Louise. All Rights Reserved.
