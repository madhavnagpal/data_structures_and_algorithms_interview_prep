/**
 *	Pairs
 * 	Given an array containing N integers, and an number S denoting a target sum.
 *  Find number of pairs that can add up to form target sum.
 */

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

long long pairsWithGivenSum(vector<int> arr, int targetSum) {
	long long pairs = 0;
	unordered_map<int, int> map;

	for (int i = 0; i < arr.size(); i++) {
		int target = targetSum - arr[i];
		if (map.count(target)) {
			pairs += map[target];
		}
		if (map.count(arr[i])) map[arr[i]]++;
		else map[arr[i]] = 1;
	}

	return pairs;
}

int main() {
	vector<int> arr = {2, 8, 12, 5, -2, -2};
	// -2 -2 2 5 8 12 12
	int targetSum  = 10;

	cout << pairsWithGivenSum(arr, targetSum);

	return 0;
}

