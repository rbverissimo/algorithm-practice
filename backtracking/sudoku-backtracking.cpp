#include<iostream>
#include<vector>

using namespace std;


bool isSafe(vector<vector<int>> &sudoku, int row, int col, int num){
	
	
	//check for the number in that row
	for(int x = 0; x < 9; x++){
		if(sudoku[row][x] == num) return false;   
	}
	
	//check for the same number in the column
	for(int x = 0; x < 9; x++){
		if(sudoku[x][col] == num) return false;
	}
	
	
	int startRow = row - (row % 3), startCol = col - (col % 3);
	
	//check if the number exists in a 3x3 space
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(sudoku[i + startRow][j + startCol] == num) return false;
		}
	}
	
	return true;
	
}

bool solveSudokuRecursively(vector<vector<int>> &sudoku, int row, int col){
	
	int n = sudoku.size();
	
	if(row == n - 1 && col == n) return true; //reached the end of the sudoku board
	
	if(col == n ){ //next row
		row++;
		col = 0;
	}
	
	if(sudoku[row][col] != 0) return solveSudokuRecursively(sudoku, row, col + 1);
	
	//check every number, if the number can't be solved in the sudoku, it will be simply marked as 0
	for(int num = 1; num <= n; num++){
		if(isSafe(sudoku, row, col, num)){
			sudoku[row][col] = num;
			if(solveSudokuRecursively(sudoku, row, col+1)) return true;
			sudoku[row][col] = 0;
		}
	}
	
	return false;
}

void solveSudoku(vector<vector<int>> &sudoku){
	solveSudokuRecursively(sudoku, 0, 0);
}

int main(){
	
	//given a solvable sudoku
	// unsolvable sudokus will lead to many zeros in the board
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
	
	solveSudoku(sudoku);
	
	for (int i = 0; i < sudoku.size(); i++) {
        for (int j = 0; j < sudoku.size(); j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }
	
	return 0;
}