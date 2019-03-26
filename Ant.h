/*********************************************************************
** Author: Adil Chaudhry
** Date: 1/7/2019
** Description: Class specification file defining the Ant class
*********************************************************************/

#ifndef LANGTONSANT_ANT_H
#define LANGTONSANT_ANT_H


class Ant {


private:

    int antDirection;
    int boardColor;
    int xCoord;
    int yCoord;

public:

    Ant();

    //Setter functions
    void setAntDirection(int direction);
    void setBoardColor(int color);
    void setXCoord(int x);
    void setYCoord(int y);


    //Getter functions
    int getBoardColor();
    int getXCoord();
    int getYCoord();
    int getAntDirection();

};





#endif //LANGTONSANT_ANT_H
