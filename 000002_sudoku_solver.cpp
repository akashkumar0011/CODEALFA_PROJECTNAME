#include <iostream>
#define N 9
using namespace std;

   // Function to print the Sudoku grid
   void printGrid(int grid[N][N])
{
   for (int r = 0; r < N; r++)
{
   for (int c = 0; c < N; c++)
{
   cout << grid[r][c] << " ";
}
   cout << endl;
}
}

   // Function to check if a number can be placed safely (row, column, and 3x3 subgrid constraints)
   bool isSafe(int grid[N][N], int row, int col, int num)
{
   // Check row constraint
   for (int x = 0; x < 9; x++)
{
   if (grid[row][x] == num)
   return false;
}
   // Check column constraint
   for (int x = 0; x < 9; x++)
{
   if (grid[x][col] == num)
   return false;
}

   // Check 3x3 subgrid constraint
   int startRow = row - row % 3;
   int startCol = col - col % 3;
   for (int i = 0; i < 3; i++)
{
   for (int j = 0; j < 3; j++)
{
   if (grid[i + startRow][j + startCol] == num)
   return false;
}
}
   return true;
}

   // Backtracking function to recursively try possible numbers until the puzzle is solved[cite : 1]
   bool solveSudoku(int grid[N][N], int row, int col)
{
   // If we have reached the 9th row and 9th column, the puzzle is successfully solved
   if (row == N - 1 && col == N)
   return true;

   // If column reaches 9, move to the next row and column 0
   if (col == N)
{
   row++;
   col = 0;
}

   // If the current cell already contains a number greater than 0, skip to the next column
   if (grid[row][col] > 0)
   return solveSudoku(grid, row, col + 1);

   // Try numbers from 1 to 9
   for (int num = 1; num <= 9; num++)
{
   if (isSafe(grid, row, col, num))
{
   grid[row][col] = num;

   // Recursively check for next possibilities
   if (solveSudoku(grid, row, col + 1))
   return true;
}
   // Remove the number if it doesn't lead to a solution (Backtracking)
   grid[row][col] = 0;
}
   return false;
}

   int main()
{
   // Representing the Sudoku grid as a 2D array (0 represents empty cells)[cite : 1]
   int grid[N][N] = 
{
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

   cout << "--- SUDOKU SOLVER ---" << endl;
   cout << "Unsolved Sudoku Grid :" << endl;
   printGrid(grid);
   cout << "\n-----------------------------------\n" << endl;

   if (solveSudoku(grid, 0, 0))
{
   cout << "Successfully Solved Sudoku Grid :" << endl;
   printGrid(grid);
} 
   else
{
   cout << "No solution exists for the given Sudoku puzzle!" << endl;
}

   return 0;
}