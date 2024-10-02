#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameboard.h"
#include "playgame.h"

void play_game(char *player_pieces, char ***board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win)
{

  player_take_turn(player_pieces, board, num_rows, num_cols, num_row_for_grid, num_in_row_to_win);
  //players take their turn
}

char *define_player_pieces()
{

  char *player_pieces = (char *)malloc(2 * sizeof(char));
  player_pieces[0] = 'X'; // this is the player 1 piece. player_pieces[0] will replace the index at board[i][j] when player1 chooses a spot
  player_pieces[1] = 'O'; // this is the player 2 piece. player_pieces[1] will replace the index at board[i][j] when player2 chooses a spot
  return player_pieces;
}

void setup_game(int num_rows, int num_cols, int row_num_for_grid, int num_in_row_to_win)
{

  char **board = make_grid(num_rows, num_cols);
  //Creating a dynamically sized 2d array that takes in the number of rows and columns
  char *player_pieces = define_player_pieces();
  //an array that stores the player pieces
  play_game(player_pieces, &board, num_rows, num_cols, row_num_for_grid, num_in_row_to_win);
  //playing the game
}

void checkarg(int num_arguments)
{
  // this function takes in the number of command line arguments and checks if exaclty 4 were entered
  if (num_arguments > 4)
  {
    printf("\nToo many arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
    exit(0);
  }
  else if (num_arguments < 4)
  {
    printf("\nNot enough arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
    exit(0);
  }
}

int main(int arg4, char *argv[])
{
  // arg0 = outfile, arg1 = numrows in grid, arg2 = numcols in grid, arg3 = number in a row to win
  checkarg(arg4);
  //'arg4' is the number of arguments. If there is not 4 arguments, let the user know that and quit the program.

  int num_rows = atoi(argv[1]);
  // command line argument 1. Converting the first argument to the number of rows.

  int num_cols = atoi(argv[2]);
  // command line argument 2. The number of columns of the board.

  int num_in_row_to_win = atoi(argv[3]);
  // command line argument 2. Converting the third argument to the number in a row to win

  if ((num_cols < 0) || num_rows < 0 || num_in_row_to_win < 0)
  {
    // condition to check if either one of the command line argument is kess than 0, if so quit the game as thats invalid input
    exit(0);
  }

  int row_num_for_grid = atoi(argv[1]);
  // this variable is only used to list the numbers for the rows when the board is printed to the screen

  setup_game(num_rows, num_cols, row_num_for_grid, num_in_row_to_win);
  // setting up the game

  return 0;
}
