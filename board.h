#ifndef BOARD_H
	#define BOARD_H
	#include <stdbool.h>
	
	bool isNumber(char number[]);
	void get_rules(int argc, char *argv[], int* num_rows, int* num_cols, int* num_to_win);
	char** make_board(int num_rows, int num_cols);
	void display_board(char** board, int num_rows, int num_cols);
	void clean_up(char*** board, int num_rows, int num_cols);
    
	void play_game(char** board, int num_rows, int num_cols, int num_to_win);
	int get_move(char** board, int num_rows, int num_cols); //return move_col
	int play_move(char** board, int num_rows, int num_cols, int turn, int move_col); //return move_row
	void change_turn(int* turn);
    
	bool is_game_over(char** board, int num_rows, int num_cols);
	bool is_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col);
	bool row_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col);
	bool col_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col);
	bool diag_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col);
	bool left_diag_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col);
	bool right_diag_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col);
   
#endif