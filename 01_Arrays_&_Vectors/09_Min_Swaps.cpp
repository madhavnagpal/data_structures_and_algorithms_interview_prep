/**
 * Given an array of size N (distinct elements), find the minimum number of swaps
 * needed to make the array sorted
 */

/**
 * Approach
 *
 * 1 Sort the array, to know the correct location of each element
 * 2 find all the non intersecting cycles that are present in array, for
 * each cycle we need size, then swaps for each cycle will be size - 1
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

int minSwaps(vector<int> &arr)
{
	int n = arr.size();
	if (n < 2) return 0;

	// Know the actual position of elements (sorting)
	// store current indices
	pair<int, int> ap[n];
	for (int i = 0; i < n; i++) {
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	// sorting
	sort(ap, ap + n);

	int ans = 0;

	// build the main logic
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {

		// if element is visited or element is in right position
		int old_position = ap[i].second;
		if (visited[i] or old_position == i) {
			continue;
		}

		// visiting the element for first time
		int node = i;
		int cycle_size = 0;

		while (!visited[node]) {
			visited[node] = true;
			int next_node = ap[node].second;
			node = next_node;
			cycle_size++;
		}
		ans += cycle_size - 1;
	}
	return ans;
}

int main() {
	vector<int> arr({ 5, 4, 3, 2, 1});

	cout << minSwaps(arr) << endl;

	return 0;
}
