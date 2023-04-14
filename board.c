#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isNumber(char number[])
{
	int i = 0;

	//checking for negative numbers
	if (number[0] == '-')
	{
		i = 1;
	}

	for (; number[i] != 0; i++)
	{
		if (!isdigit((unsigned char)number[i]))
			return false;
	}
	return true;
}

void get_rules(int argc, char *argv[], int* num_rows, int* num_cols, int* num_to_win){
    
//printf("argc:%d\n", argc);
	if (argc < 4) {
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	} 
	
	if (argc > 4) {
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	} 
	
	for(int i = 1; i < argc; i++)
	{
		if( (isNumber(argv[i]) == false) )
		{
			printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
			printf("num_rows num_columns number_of_pieces_in_a_row_needed_to_win should be integers\n");
			exit(0);
		}
	}
	
	*num_rows = atoi(argv[1]);
	*num_cols = atoi(argv[2]);
	*num_to_win = atoi(argv[3]);
//printf("*num_rows:%d, *num_cols:%d, *num_to_win:%d\n", *num_rows, *num_cols, *num_to_win);
	
	if ((*num_rows < 1) || (*num_cols < 1) || (*num_to_win < 1))
	{
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		printf("num_rows num_columns number_of_pieces_in_a_row_needed_to_win should > 0\n");
		exit(0);
	}
	
}
char** make_board(int num_rows, int num_cols){
    char** board = (char**)malloc(num_rows * sizeof(char*));
    for(int i = 0; i < num_rows; ++i){
        board[i] = (char*)malloc(num_cols * sizeof(char));
        for(int j = 0; j < num_cols; ++j){
            board[i][j] = '*';
        }
    }
    return board;
}

void clean_up(char*** board, int num_rows, int num_cols){
    
    for(int i = 0; i< num_rows; ++i){
        free((*board)[i]);
		(*board)[i] = NULL;
	}
	free(*board);
	*board = NULL;
}

void display_board( char** board, int num_rows, int num_cols){
	for (int i = 0; i < num_rows; i++) {
		printf("%d ", num_rows-i-1);
		for (int j = 0; j < num_cols; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("  ");
	for (int j = 0; j < num_cols; j++) {
		printf("%d ", j);
	}
	printf("\n");

}
