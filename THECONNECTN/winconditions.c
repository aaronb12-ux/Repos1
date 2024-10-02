#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "winconditions.h"
#include "gameboard.h"
#include "playgame.h"

bool win_vertical(char *player_pieces, char **board, int num_rows, int num_cols, int num_in_row_to_win)
{
    //function that checks if a player has a vertical win
    int count = 0;
    for (int i = 0; i <= num_rows - num_in_row_to_win; ++i)
    {
        for (int j = 0; j <= num_cols; ++j)
        {
            count = 0;
            for (int k = 0; k < num_in_row_to_win; ++k)
            {

                if (board[i + k][j] == '*' || board[i + k][j] != board[i][j])

                {
                    break;
                }
                else if (board[i][j] == *player_pieces)
                {

                    count = count + 1;
                }
            }

            if (count == num_in_row_to_win)
            {
                return true;
            }
        }
    }
    return 0;
}

bool win_horozontal(char *player_pieces, char **board, int num_rows, int num_cols, int num_in_row_to_win)
{
    //function that checks if a player has a horozontal win
    int count = 0;
    // checking for 'X'
    for (int i = num_rows - 1; i >= 0; --i)
    {
        for (int j = 0; j <= num_cols - num_in_row_to_win; ++j)
        {
            count = 0;
            for (int k = 0; k < num_in_row_to_win; ++k)
            {

                if (board[i][j + k] == '*' || board[i][j + k] != board[i][j])
                {

                    break;
                }
                else if (board[i][j] == *player_pieces)
                {
                    count = count + 1;
                }
            }

            if (count == num_in_row_to_win)
            {
                return true;
            }
        }
    }
    return 0;
}
bool win_diagonal(char *player_pieces, char **board, int num_rows, int num_cols, int num_in_row_to_win)
{
    //function that checks if a player has a diagonal win to the left
    int count = 0;
    // checking for 'X'
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            count = 0;
            for (int k = 0; k < num_in_row_to_win; ++k)
            {
                if ((i + k) < num_rows && (j - k) < num_cols)
                {

                    if (board[i + k][j - k] == '*' || board[i + k][j - k] != board[i][j])
                    {
                        break;
                    }
                    else if (board[i][j] == *player_pieces)
                    {
                        count = count + 1;
                    }
                }
            }

            if (count == num_in_row_to_win)
            {
                return true;
            }
        }
    }

    return 0;
}

bool win_diagonalright(char *player_pieces, char **board, int num_rows, int num_cols, int num_in_row_to_win)

{
    //function that checks if a player has a right diagonal win
    int count = 0;
    // checking for 'X'
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            count = 0;
            for (int k = 0; k < num_in_row_to_win; ++k)
            {
                if ((i + k) < num_rows && (j + k) < num_cols)
                {

                    if (board[i + k][j + k] == '*' || board[i + k][j + k] != board[i][j])
                    {

                        break;
                    }
                    else if (board[i][j] == *player_pieces)
                    {
                        count = count + 1;
                    }
                }
            }

            if (count == num_in_row_to_win)
            {
                return true;
            }
        }
    }
    return 0;
}

bool tie_game(char *player_pieces, char **board, int num_rows, int num_cols, int num_in_row_to_win)
{
    //function that checks if a tie game has occured
    int tie_count = 0;
    for (int i = num_rows - 1; i >= 0; --i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            if (board[i][j] != '*')
            {
                tie_count += 1;
            }
        }
    }
    if (tie_count == num_rows * num_cols)
    {
        return true;
    }

    return 0;
}
