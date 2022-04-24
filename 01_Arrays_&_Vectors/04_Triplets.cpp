#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// TRIPLET SUM

vector<vector<int>> findTriplets(vector<int>arr, int n, int S) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> result = {};

	for (int i = 0; i <= n - 3; i++) {
		int low = i + 1, high = n - 1;
		while (low < high) {
			int currSum = arr[i] + arr[low] + arr[high];
			if (currSum == S) {
				result.push_back({ arr[i], arr[low++], arr[high--] });
			} else if (currSum > S) {
				high--;
			} else {
				low++;
			}
		}
	}

	return result;
}

vector<vector<int>> findUniqueTriplets(vector<int>arr, int n, int S) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> result = {};

	for (int i = 0; i <= n - 3; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		int low = i + 1, high = n - 1;
		while (low < high) {
			if (low > i + 1 && arr[low] == arr[low - 1]) {
				low++;
				continue;
			};
			if (high < n - 1 && arr[high] == arr[high + 1] ) {
				high--;
				continue;
			}
			int currSum = arr[i] + arr[low] + arr[high];
			if (currSum == S) {
				result.push_back({ arr[i], arr[low++], arr[high--] });
			} else if (currSum > S) {
				high--;
			} else {
				low++;
			}
		}
	}

	return result;
}

int main() {

	return 0;
}