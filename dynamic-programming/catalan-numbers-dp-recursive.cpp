#include<iostream>

using namespace std;

int findCatalan(int n){
	
	if(n < 2) return 1;
	int res = 0;
	for(int i = 0; i < n; i++) res += findCatalan(i) * findCatalan(n - i - 1);
	return res;
	
}

int main(){
	
	int n = 10;
	for(int i = 0; i < n + 1; i++) cout << i << ": " << findCatalan(i) << "\n";
	
	return 0;
}