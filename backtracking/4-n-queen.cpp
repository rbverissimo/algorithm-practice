#define N 12
#include<stdio.h>
#include<stdbool.h>


void printSolution(int board[N][N]){	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j]) printf("Q ");
			else printf(". ");
		}
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col){
	
	int i, j;
	
	//checking left since the queen is already placed (no need to check the right side)
	for(i = 0; i < col; i++) if(board[row][i]) return false;
	
	
	//check the upper diagonal
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--) if(board[i][j]) return false;   
	
	
	//check the lower diagonal
	for(i = row, j = col; j >= 0 && i < N ; i++, j--) if(board[i][j]) return false;   
	
	
	return true;
	
}

bool solveNQUtil(int board[N][N], int col){
	
	if(col >= N) return true;
	
	for(int i = 0; i < N; i++){
		if(isSafe(board, i, col)){
			
			board[i][col] = 1;
			
			if(solveNQUtil(board, col+1)) return true;
			
			//backtrack to 0
			board[i][col] = 0;
		}
	}

	return false;	
}


bool solveNQ(){
	
	int board[N][N] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	
	if(solveNQUtil(board, 0) == false){
		printf("No solution possible");
		return false;
	}
	
	printSolution(board);
	return true;
	
}

int main(){
	
	solveNQ();
	return 0;
}