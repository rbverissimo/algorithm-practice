#include<iostream>
#include<vector>

using namespace std;


bool isSafe(vector<vector<int>> &sudoku, int row, int col, int num){
	
	
	int startRow = row - (row % 3), startCol = col - (col % 3);
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(sudoku[i + startRow][j + startCol] == num) return false;
		}
	}
	
	return true;
	
}

bool solveSudokuRecursively(){
	return false;
}

int main(){
	
	vector<vector<int>> sudoku = {
		{
			3, 0, 6, 5, 0, 8, 4, 0, 0 
		},
		{
			5, 2, 0, 0, 0, 0, 0, 0, 0
		},
		{
			0, 8, 7, 0, 0, 0, 0, 3, 1
		},
		{
			0, 0, 3, 0, 1, 0, 0, 8, 0
		}, 
		{
			9, 0, 0, 8, 6, 3, 0, 0, 5
		},
		{
			0, 5, 0, 0, 9, 0, 6, 0, 0
		},
        {	
			1, 3, 0, 0, 0, 0, 2, 5, 0
		}, 
        {
		  	0, 0, 0, 0, 0, 0, 0, 7, 4
		}, 
        {
			0, 0, 5, 2, 0, 6, 3, 0, 0
		}
	};
	
	return 0;
}