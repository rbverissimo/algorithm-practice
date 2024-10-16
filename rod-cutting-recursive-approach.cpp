#include <stdio.h>
#include <limits.h>


int cutRod(int price[], int idx, int n){
	
	if(idx == 0) return n * price[0];
	
	if(n == 0) return 0;
	
	int notCut = cutRod(price, idx - 1, n);
	int cut = INT_MIN;
	int rodLen = idx + 1;
	
	
	
	if(rodLen <= n){
		cut = price[idx] + cutRod(price, idx, n - rodLen);
	}
	
	return (notCut > cut) ? notCut : cut;
	
}

int main(){
	
	int price[] = {1, 3, 4, 4};
	int size = sizeof(price) / sizeof(price[0]);
	printf("%d\n", cutRod(price, size - 1, size));
	
	return 0; 
}


/*

	A simulation of the stack
	
	cutRod(price, 3, 4);
		3 + cutRod(price, 3, 4 - 4);
		cut = 4 + 0;
		return 6 > 4, then 6
	 	notCut = cutRod(price, 2, 4) = 6;
	 		cut = 3 + cutRod(price, 2, 2);   ---> notCut 1 cut: 3 + 0
	 		return
	 		notCut = cutRod(price, 1, 4);
	 			notCut = cutRod(price, 0, 4) = 4;
	 			return
	 			cut = 1 + cutRod(price, 1, 3);
	 				notCut = cutRod(price, 0, 3) = 3 
	 				cut = 1 + rodCut(price, 1, 2);
				  	

*/