/**
 * You are given an integer array ‘ARR’. You have to find the length
 * of the shortest contiguous subarray such that,
 * if you sort this subarray in ascending order,
 * then the whole array will be sorted in ascending order
 */

/**
 * Approach - 1
 * Time O(NlogN) , Space (N)
 * Sort the array, find first diff index where its diff from sorted arr
 * and also from end the first diff, diff b/w indices is ans
 *
 * Better Approach
 * Time O(N), Space O(1)
 * Find smallest and largest element out of order
 * for smallest, start iterating from start, which pos it can be inserted
 * for largest, iterate from last
 * diff b/w these indices is ans
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool is_out_of_order(vector<int>&arr, int i) {
	int n = arr.size();
	if (i - 1 < 0 and i + 1 >= n) return false;
	else if (i - 1 < 0) return arr[1] < arr[0];
	else if (i + 1 >= n) return arr[i] < arr[i - 1];
	else return arr[i - 1] > arr[i] or arr[i] > arr[i + 1];
}

// O(NlogN)
int subarray_sort_Approach_1(vector< int > &arr) {
	vector<int> v(arr);
	sort(v.begin(), v.end());

	int start = 0, end = arr.size() - 1;
	while (arr[start] == v[start]) start++;
	while (arr[end] == v[end]) end--;

	int ans = 0;

	if (start < end) ans = end - start + 1;

	return ans;
}

// Time - O(N) Space - O(1)
int subarray_sort_better_approach(vector< int > &arr) {
	int smallest = INT_MAX;
	int largest = INT_MIN;
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		if (is_out_of_order(arr, i)) {
			smallest = min(smallest, arr[i]);
			largest = max(largest, arr[i]);
		}
	}

	// find the right index where smallest and largest lie
	if (smallest == INT_MAX) return 0;

	int left = 0;
	while (arr[left] <= smallest) left++;

	int right = n - 1;
	while (largest <= arr[right]) right--;

	return right - left + 1;
}


int main() {
	vector<int> arr({2, 6, 4, 8, 10, 9 , 15});

	// cout << subarray_sort_Approach_1(arr) << endl;s

	cout << subarray_sort_better_approach(arr) << endl;

	return 0;
}
