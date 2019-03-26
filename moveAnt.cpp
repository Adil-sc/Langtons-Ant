/*********************************************************************
** Author: Adil Chaudhry
** Date: 1/7/2019
** Description: .cpp file that contains code to make the Ant move on the board.
*********************************************************************/

#include "moveAnt.h"
#include <iostream>

using std::cout;

//Takes as paramaters a 2d array, the row and col size of the grid, the ants direction, and an ant object. It uses this data to make the ant move grid positions on the array
void moveAnt(char **ary, int row, int col, int &antDirection, Ant &myAnt) {

    //Get the current color of the board
    int boardColor = myAnt.getBoardColor();
    //Get the ants current X coord
    int antPosX = myAnt.getXCoord();
    //Get the ants current Y coord
    int antPosY = myAnt.getYCoord();

    //antStates that repersent the possible turns that the Ant can take. Based on the clockwise motion of a clock.
    const int ANTSTATEUP = 0;
    const int ANTSTATERIGHT = 1;
    const int ANTSTATEDOWN = 2;
    const int ANTSTATELEFT = 3;


    //If the board is 0, which means an white space, we ________________________________ <---Place rule here for how ant is supposed to behave.
    if (boardColor == 0) {
        //cout<<"blank space"<<std::endl;

        //If the ant lands on a white space, we update its direction by 1.
        antDirection++;

        //Set the board where the ant is to black
        ary[antPosX][antPosY] = '#';
        //Makes sure that the ant's direction goes back to pointing UP if it is already pointing left. Think of it like a clock.
        if (antDirection > ANTSTATELEFT) {
            antDirection = ANTSTATEUP;

        }

        //Move the ant based on its current state.
        if (antDirection == ANTSTATEUP) {
            myAnt.setXCoord(--antPosX);
        } else if (antDirection == ANTSTATERIGHT) {
            myAnt.setYCoord(++antPosY);
        } else if (antDirection == ANTSTATEDOWN) {
            myAnt.setXCoord(++antPosX);
        } else if (antDirection == ANTSTATELEFT) {
            myAnt.setYCoord(--antPosY);
        }



        //If the board is 1, which means an black space, we ________________________________ <---Place rule here for how ant is supposed to behave.
    } else if (boardColor == 1) {
        //  cout<<"black space"<<std::endl;

        antDirection--;
        ary[antPosX][antPosY] = ' ';

        if (antDirection < ANTSTATEUP) {
            antDirection = ANTSTATELEFT;

        }
        //  cout<<antDirection<<std::endl;
        //Move the ant
        if (antDirection == ANTSTATEUP) {
            myAnt.setXCoord(--antPosX);
        } else if (antDirection == ANTSTATERIGHT) {
            myAnt.setYCoord(++antPosY);
        } else if (antDirection == ANTSTATEDOWN) {
            myAnt.setXCoord(++antPosX);
        } else if (antDirection == ANTSTATELEFT) {
            myAnt.setYCoord(--antPosY);
        }


    }



    //Edge of board colission check. If ant hits the end of the board, we wrap it around.
    if (myAnt.getXCoord() > row - 1) {
        //   cout<<"Hit the edge, X>row-1"<<std::endl;
        myAnt.setXCoord(0);
    } else if (myAnt.getXCoord() < 0) {
        //   cout<<"Hit the edge, X<0"<<std::endl;
        myAnt.setXCoord(row - 1);
    }

    if (myAnt.getYCoord() > col - 1) {
        //   cout<<"Hit the edge, Y>col-1"<<std::endl;
        myAnt.setYCoord(0);
    } else if (myAnt.getYCoord() < 0) {
        //  cout<<"Hit the edge, Y<0"<<std::endl;

        myAnt.setYCoord(col - 1);
    }



    //Here we track if the board is white or black. We then set the BoardColor to 0 or 1 so we know what color the ant has landed on.
    if (ary[myAnt.getXCoord()][myAnt.getYCoord()] == ' ') {
        myAnt.setBoardColor(0);


    } else if (ary[myAnt.getXCoord()][myAnt.getYCoord()] == '#') {
        myAnt.setBoardColor(1);

    }


}