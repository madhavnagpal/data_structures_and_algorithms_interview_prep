/*

An array is a collection of elements of the same type placed in contiguous memory locations.

Unlike arrays, size of vectors can change dynamically, with their storage being handled
automatically by the container.

Unlike Arrays, Vectors are passed by value to a function, you may still pass
them by reference if need arises.

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Fill constuctor
	vector<int> arr(5, 12);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int curr : arr) {
		cout << curr << " ";
	}
	cout << endl;

	// pop_back does not reduce capacity of vector
	arr.pop_back();

	// if vector is full, push_back doubles the capacity of the vector
	// by copying array into new array of double the size
	arr.push_back(4);

	// Size of Vector (number of elements)
	cout << "size: " << arr.size() << endl;

	// Capacity of Vector
	cout << "capacity: " << arr.capacity() << endl;

	return 0;
}