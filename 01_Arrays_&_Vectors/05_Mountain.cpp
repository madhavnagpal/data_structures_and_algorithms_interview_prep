/**
 * You are given an array of 'N' integers denoting the heights of the mountains.
 * You need to find the length of the longest subarray which has the shape
 * of a mountain.
 */

/**
 *
 * Approach
 *
 * 1 Identify peaks
 * 2 solve rest
 */

#include<iostream>
#include<vector>
using namespace std;

int longestMountain(vector<int> arr) {
	int longestLength = 0, n = arr.size();

	for (int i = 1; i <= n - 2;) {
		// check if arr[i] is peak or not
		if (arr[i - 1] < arr[i] and arr[i] > arr[i + 1]) {
			int count = 1;
			int j = i;

			// count left
			while (j >= 1 and arr[j - 1] < arr[j]) {
				j--;
				count++;
			}

			// count right
			while (i <= n - 2 and arr[i] > arr[i + 1]) {
				i++;
				count++;
			}
			longestLength = max(longestLength, count);
		} else {
			i++;
		}
	}
	return longestLength;
}

int main() {
	vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

	cout << longestMountain(arr) << endl;

	return 0;
}