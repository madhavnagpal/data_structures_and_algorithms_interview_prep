#include<iostream>
#include<vector>
using namespace std;

int main() {
	//2D Vector
	vector< vector<int> > arr =  {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9, 10},
		{11, 12}
	};

	for (int row = 0; row < arr.size(); row++) {
		for (int col = 0; col < arr[row].size(); col++) {
			cout << arr[row][col] << " ";
		}
		cout << endl;
	}
	return 0;
}