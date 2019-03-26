/*********************************************************************
** Author: Adil Chaudhry
** Date: Late December
** Description: Class specification file for the Menu class
** Citation: Inspired by https://github.com/jessicaspeigel/cs162-fantasy-combat-game/blob/master/Menu.cpp
*********************************************************************/

#ifndef MENU_MENU_H
#define MENU_MENU_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Menu {

private:

    vector<string> menuOptions;
    string menuHeader;

public:

    //Constructor that takes a vector of menu options
    Menu(vector<string> newMenuOptions);

    //Constructor that takes a vector of menu options + allows you to set a menu text header
    Menu(string menuHeader, vector<string> newMenuOptions);

    //This function displays the menu options in the console. Returns an int so we can which choice the user selected
    int displayMenu();

    //Setter function that allows you to pass in a string of vector values as new menu options. We use this to update whats held in the private menuOptions vector
    void setMenuOptions(vector<string> newMenuOptions);

    //Setter function to set the header title that we want to display in our menu. Ex. OPTIONS MENU or SUB MENU etc
    void setMenuHeader(string t);

    //Returns the menu text header
    string getMenuHeader();

    //Displays the list of menu options
    void displayMenuOptions();

};


#endif //MENU_MENU_H
