/**
 * Given an array containing N integers, find length of longest band
 *
 * Band - is a subsequence which can be reordered in such a manner that
 * all the elements are sequence (e.g 1, 2, 3, 4) or you can say sorted.
 */

/**
 * Approach -
 * Time: O(N)
 *
 * 1 Store elements in a unordered_set for having a lookup of O(1)
 * 2 Iterate on set
 * 3 If element is head of band (head means the number(x) whose parent
 * 	 i.e (x - 1) is not in array). then find length of the band (i.e
 * 	 keep iterating till (x + 1) is not in set)
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr) {
	int n = arr.size();
	unordered_set<int> s;

	for (int curr : arr) {
		s.insert(curr);
	}

	int largestLength = 1;

	for (int element : s) {
		int parent = element - 1;

		if (s.find(parent) == s.end()) {
			// find entire band starting from element
			int next_no = element + 1;
			int count = 1;

			while (s.find(next_no) != s.end()) {
				next_no++;
				count++;
			}
			if (count > largestLength) {
				largestLength = count;
			}
		}
	}

	return largestLength;
}

int main() {
	vector<int> arr{1, 9, 3, 0, 18, 5, 2, 10, 7, 12, 6, 4};
	cout << largestBand(arr) << endl;
	return 0;
}