#ifndef WINCONDITIONS_H
    #define WINCONDITIONS_H
   bool win_vertical(char* player_pieces, char** board, int num_rows, int num_cols, int num_in_row_to_win);
   bool win_horozontal(char* player_pieces, char** board, int num_rows, int num_cols, int num_in_row_to_win);
   bool win_diagonal(char* player_pieces, char** board, int num_rows, int num_cols, int num_in_row_to_win);
   bool win_diagonalright(char* player_pieces, char** board, int num_rows, int num_cols, int num_in_row_to_win);
   bool tie_game(char *player_take_turn, char** board, int num_rows, int num_cols, int num_in_row_to_win);
   void delete_board(char** *board, int num_rows , int num_cols);
   void delete_player_pieces(char* *playerpieces);
  

#endif


