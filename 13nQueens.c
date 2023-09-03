/*
Consider the n-queens puzzle in which the goal is to place N queens on
an N×N chessboard such that no two queens attack each other. A queen can
attack horizontally, vertically, or diagonally. Given an integer N, return all
distinct solutions to the N-queens puzzle. Note: Use Backtracking technique
*/
#include <stdio.h>
#include <string.h>

int N; int count=0;

int isSafe(char mat[][N], int r, int c)
{
    for (int i = 0; i < r; i++) // Check if a queen is present on the column
        if (mat[i][c] == 'Q')
            return 0;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) // Check if a queen is present on the upper left diagonal
        if (mat[i][j] == 'Q')
            return 0;
    for (int i = r, j = c; i >= 0 && j < N; i--, j++) // Check if a queen is present on the upper right diagonal
        if (mat[i][j] == 'Q')
            return 0;
    return 1; // if not, safe
}
void printSolution(char mat[][N])
{
    count++;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            if (mat[i][j] == 'Q') // Print the index where the queen is present
                printf("%d ", j);
        }
    printf("\n");
}
void nQueen(char mat[][N], int r)
{
    if (r == N) // If a queen is placed on all rows
    {
        printSolution(mat);
        return;
    }
    for (int i = 0; i < N; i++)
        if (isSafe(mat, r, i))
        {
            mat[r][i] = 'Q'; // Place Queen on the position r,i and move to the next row
            nQueen(mat, r + 1); 
            mat[r][i] = '-'; // Once you're back after checking all possibilities, remove the queen from r,i and place on r,i+1
        }
}
int main()
{
    printf("Enter no. of queens:\n");
    scanf("%d", &N);
    char mat[N][N];
    memset(mat, '-', sizeof(mat));
    printf("Solutions:\n");
    nQueen(mat, 0);
    printf("%d possible solutions\n", count);
    return 0;
}
