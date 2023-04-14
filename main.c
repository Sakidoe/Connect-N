#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"

int main(int argc, char *argv[]){
	
	char** board;
	int num_rows, num_cols, num_to_win;
	get_rules(argc, argv, &num_rows, &num_cols, &num_to_win);
//printf("num_rows:%d, num_cols:%d, num_to_win:%d\n", num_rows, num_cols, num_to_win);
	board = make_board(num_rows, num_cols);
	display_board(board, num_rows, num_cols);
	play_game(board, num_rows, num_cols, num_to_win);
	clean_up(&board, num_rows, num_cols);
	return 0;
}
