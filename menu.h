/** @file menu.h
 * @brief Header of UI class
 */

#ifndef MENU_H
#define MENU_H

#include "board.h"

#include <ctime>        //For clock()
#include <iostream>     //Idk what it does, I'm not programmer
#include <fstream>      //For ifstream

/**
 * @brief User interface class
 *
 * @warning This class needs board.h class
 */
class menu
{
public:
    /**
     * @brief Main program function
     *
     * Sets board, print menu options etc.
     */
    menu();

private:

    void mainMenu();

    void evolve();
    void printMenu();

    void settings();

    board *Brd;

};

#endif // MENU_H
