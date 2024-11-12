#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> grn(int n){
	std::vector<int> numbers(n);
	std::iota(numbers.begin(), numbers.end(), 1);
	
	std::random_device rd;
	std::mt19937 rng(rd());
	
	std::shuffle(numbers.begin(), numbers.end(), rng);
	return numbers;
}

int main(){	
	return 0;
}