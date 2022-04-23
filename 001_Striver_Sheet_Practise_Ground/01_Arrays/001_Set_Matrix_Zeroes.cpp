#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void setZeros(vector<vector<int>> &matrix) {
	int totalRows = matrix.size();
	int totalCols = matrix[0].size();
	int col0 = 1;

	for (int row = 0; row < totalRows; row++) {
		if (matrix[row][0] == 0) col0 = 0;
		for (int col = 1; col < totalCols; col++) {
			if (matrix[row][col] == 0) {
				matrix[row][0] = 0;
				matrix[0][col] = 0;
			}
		}
	}

	for (int row = totalRows - 1; row >= 0; row--) {
		for (int col = totalCols - 1; col >= 1; col--) {
			if (matrix[row][0] == 0 || matrix[0][col] == 0) matrix[row][col] = 0;
		}
		if (col0 == 0) matrix[row][0] = 0;
	}
}

void setZeroes_01(vector<vector<int>>& matrix) {
	unordered_set<int> rows, cols;

	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			if (matrix[row][col] == 0) {
				rows.insert(row);
				cols.insert(col);
			}
		}
	}

	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			if (rows.find(row) != rows.end() || cols.find(col) != cols.end()) matrix[row][col] = 0;
		}
	}
}

int main() {
	vector<vector<int>> matrix = { {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

	setZeroes(matrix);

	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	return 0;
}