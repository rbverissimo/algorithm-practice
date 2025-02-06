#include<bits/stdc++.h>

bool flag = 0; //if solution: 1

void PrintSubSetSum(int i, int n, int set[], int targetSum, std::vector<int>& subset){
	
	
	if(targetSum == 0){
		flag=1;
		std::cout << "[ ";
		for(int i = 0; i < subset.size(); i++){
			std::cout << subset[i];
			
			if(subset.size() == i+1) std::cout << " ";
			else std::cout << ", ";
		}
		std::cout << "] ";
		return;
	}
	
	if(i == n) return;
	
	PrintSubSetSum(i + 1, n, set, targetSum, subset);
	
	if(set[i] <= targetSum){
		subset.push_back(set[i]);
		
		PrintSubSetSum(i + 1, n, set, targetSum - set[i], subset);
		
		subset.pop_back();
	}
	
}

int main(){
	
	int set[] = {1, 3, 5, 2, 4, 6};
	int sum = 5;
	
	int n = sizeof(set)/sizeof(set[0]);
	std::vector<int> subset;
	
	PrintSubSetSum(0, n, set, sum, subset);
	
	if(!flag) std::cout << "No subset found";
	else std::cout << " These are the subsets found";
	
	return 0;
}