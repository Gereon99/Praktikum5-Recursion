#include <stdio.h>

#define DIM 8

int board[DIM];
int solutions = 0;

void printSolution() {
    // Constructing a simple chess board
    printf("Solution %i:\n%i\t ", ++solutions, DIM);
    for (int i = 0; i < DIM; i++) {
        printf("%i  ", i + 1);
    }
    printf("\n\to");
    for (int i = 0; i < DIM; i++) {
        printf(" - ");
    }
    printf("o\n");
    for (int i = 0; i < DIM; i++) {
        printf("%i\t|", i + 1);
        for (int j = 0; j < DIM; j++) {
            if (board[i] == j) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("|\n");
    }
    printf("\to");
    for (int i = 0; i < DIM; i++) {
        printf(" - ");
    }
    printf("o\n\n");

}

int notThreatened(int column, int row) {
    // Check left side
    for (int i = column; i > 0; i--) {
        int previousColumn = i - 1;
        if (column != 0 && row == board[previousColumn]) {
            return 0;
        }
    }
    // Check top-left diagonal
    for (int i = 1, j = row; i <= column && j > 0; i++, j--) {
        if (column != 0 && row == board[column - i] + i) {
            return 0;
        }
    }
    // Check bottom-left diagonal
    for (int i = 1, j = row; i <= column && j < DIM; i++, j++) {
        if (column != 0 && row == board[column - i] - i) {
            return 0;
        }
    }
    return 1;
}

void placeIn(int column) {
    // Keep placing queens until every combination was successfully checked
    if (column != DIM) {
        for (int row = 0; row < DIM; row++) {
            if (notThreatened(column, row)) {
                board[column] = row;
                placeIn(column + 1);
            }
        }
    } else {
        // 'DIM' amount of queens have been placed
        printSolution();
    }
}

int main() {
    printf("Printing all solutions to the %i queens problem:\n\n", DIM);
    for (int i = 0; i < DIM; i++) {
        board[i] = 0;
    }
    // Placing the first queen in the first column
    placeIn(0);
    printf("Found a total of %i solutions.", solutions);
    return 0;
}