/** @file cell.h
 * @brief Headline file of class cell
 *
 * Cointains class constructor, destructor and some methods to modify the cell
 */



#ifndef CELL_H
#define CELL_H

/**
 * @brief Cell is object containing bool alive and 4 cell class pointers of its neighbours
 *
 * It's designed to make 4-way lists, for example game board. Cell can be dead (0) or alive (1).
 */
class cell
{
public:

    /**
     * @brief Switch cell statement from dead to alive or opposite way
     */
    void setAlive ();     //Switch if the cell is dead (0) or alive (1)

    /**
     * @brief Sets pointer Up
     * @param up Cell type pointer
     */
    void setUp (cell *up);      //Setting cell's neighbours

    /**
     * @brief Sets pointer Down
     * @param down Cell type pointer
     */
    void setDown (cell *down);

    /**
     * @brief Sets pointer Right
     * @param right Cell type pointer
     */
    void setRight (cell *right);

    /**
     * @brief Sets pointer Left
     * @param left Cell type pointer
     */
    void setLeft (cell *left);

    /**
     * @brief Returns statement of cell
     * @return Boolean, 0 if dead or 1 if alive
     */
    bool ifAlive ();        //Says if the cell is dead (0) or alive (1)

    /**
     * @brief Returns Up pointer
     * @return Cell pointer
     */
    cell *getUp();          //Getting cell's neighbours addresses

    /**
     * @brief Returns Down pointer
     * @return Cell pointer
     */
    cell *getDown();

    /**
     * @brief Returns Right pointer
     * @return Cell pointer
     */
    cell *getRight();

    /**
     * @brief Returns Left pointer
     * @return Cell pointer
     */
    cell *getLeft();

    /**
     * @brief Funcions return nu,ber of alive neighbours
     * @return Integer of alive neighbours
     */
    int neighboursAlive();     //Returns int of alive neighbours

private:
    bool alive = 0;
    cell *right = nullptr;
    cell *left = nullptr;
    cell *up = nullptr;
    cell *down = nullptr;

};

#endif // CELL_H
