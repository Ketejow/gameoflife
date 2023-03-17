
#include "board.h"

#include <iostream>


void board::makeBoard()
{
    using namespace std;

    int width = this->getWidth();
    int height = this->getHeight();
    this->upLeft = new cell;

    if(width > this->maxWidth || height > this->maxHeight) {
        cout << "Error." << endl << "Chosen board is too big" << endl << "Max height is " << maxHeight << ". Max width is " << maxWidth << "." << endl;
        return;
    }


    cell *tmp = this->upLeft, *prev;

    for (int i = 1; i < width; i++) {   //Makes first line of board
        prev = tmp;
        tmp = new cell;
        prev->setRight(tmp);
        tmp->setLeft(prev);
    }

    int x, y;

    x = 0;
    y = 1;

    cell *upper;
    cell *firstOfLine;
    upper = this->upLeft;

    while(y < height) {                 //Makes lines no 1+

        x = 1;
        upper->setDown(new cell);
        tmp = upper->getDown();
        tmp->setUp(upper);
        firstOfLine = tmp;

        while(x < width) {
            tmp->setRight(new cell);

            prev = tmp;
            tmp = tmp->getRight();
            upper = upper->getRight();

            tmp->setUp(upper);
            upper->setDown(tmp); 
            prev->setRight(tmp);
            tmp->setLeft(prev);
            x++;
        }

        upper = firstOfLine;

        y++;
    }

}

void board::deleteBoard()       //Deletes board
{
    cell *tmp = this->upLeft,   //Temporary references
            *nextLine,
            *toDelete;

    int i = 0;

    nextLine = tmp->getDown();

    while (i < this->height) {

        toDelete = tmp;

        tmp = toDelete->getRight();


        if (tmp == nullptr) {
            tmp = nextLine;
            nextLine = nextLine->getDown();
        }

        delete toDelete;

        i++;

    }
}

void board::printBoard()    //Prints board on console
{
    using namespace std;

    cell *tmp = this->upLeft;
    cell *prev = tmp;
    int i = 0;

    cout << endl << "\t";

    while ( i < this->width) {
        cout << i << "\t";
        i++;
    }

    i = 0;

    cout << endl << i << "|\t";

    while (tmp != nullptr) {
        cout << tmp->ifAlive() << "\t";
        tmp = tmp->getRight();
        if (tmp == nullptr) {
            i++;
            if(i >= this->height) break;
            cout << endl << i << "|\t";
            tmp = prev->getDown();
            prev = tmp;
        }
        if(tmp == nullptr) break;
    }

    delete tmp;
    cout << endl;
}

void board::setAlive(int x, int y)
{
    if(x >= this->width || y >= this->height) {
        std::cout << "This cell doesn't exist!" << std::endl;
        return;
    }

    cell *tmp = this->upLeft;
    int i = 0;

    while (i < x) {
        tmp = tmp->getRight();
        i++;
    }

    i = 0;

    while (i < y) {
        tmp = tmp->getDown();
        i++;
    }

    tmp->setAlive();

}

bool board::getAlive(int x, int y)
{
    if(x >= this->width || y >= this->height || y < 0 || x < 0) {
        return 0;
    }

    cell *tmp = this->upLeft;
    int i = 0;

    while (i < x) {
        tmp = tmp->getRight();
        i++;
    }

    i = 0;

    while (i < y) {
        tmp = tmp->getDown();
        i++;
    }
    return tmp->ifAlive();

}

int board::getWidth() const
{
    return width;
}

void board::setWidth()
{
    using namespace std;

    int max = maxWidth;
    int value;

    do {
        cout << "Enter width smaller than " << max << ":" << endl;
        cin >> value;

    } while (value < minWidth || value > max);

    width = value;
}

int board::getHeight() const
{
    return height;
}

void board::setHeight()
{
    using namespace std;

    int max = this->maxHeight;
    int value;

    do {
        cout << "Enter height smaller than " << max << ":" << endl;
        cin >> value;

    } while (value < this->minHeight || value > max);

    height = value;
}

cell *board::getUpLeft() const
{
    return upLeft;
}

void board::addColumn(bool place)
{
    cell *tmp = this->upLeft,
            *prev,
            *tmp1;

    if(!place) {

        this->upLeft = new cell;
        this->upLeft->setRight(tmp);

        tmp->setLeft(this->upLeft);

        prev = this->upLeft;

        tmp = tmp->getDown();

        while (tmp != nullptr) {

            tmp1 = new cell;

            tmp1->setUp(prev);
            prev->setDown(tmp1);

            tmp1->setRight(tmp);
            tmp->setLeft(tmp1);

            prev = tmp1;
            tmp = tmp->getDown();
        }

        this->width++;

    } else {

        while (tmp->getRight() != nullptr) tmp = tmp->getRight();

        prev = new cell;

        tmp->setRight(prev);

        prev->setLeft(tmp);

        tmp = tmp->getDown();

        while (tmp != nullptr) {

            tmp1 = new cell;

            tmp1->setUp(prev);
            prev->setDown(tmp1);

            tmp1->setLeft(tmp);
            tmp->setRight(tmp1);

            prev = tmp1;
            tmp = tmp->getDown();
        }
        this->width++;
    }


}

void board::deleteColumn(bool place)
{
    cell *tmp = this->upLeft,
            *toDelete;

    if(!place) {
        this->upLeft = tmp->getRight();

        do {

        toDelete = tmp;

        tmp = tmp->getDown();

        delete toDelete;

        } while (tmp != nullptr);

        this->width--;

    } else {

        while (tmp->getRight() != nullptr) tmp = tmp->getRight();

        do {

        toDelete = tmp;

        tmp = tmp->getDown();

        delete toDelete;

        } while (tmp != nullptr);

        this->width--;
    }
}

void board::addLine(bool place)
{
    cell *tmp = this->upLeft,
            *prev,
            *tmp1;

    if(!place) {

        this->upLeft = new cell;
        this->upLeft->setDown(tmp);

        tmp->setUp(this->upLeft);

        prev = this->upLeft;

        tmp = tmp->getRight();

        while (tmp != nullptr) {

            tmp1 = new cell;

            tmp1->setLeft(prev);
            prev->setRight(tmp1);

            tmp1->setDown(tmp);
            tmp->setUp(tmp1);

            prev = tmp1;
            tmp = tmp->getRight();
        }

        this->height++;

    } else {

        while (tmp->getDown() != nullptr) tmp = tmp->getDown();

        prev = new cell;

        tmp->setDown(prev);

        prev->setUp(tmp);

        tmp = tmp->getRight();

        while (tmp != nullptr) {

            tmp1 = new cell;

            tmp1->setLeft(prev);
            prev->setRight(tmp1);

            tmp1->setUp(tmp);
            tmp->setDown(tmp1);

            prev = tmp1;
            tmp = tmp->getRight();
        }
        this->height++;
    }
}

void board::deleteLine(bool place)
{
    cell *tmp = this->upLeft,
            *toDelete;

    if(!place) {
        this->upLeft = tmp->getDown();

        do {

        toDelete = tmp;

        tmp = tmp->getRight();

        delete toDelete;

        } while (tmp != nullptr);

        this->height--;

    } else {

        while (tmp->getDown() != nullptr) tmp = tmp->getDown();

        do {

        toDelete = tmp;

        tmp = tmp->getRight();

        delete toDelete;

        } while (tmp != nullptr);

        this->height--;
    }
}

void board::nextGen()
{
    border();

    cell *tmp = this->upLeft,
            *prev = tmp;

    List *toChange = new List,
            *toDelete;

    toChange->next = nullptr;


    int x = 0, y = 0;

    while(tmp !=nullptr) {      //Checks board's cells Moore's neighbourship and adds to change list
        prev = tmp->getDown();

        while(tmp != nullptr) {

            int i = 0;
            char digit, friends;
            int n = tmp->neighboursAlive();

            if(tmp->ifAlive()) {

                bool change = 1;

                do {
                    digit = gameRule.at(i);
                    friends = (char) (n + '0');
                    if(digit == friends) change = 0;
                    i++;

                } while (digit != '/');

                if (change) {
                    listAdd(toChange, x, y);
                }

            } else {
                while (gameRule.at(i) != '/') i++;
                i++;
                do {
                    digit = gameRule.at(i);
                    friends = (char) (n + '0');
                    if(digit == friends) {
                        listAdd(toChange, x, y);
                    }
                    i++;

                } while (i < (int) gameRule.size());

            }

            tmp = tmp->getRight();

            x++;
        }
        tmp = prev;

        x=0;
        y++;
    }

    toDelete = toChange;
    toChange = toChange->next;

    delete toDelete;

    while (toChange != nullptr) {

        int x, y;

        toDelete = toChange;
        toChange = toChange->next;

        x = toDelete->x;
        y = toDelete->y;

        setAlive(x, y);

        delete toDelete;
    }


}

std::string board::getGameRule() const
{
    return gameRule;
}

void board::setGameRule(const std::string &value)
{
    gameRule = value;
}

int board::neibAlive(int x, int y)
{
    if(x >= this->width || y >= this->height || y < 0 || x < 0) {
        return 0;
    }

    cell *tmp = this->upLeft;
    int i = 0;

   // std::cout << tmp << std::endl;
    while (i > x) {
        tmp = tmp->getRight();
        i++;
    }

    //std::cout << tmp << std::endl;

    i = 0;

    while (i > y) {
        tmp = tmp->getDown();
        i++;
    }

    //1std::cout << tmp << std::endl;

    return tmp->neighboursAlive();
}

void board::border()
{
    cell *tmp = this->upLeft;

    bool change = 0;

    while(tmp->getRight() != nullptr) {
        change += tmp->ifAlive();
        tmp = tmp->getRight();
    }

    if(change) addLine(0);

    change = 0;

    while(tmp->getDown() != nullptr) {
        change += tmp->ifAlive();
        tmp = tmp->getDown();
    }

    if(change) addColumn(1);

    change = 0;

    while(tmp->getLeft() != nullptr) {
        change += tmp->ifAlive();
        tmp = tmp->getLeft();
    }

    if(change) addLine(1);

    change = 0;

    while(tmp->getUp() != nullptr) {
        change += tmp->ifAlive();
        tmp = tmp->getUp();
    }

    if(change) addColumn(0);
}


void board::listAdd(board::List *value, int x, int y)
{

        List *tmp = new List;
        List *prev;

        prev = value;

        while(prev->next != nullptr) prev = prev->next;

        prev->next = tmp;
        tmp->x = x;
        tmp->y = y;
        tmp->next = nullptr;

}
