
#ifndef PLAYGAME_H
    #define PLAYGAME_H
    void player_take_turn(char* player_pieces, char** *board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win);
    void select_column_to_place_piece_in_player1(char* player_pieces, char** *board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win);
    void put_piece_on_board_player1(char* player_pieces, char** board, int num_rows,int num_cols, int col_choice, int num_row_for_grid, int num_in_row_to_win);
    void select_column_to_place_piece_in_player2(char *player_pieces, char** *board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win);
    void put_piece_on_board_player2(char* player_pieces, char** board, int num_rows,int num_cols, int col_choice, int num_row_for_grid, int num_in_row_to_win);
    bool check_if_col_is_full(char** board, int col_choice, int num_rows, int num_cols);
    void check_if_win_condition_met_player1(char *player_pieces, char **board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win);
    void check_if_win_condition_met_player2(char *player_pieces, char **board, int num_rows, int num_cols, int num_row_for_grid, int num_in_row_to_win);
#endif

