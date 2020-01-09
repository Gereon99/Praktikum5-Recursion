#include <stdio.h>
#include <stdlib.h>

#define DIM 4

void printSolution(const int* board, int solutionNumber) {
    // Constructing a simple chess board
    printf("Solution %i:\n%i\t  ", solutionNumber, DIM);
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

int notThreatened(int column, int row, int* board) {
    for (int i = 0; i < column; i++) {
        if (abs(board[i] - row) == abs(i - column) || board[i] == row) {
            return 0;
        }
    }
    return 1;
}

void placeIn(int column, int* board, int* solutions) {
    // Keep placing queens until every combination was successfully checked
    if (column != DIM) {
        for (int row = 0; row < DIM; row++) {
            if (notThreatened(column, row, board)) {
                board[column] = row;
                placeIn(column + 1, board, solutions);
            }
        }
    } else {
        // 'DIM' amount of queens have been placed
        *solutions += 1;
        printSolution(board, *solutions);
    }
}

int main() {
    printf("Printing all solutions to the %i queens problem:\n\n", DIM);
    int board[DIM] = {0};
    int solutions = 0;
    placeIn(0, board, &solutions);
    printf("Found a total of %i solutions.", solutions);
    return 0;
}