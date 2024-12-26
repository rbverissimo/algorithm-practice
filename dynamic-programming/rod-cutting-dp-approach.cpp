#include<bits/stdc++.h>

using namespace std;

//EXPLAIN: the ans variable of the rodRecurisve is the return of the evalutation of the current answer and the price between the the beginning - rest of the array
// meaning: if we cut the array at index 2, then the array should be cut at index 6. 


int cutRodRecursive(int i, vector<int> &price){
	
	if(i == 0) return 0;
	
	int ans = 0;
	
	for(int j = 1; j <= i; j++) ans = max(ans, price[j-1]+cutRodRecursive(i - j, price));
	
	return ans;
}


int cutRod(vector<int> &price){
	
	int n = price.size();  
	return cutRodRecursive(n, price); 
}

int main(){
	
	vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
	
	cout << cutRod(price);
	
	return 0;
}