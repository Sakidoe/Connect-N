#include <stdio.h>
#include <stdbool.h>
#include "board.h"

int get_move(char** board, int num_rows, int num_cols){
	int move_col;
	while (true)
	{
		printf("Enter a column between 0 and %d to play in: ", num_cols-1);
		scanf("%d", &move_col);
		if (move_col < 0 || move_col > num_cols-1)
		{
			continue;
		}
		for(int i = 0; i < num_rows; i++)
		{
			if (board[i][move_col] == '*')
			{
				return move_col;
			}
		}
	}
}

int play_move(char** board, int num_rows, int num_cols, int turn, int move_col){
	int move_row = -1;
	for(int i = 0; i < num_rows; i++)
	{
		if (board[num_rows-1-i][move_col] == '*')
		{
			if (turn == 0)
			{
				board[num_rows-1-i][move_col] = 'X';
			}
			
			if (turn == 1)
			{
				board[num_rows-1-i][move_col] = 'O';
			}
			move_row = num_rows-1-i;
			break;
		}
	}
	return move_row;
}

void change_turn(int* turn){
	if (*turn == 0)
	{
		*turn = 1;
	} 
	else
	{
		*turn = 0;
	}	
}

void play_game(char** board, int num_rows, int num_cols, int num_to_win){
	int move_row, move_col;
	int turn = 0;
	
	while(true){
		move_col = get_move(board, num_rows, num_cols);
		move_row = play_move(board, num_rows, num_cols, turn, move_col);
		display_board(board, num_rows, num_cols);
		if (is_game_over(board, num_rows, num_cols))
		{
			printf("Tie game!\n");
			break;
		}
		if (is_win(board, num_rows, num_cols, num_to_win, move_row, move_col))
		{
			if (turn == 0)
			{
				printf("Player 1 Won!\n");
				break;
			} 
			else 
			{
				printf("Player 2 Won!\n");
				break;
			}
		}
		change_turn(&turn);
		//printf("move_row: %d, move_col: %d\n", move_row,move_col);
	}
}
