/** @file board.h
 * @brief Headline file of class board
 *
 * Cointains constructor, destructor ans some methods to modify the Board
 */

#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

#include <string>

/**
 * @brief The board class is made of cells which may be dead or alive
 *
 * Technically, it's 4-way list made by cell class objects. Ever cell has it's own (x,y) coords counted from 0 and can be dead (0) or alive (1). You can make many different boards at the same time
 * @warning The class wouldn't work without cell.h
 */


class board
{
public:
    /**
     * @brief makeBoard
     *
     * Class constructor
     */
    void makeBoard();                   //Class constructor

    /**
     * @brief deleteBoard
     *
     * Class destructor
     */

    void deleteBoard();                 //Class destructor

    /**
     * @brief printBoard
     *
     * Prints on console existing board
     */

    void printBoard();                  //Prints board

    /**
     * @brief Funtion switch cells statement from dead to alive or opposite way
     * @param x X coord of choosen cell
     * @param y Y coord of choosen cell
     */
    void setAlive(int x, int y);        ///Sets if chosen cell is alive (1) or dead (0)

    /**
     * @brief Function return if the cell  is alive (1) or dead (0)
     * @param x X coord of choosen cell
     * @param y Y coord of choosen cell
     * @return Returns boolean 0 if cell is dead or 1 if alive
     */
    bool getAlive(int x, int y);        ///Returns if chosen cell is alive (1) or dead (0)

    /**
     * @brief Returns actual height of board
     * @return Integer equal to board height
     */
    int getHeight() const;              ///Returns board's height

    /**
     * @brief Funtion asks user for wanted board height and sets it
     */
    void setHeight();                   ///Sets board's height

    /**
     * @brief Function returns actual width of board
     * @return Integer equal to board width
     */
    int getWidth() const;               ///Returns board's width

    /**
     * @brief Funtion asks user for wanted board width and sets it
     */
    void setWidth();                    ///Sets board's width

    /**
     * @brief Function returns address of first cell (coords 0,0)
     * @return Cell class address
     */
    cell *getUpLeft() const;            ///Returns address of first cell

    /**
     * @brief Funtion adds new column to existing board at the front or end
     * @param place Switch for place for new column. 0 adds at the front, 1 at the end
     */
    void addColumn(bool place);         ///Adds first (0) or last (1) column

    /**
     * @brief Deletes first or last column of board
     * @param place Switch for first (0) or last (1) column
     */
    void deleteColumn(bool place);      ///Deletes first (0) or last (1) column

    /**
     * @brief Funtion adds new line to existing board at the front or end
     * @param place Switch for place for new line. 0 adds at the front, 1 at the end
     */
    void addLine(bool place);           ///Adds first (0) or last (1) line

    /**
     * @brief Deletes first or last line of board
     * @param place Switch for first (0) or last (1) line
     */
    void deleteLine(bool place);        ///Deletes first (0) or last (1) line

    /**
     * @brief Funtion evolve board by one generation
     */
    void nextGen();

    /**
     * @brief Funtion returns actuall gamerule
     * @return String XXX/YYY
     */
    std::string getGameRule() const;    //Returns game rule

    /**
     * @brief Funtions change gamerule
     * @param value Must be string cointaining only digits and one '/'
     */
    void setGameRule(const std::string &value); //Modify game rule

    /**
     * @brief Funtions reurns number of neighbors alive
     * @param x X coord of cell
     * @param y Y coord of cell
     * @return Integer equal to number of neighbors alive
     */
    int neibAlive(int x, int y);        //Returns alive parameter from cords cell

    /**
     * @brief Checks, if there any alive cells on board's borders, then adds new columns or lines to avoid getting alive cells outta map
     */
    void border();                      //Adds new line/border if any cell on border is alive

private:
    int maxHeight = 16;  //Max height of board
    int maxWidth = 16;    //Max width of board
    int minHeight = 3;    //Min height of board
    int minWidth = 3;     //Min width of board

    int height;                 //Current board heigh
    int width;                  //Current board width

    std::string gameRule = "23/3";

    cell *upLeft;               //Addres of first cell

    struct List {
        int x;
        int y;
        List *next;
    };

    void listAdd(List *value, int x, int y);

};

#endif // BOARD_H
