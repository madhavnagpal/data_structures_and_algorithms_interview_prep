#include<iostream>
#include<unordered_map>
using namespace std;

/**
 * All queries take O(1) time complexity
 */

int main() {
	unordered_map<string, int> menu;

	// Insert Key Value pairs inside the hashtable O(1) operation
	menu["pizza"] = 300;
	menu["maggi"] = 15;
	menu["cold-drink"] = 20;
	menu["dosa"] = 99;

	// Update Query O(1)
	menu["dosa"] = (1 + 0.1) * menu["dosa"];

	// Deletion O(1)
	menu.erase("dosa");

	// Search O(1)
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