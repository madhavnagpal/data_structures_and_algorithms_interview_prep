/**
 * Given N non-negative integers representing an elevation map where
 * the width of each bar is 1, compute how much water it can trap
 * after raining.
 */

/**
 * Approach: Time O(n), Space O(n)
 *
 * 1 store left[], where left[i] will have max from arr[0] ... arr[i]
 * 2 store right[], where right[i] will have max from arr[i] ... arr[n-1]
 * 3 for each positon
 * 	 water += min(left[i], right[i]) - arr[i]
 */

#include<iostream>
#include<algorithm>
using namespace std;

long getTrappedWater(long *arr, int n) {
	if (n <= 2) return 0;

	long left[n] = {0};
	long right[n] = {0};

	left[0] = arr[0];
	right[n - 1] = arr[n - 1];

	for (int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], arr[i]);
		right[n - i - 1] = max(right[n - i], arr[n - i - 1]);
	}

	long totalWater = 0;

	for (int i = 0; i < n; i++) {
		totalWater += min(left[i], right[i]) - arr[i];
	}

	return totalWater;
}

int main() {
	long arr[] = {3, 0, 0, 2, 0, 4};
	int n = 6;

	cout << getTrappedWater(arr, 6) << endl;
	return 0;
}