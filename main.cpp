/*********************************************************************
** Project Name: Project 1
** Author: Adil Chaudhry
** Date: 1/7/2019
** Description: Langtons Ant project - simulates the movements of Langtons Ant
*********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "Ant.h"
#include "printBoard.h"
#include "moveAnt.h"
#include "inputValidation.h"
#include "Menu.h"

using std::cin;
using std::cout;


int main() {
    Ant myAnt;
    //Holds the size of the grids row and col
    int row = 0;
    int col = 0;

    //Counter to track the loop for how many steps that ant should perform
    int counter = 0;
    int simulationSteps = 0;

    //Set the initial X and Y coords of the ant to be the middle of the board.
    int antStartPosX = 0;
    int antStartPosY = 0;

    //Holds the choice value depending on what the menu shows
    int menuChoice = 0;
    //Bool to track if the user wants to play gain
    bool playAgain = true;
    //Bool to determin if user has selected to have a random ant starting position
    bool randomAntStartPos = false;


    while (playAgain) {

        //Set up a vector to contain the bonus menu asking the user if they want a random ant X and Y position
        vector<string> bonusMenuOptions = {"Yes", "No"};
        Menu bonusMenu("Extra Credit Option: Do you want to use a random starting position for the ant?", bonusMenuOptions);
        menuChoice = bonusMenu.displayMenu();
        switch (menuChoice) {
            case 1:
                randomAntStartPos = true;
                break;

            case 2:
                randomAntStartPos = false;
                break;
        }

        //Set up a vector to contain the simulations main menu
        vector<string> myMenuOptions = {"Start Langton's Ant simulation", "Quit"};
        Menu myMenu("Main Menu", myMenuOptions);
        menuChoice = myMenu.displayMenu();
        //Depending on the users menu choice, we either proceed with the simulation, in wich case we ask for variable values. Or we quit the simulation
        switch (menuChoice) {

            case 1:
                cout << "Please enter the number of rows for the board [min:1, max:1000]" << std::endl;
                cin >> row;
                isValidIntRange(row, 1, 1000, "Please enter the number of rows for the board [min:1, max:1000]");
                cout << "Please enter the number of columns for the board [min:1, max:1000]" << std::endl;
                cin >> col;
                isValidIntRange(col, 1, 1000, "Please enter the number of columns for the board [min:1, max:1000]");
                cout << "Please enter the number of times(steps) you want the simulation to run for [max:20,000]"
                     << std::endl;
                cin >> simulationSteps;
                isValidIntRange(simulationSteps, 1, 20000,
                                "Please enter the number of times(steps) you want the simulation to run for [max:20,000]");
                //If the user has selected to set a random ant start position, we skip this step. Otherwise, we ask the user for the X and Y position of the ant
                if (randomAntStartPos == false) {

                    cout << "Please enter the starting row of the ant [min:1]" << std::endl;
                    cin >> antStartPosX;
                    isValidIntRange(antStartPosX, 1, row, "Please enter the starting row of the ant [min:1]");
                    cout << "Please enter the starting column of the ant[min:1]" << std::endl;
                    cin >> antStartPosY;
                    isValidIntRange(antStartPosY, 1, col, "Please enter the starting column of the ant [min:1]");
                } else {
                    //Set a random value of the ant's X and Y coords
                    srand((int) time(0));
                    antStartPosX = rand() % row + 1;
                    antStartPosY = rand() % col + 1;
                }

                break;

            case 2:
                return 0;

        }

        //Set the ants initial X and Y coords. We subtract 1 from each as to not go out of the bounds of the array.
        myAnt.setXCoord(antStartPosX - 1);
        myAnt.setYCoord(antStartPosY - 1);

        //Get the initial direction of the Ant.
        int antDirection = myAnt.getAntDirection();

        //Initilize a dynamic 2d array and fill it with blank spaces. GRIDSIZE repersents that max dimensions of the array.
        char **ary = new char *[row];
        for (int i = 0; i < row; i++) {
            ary[i] = new char[col];
            for (int j = 0; j < col; j++) {
                ary[i][j] = ' ';
            }
        }

        //Print the board as well as the initial starting position of the ant.
        printBoard(ary, row, col, myAnt);

        //Here we make the any 'move' on our board.

        while (counter < simulationSteps) {
            //moveAnt function is responsilble for the ant's movement simulation
            moveAnt(ary, row, col, antDirection, myAnt);
            //printBoard function prints the ant on the board
            printBoard(ary, row, col, myAnt);
            counter++;

        }

        //Set up a new vector to hold the End game menu asking the user to Play Again or Quit
        vector<string> myEndMenuOptions = {"Play Again", "Quit"};
        myMenu.setMenuOptions(myEndMenuOptions);
        myMenu.setMenuHeader("The simulation has ended. Do you want to play again?");
        menuChoice = myMenu.displayMenu();
        //Depending on the menu choice of the user, we either reset the variables to 0 to reset and restart the simulation, or we quit the simulation.
        switch (menuChoice) {
            case 1:
                row = 0;
                col = 0;
                counter = 0;
                simulationSteps = 0;
                antStartPosX = 0;
                antStartPosY = 0;
                menuChoice = 0;
                myAnt.setAntDirection(0);
                myAnt.setBoardColor(0);
                randomAntStartPos == false;
                playAgain = true;
                break;
            case 2:
                playAgain = false;

                //Deallocate 2d array and clean up memory
                for (int i = 0; i < col; i++) {
                    delete[] ary[i];
                }
                delete[] ary;

                return 0;

        }
    }

}


