#include "cell.h"


int cell::neighboursAlive()
{
    cell *tmp = this,
            *neigh;
    int n = 0;

    neigh = tmp->getUp();

    if(neigh != nullptr) {

        n += neigh->ifAlive();

        if(neigh->getRight() != nullptr) {
            neigh = neigh->getRight();
            n += neigh->ifAlive();
        }
    }

    neigh = tmp->getDown();

    if( neigh != nullptr) {
        n += neigh->ifAlive();

        if(neigh->getLeft() != nullptr) {
            neigh = neigh->getLeft();
            n += neigh->ifAlive();
        }
    }


    neigh = tmp->getLeft();

    if(neigh != nullptr) {
        n +=neigh->ifAlive();

        if(neigh->getUp() != nullptr) {
            neigh = neigh->getUp();
            n += neigh->ifAlive();
        }
    }

    neigh = tmp->getRight();

    if(neigh != nullptr) {
        n +=neigh->ifAlive();

        if(neigh->getDown() != nullptr) {
            neigh = neigh->getDown();
            n += neigh->ifAlive();
        }

    }
    return n;

}

void cell::setAlive()
{
    this -> alive = !this->alive;
}

void cell::setUp(cell *up)
{
    this -> up = up;
}

void cell::setDown(cell *down)
{
    this -> down = down;
}

void cell::setRight(cell *right)
{
    this -> right = right;
}

void cell::setLeft(cell *left)
{
    this -> left = left;
}

bool cell::ifAlive()
{
    return this -> alive;
}

cell *cell::getUp()
{
    return this -> up;
}

cell *cell::getDown()
{
    return this -> down;
}

cell *cell::getRight()
{
    return this -> right;
}

cell *cell::getLeft()
{
    return this -> left;
}
