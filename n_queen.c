#include <stdio.h>

#define N 4   // Change this value for different sizes

int board[N][N];

// Function to print solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place queen
int isSafe(int row, int col) {
    int i, j;

    // Check left side of row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Backtracking function
int solveNQueen(int col) {
    if (col >= N) {
        printSolution();
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            solveNQueen(col + 1);

            // Backtrack
            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Initialize board with 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    printf("Solutions for %d-Queen Problem:\n\n", N);
    solveNQueen(0);

    return 0;
}