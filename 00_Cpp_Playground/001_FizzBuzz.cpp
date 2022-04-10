#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> fizzbuzz(int n) {
	vector<string> result(n, "");

	for (int i = 0; i < n; i++) {
		int number = i + 1;
		string str = "";
		if (number % 3 == 0) str += "Fizz";
		if (number % 5 == 0) str += "Buzz";
		if (str == "") str = to_string(number);
		result[i] = str;
	}

	return result;
}

int main() {
	vector<string> arr = fizzbuzz(15);
	for (string curr : arr) {
		cout << curr << endl;
	}
	return 0;
}