#include <stdio.h>
#include <stdbool.h>
#include "board.h"

bool is_game_over(char** board, int num_rows, int num_cols){	
	for(int i = 0; i < num_cols; i++)
	{
		if (board[0][i] == '*')
		{
			return false;
		}
    }
	return true;
}

bool is_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col){
    if (row_win(board, num_rows, num_cols, num_to_win, move_row, move_col) || col_win(board, num_rows, num_cols, num_to_win, move_row, move_col) || diag_win(board, num_rows, num_cols, num_to_win, move_row, move_col))
	{
		return true;
	} else {
		return false;
	}	
}

bool row_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col){
    int count = 1;
	for(int i = move_col-1; i > -1; i--)
	{
		if (board[move_row][i] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	for(int i = move_col+1; i < num_cols; i++)
	{
		if (board[move_row][i] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	if (count >= num_to_win)
	{
		return true;
	} else {
		return false;
	}
}

bool col_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col){
    int count = 1;
	
	for(int i = move_row-1; i > -1; i--)
	{
		if (board[i][move_col] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	
	for(int i = move_row+1; i < num_rows; i++)
	{
		if (board[i][move_col] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	
	if (count >= num_to_win)
	{
		return true;
	} else {
		return false;
	}
}

bool diag_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col){
    if (left_diag_win(board, num_rows, num_cols, num_to_win, move_row, move_col) || right_diag_win(board, num_rows, num_cols, num_to_win, move_row, move_col))
	{
		return true;
	} else {
		return false;
	} 
}

bool left_diag_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col){
    int count = 1;
	
	for(int i = move_row-1, j = move_col-1; i > -1&&j>-1; i--,j--)
	{
		if (board[i][j] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	
	for(int i = move_row+1, j=move_col+1; i < num_rows&&j<num_cols; i++,j++)
	{
		if (board[i][j] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	
	if (count >= num_to_win)
	{
		return true;
	} else {
		return false;
	}

}

bool right_diag_win(char** board, int num_rows, int num_cols, int num_to_win, int move_row, int move_col){
    int count = 1;
	
	for(int i = move_row+1, j = move_col-1; i < num_rows&&j>-1; i++,j--)
	{
		if (board[i][j] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	
	for(int i = move_row-1, j=move_col+1; i > -1&&j<num_cols; i--,j++)
	{
		if (board[i][j] == board[move_row][move_col])
		{
			count++;
		} else {
			break;
		}
    }
	
	if (count >= num_to_win)
	{
		return true;
	} else {
		return false;
	}
    
}
