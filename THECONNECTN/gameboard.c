#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameboard.h"

char **make_grid(int num_rows, int num_cols)
{
   //this function creates the game board
   char **board = (char **)malloc(num_rows * sizeof(char *));

   for (int row = 0; row < num_rows; ++row)
   {

      board[row] = (char *)malloc(num_cols * sizeof(char));

      for (int col = 0; col < num_cols; ++col)
      {

         board[row][col] = '*';
      }
   }
   return board;
}

void printboard(char **board, int num_rows, int num_cols, int num_row_for_grid)
{
    //this function prints the game board
   for (int row = 0; row < num_rows; ++row)
   {

      printf("%d ", num_row_for_grid - 1);

      num_row_for_grid = num_row_for_grid - 1;

      for (int col = 0; col < num_cols; ++col)
      {

         printf("%c ", board[row][col]);
      }

      printf("\n");
   }
   printf(" ");
   for (int col = 0; col < num_cols; ++col)
   {

      printf(" %d", col);
   }
}
