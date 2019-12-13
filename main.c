#include <stdio.h>
#include <stdlib.h>

#define DIM 8

int board[DIM];
int solutions = 0;

int notThreatened(int column, int row) {
    // return 1 if queen can be placed in column
    // Left
    for (int i = column; i > 0; i--) {
        if (row == board[i - 1]) {
            return 0;
        }
    }
    // Diagonal Top Left
    for (int i = column; i > 0; i--) {
        if (row == board[i - 1] + 1) {
            return 0;
        }
    }

    // Diagonal Bottom Left
    for (int i = column; i > 0; i--) {
        if (row == board[i - 1] - 1) {
            return 0;
        }
    }
    // No Threat
    return 1;
}

void printSolution() {
    printf("Solution found.\n\n");
    solutions++;
}

void placeIn(int column) {
    if (column == 8) {
        printSolution();
    } else {
        for (int row = 0; row < DIM; row++) {
            if (notThreatened(column, row)) {
                board[column] = row;
                placeIn(column + 1);
            }
        }
    };
}

int main() {
    printf("Printing all solutions to the %i queens problem:\n\n", DIM);
    for (int i = 0; i < DIM; i++) {
        board[i] = -10;
        printf("%i ", board[i]);
    }
    printf("\n\n");
    placeIn(0);
    printf("Found a total of %i solutions.", solutions);
    return 0;
}