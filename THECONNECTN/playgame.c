#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "gameboard.h"
#include "playgame.h"
#include "winconditions.h"
#include "inputval.h"

void check_if_win_condition_met_player2(char *player_pieces, char **board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win)
{

    if ((win_vertical(&player_pieces[1], board, num_rows, num_cols, num_in_row_to_win)) || (win_horozontal(&player_pieces[1], board, num_rows, num_cols, num_in_row_to_win)) || (win_diagonal(&player_pieces[1], board, num_rows, num_cols, num_in_row_to_win)) ||
        (win_diagonalright(&player_pieces[1], board, num_rows, num_cols, num_in_row_to_win)))
    {
        printboard(board, num_rows, num_cols, num_row_for_grid);
        printf("\n");
        printf("Player 2 Won!");
        exit(0);
    }
    else if (tie_game(&player_pieces[1], board, num_rows, num_cols, num_in_row_to_win))
    {
        printboard(board, num_rows, num_cols, num_row_for_grid);
        printf("\n");
        printf("Tie Game!");
        exit(0);
    }
}

void put_piece_on_board_player2(char *player_pieces, char **board, int num_rows, int num_cols, int col_choice, int num_row_for_grid, int num_in_row_to_win)
{

    for (int i = num_rows - 1; i >= 0; --i)
    {
        if (board[i][col_choice] == '*')
        {
            board[i][col_choice] = player_pieces[1];
            break;
        }
    }

    check_if_win_condition_met_player2(player_pieces, board, num_rows, num_cols, num_row_for_grid, num_in_row_to_win);
}

void select_column_to_place_piece_in_player2(char *player_pieces, char ***board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win)
{

    int col_choice;
    printboard(*board, num_rows, num_cols, num_row_for_grid);
    printf("\n");
    while (true)
    {
        col_choice = getValidInt(num_cols);
        if (col_choice < 0 || col_choice > num_cols - 1)
        {
            continue;
        }
        else if (check_if_col_is_full(*board, col_choice, num_rows, num_cols))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    put_piece_on_board_player2(player_pieces, *board, num_rows, num_cols, col_choice, num_row_for_grid, num_in_row_to_win);
}

// here, the functions of player 1 end, now player 2 functions begin above

void check_if_win_condition_met_player1(char *player_pieces, char **board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win)
{
    //this function checks if the win conditions are met
    if ((win_horozontal(&player_pieces[0], board, num_rows, num_cols, num_in_row_to_win)) || (win_vertical(&player_pieces[0], board, num_rows, num_cols, num_in_row_to_win)) || (win_diagonal(&player_pieces[0], board, num_rows, num_cols, num_in_row_to_win)) || (win_diagonalright(&player_pieces[0], board, num_rows, num_cols, num_in_row_to_win)))
    {
        printboard(board, num_rows, num_cols, num_row_for_grid);
        printf("\n");
        printf("Player 1 Won!");
        delete_board(&board, num_rows, num_cols);
        delete_player_pieces(&player_pieces);
        exit(0);
    }
    else if (tie_game(&player_pieces[0], board, num_rows, num_cols, num_in_row_to_win))
    {
        printboard(board, num_rows, num_cols, num_row_for_grid);
        printf("\n");
        printf("Tie Game!");
        exit(0);
    }
}

void put_piece_on_board_player1(char *player_pieces, char **board, int num_rows, int num_cols, int col_choice, int num_row_for_grid, int num_in_row_to_win)
{
    //if the selected column is not fill and if the selected column is valid, then we place the piece on the board. Then we check if the win conditions are met
    for (int i = num_rows - 1; i >= 0; --i)
    {
        if (board[i][col_choice] == '*')
        {
            board[i][col_choice] = player_pieces[0];
            //putting the valid piece on the board
            break;
        }
    }

    check_if_win_condition_met_player1(player_pieces, board, num_rows, num_cols, num_row_for_grid, num_in_row_to_win);
}

bool check_if_col_is_full(char **board, int col_choice, int num_rows, int num_cols)
{
    //this funciton checks if the selected column is full by using a for loop and iterating from the top of the board to the bottom. If we come acress no "*" that means its full
    int is_row_full = 0;
    for (int i = num_rows - 1; i >= 0; --i)
    {

        if (board[i][col_choice] != '*')
        {
            
            is_row_full += 1;
        }
    }

    if (is_row_full == num_rows)
    {

        return true;
    }
    else
    {
        return false;
    }
}

void select_column_to_place_piece_in_player1(char *player_pieces, char ***board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win)
{
    //this function prompts player 1 to select a column. It also verifies user input. After a valid column is chosen, it places that piece on the board.
    int col_choice;
    printboard(*board, num_rows, num_cols, num_row_for_grid);
    printf("\n");
    //printing the board
    while (true)
    {
        col_choice = getValidInt(num_cols);
        //validating input
        if (col_choice < 0 || col_choice > num_cols - 1)
        {
            //checking if the integer is out of range
            continue;
        }
        else if (check_if_col_is_full(*board, col_choice, num_rows, num_cols))
        {
            //checking if the column is full
            continue;
        }
        else
        {
            break;
            //this break statement is run when the user enters valid input. This while loop continues until valid input is entered, valid input being a single integer
        }
    }

    put_piece_on_board_player1(player_pieces, *board, num_rows, num_cols, col_choice, num_row_for_grid, num_in_row_to_win);
}

void player_take_turn(char *player_pieces, char ***board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win)
{

    while (true)
    {
        //this while loop continuest to run while the game is not finished
        select_column_to_place_piece_in_player1(player_pieces, board, num_rows, num_cols, num_row_for_grid, num_in_row_to_win);
        select_column_to_place_piece_in_player2(player_pieces, board, num_rows, num_cols, num_row_for_grid, num_in_row_to_win);
    }
}

void delete_player_pieces(char **playerpieces)
{
    //after the game is over, we need to delete free the dynamically created array of piece, then free it
    free(*playerpieces);
    *playerpieces = NULL;
}

void delete_board(char ***board, int num_rows, int num_cols) 
{
    // this function deletes the all the matricies and sets them to NULL.
    for (int row = 0; row < num_rows; ++row)
    {                        // looping through all the rows in the matrix
        free((*board)[row]); // going through each row, and deleting the array made at that row
    }
    free(*board);
    *board = NULL;
}
