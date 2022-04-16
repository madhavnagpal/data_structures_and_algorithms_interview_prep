#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main() {
	// set is just a collection of keys
	// each insertion is O(1)
	unordered_set<int> s{1, 2, 3, 4, 11, 15, 0};

	// insert O(1)
	s.insert(111);

	// erase O(1)
	s.erase(11);

	int key = 11;
	string displayValue = to_string(key);

	// search O(1)
	displayValue += s.find(key) != s.end() ? " found" : " not found";
	cout << displayValue << endl;

	// loop
	for (int item : s) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}