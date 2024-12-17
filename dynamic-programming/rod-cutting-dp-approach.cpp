#include<bits/stdc++.h>

using namespace std;


int cutRodRecursive(int i, vector<int> &price){
	
	if(i == 0) return 0;
	
	int ans = 0;
	
	for(int j = 1; j <= i; j++) ans = max(ans, price[j-1]+cutRodRecursive(i - j, price));
	
	return ans;
}

//0, 0,

int cutRod(vector<int> &price){
	
	int n = price.size();
	return cutRodRecursive(n, price);
}

int main(){
	
	
	return 0;
}