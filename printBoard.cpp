/*********************************************************************
** Author: Adil Chaudhry
** Date: 1/7/2019
** Description: Contains function responsible for prinitng the most up to date grind + ant location
*********************************************************************/
#include "printBoard.h"
#include <iostream>

using std::cout;

//Takes as paramaters a 2d array, the row and col size of the array, and an ant object. It uses these arguments to print the grid
void printBoard(char **boardArray, int row, int col, Ant ant) {
    //Takes the X and Y coords of the Ant and prints a ant character in that position.
    int antX = ant.getXCoord();
    int antY = ant.getYCoord();
    // cout<<"antX = "<<antX<<std::endl;
    // cout<<"antY = "<<antY<<std::endl;
    boardArray[antX][antY] = '*';

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            cout << boardArray[i][j]; //<<"|"

        }
        cout << std::endl;

    }
    cout << std::endl;
}