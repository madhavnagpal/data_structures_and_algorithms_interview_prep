#include<iostream>
#include<map>
using namespace std;

/**
 * All queries take O(log N) time complexity, as it internally
 * uses tree like structure (Balanced tree with height of log N)
 */

int main() {
	map<string, int> menu;

	// Insert Key Value pairs inside the hashtable O(log N) operation
	menu["maggi"] = 15;
	menu["cold-drink"] = 20;
	menu["dosa"] = 99;
	menu["pizza"] = 300;

	// Update Query O(log N)
	menu["dosa"] = (1 + 0.1) * menu["dosa"];

	// Deletion O(log N)
	menu.erase("dosa");

	// Search O(log N)
	string item = "dosa";

	if (menu.count(item) == 0) {
		cout << item << " not available" << endl;
	} else {
		cout << item << " is available and its cost is: " << menu[item] << endl;
	}

	// Iteration on All Key-Value pairs
	for (pair<string, int> currItem : menu) {
		cout << currItem.first << " - " << currItem.second << endl;
	}

	return 0;
}