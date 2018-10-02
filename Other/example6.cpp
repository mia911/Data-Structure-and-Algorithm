#include <iostream>
#include <vector>
using namespace std;

// Recursively build the triangle by trying all permutation of the last row
// (n, triangle, used, pos) state means that the 'pos'th element of the last row is being built
// The 'pos'th element is tried with all possible numbers (used.at(i - 1) == false); after a number is set; all numbers diagonally up from it is built and checked
// Function returns true if it is possible to build a triangle from the current state
bool recursiveBuildTriangle(int n, vector<vector<int>>& triangle, vector<bool>& used, int pos) {
	// The triangle is built, return true
	if(pos == n) {
		return true;
	}

	// Try all numbers for the 'pos'th element
	for(int i = 1; i <= n * (n + 1) / 2; i++) {
		if(!used.at(i - 1)) {
			// Set the 'pos'th element into i and mark i as used
			triangle.at(n - 1).at(pos) = i;
			used.at(i - 1) = true;

			// Build all elements diagonally up and check if they are all unused
			bool allUnused = true;
			int row = n - 2;
			int col = pos - 1;
			while(col >= 0) {
				int val = abs(triangle.at(row + 1).at(col) - triangle.at(row + 1).at(col + 1));
				if(!used.at(val - 1)) {
					triangle.at(row).at(col) = val;
					used.at(val - 1) = true;
				}
				else {
					// val is already used -> the whole state is invalid
					allUnused = false;
					break;
				}
				row--;
				col--;
			}

			// If current state is valid, just continue building the last row
			if(allUnused) {
				if(recursiveBuildTriangle(n, triangle, used, pos + 1)) {
					return true;
				}
			}

			// After finishing this branch, delete and unmark all numbers diagonally up from pos
			row = n - 1;
			col = pos;
			while(col >= 0) {
				if(triangle.at(row).at(col) != 0) {
					used.at(triangle.at(row).at(col) - 1) = false;
					triangle.at(row).at(col) = 0;
				}
				row--;
				col--;
			}
		}
	}

	return false;
}

vector<vector<int>> buildTriangle(int n) {
	// Initialize the size of the triangle
	vector<vector<int>> result = vector<vector<int>>(n);
	for(int i = 0; i < n; i++) {
		result.at(i) = vector<int>(i + 1);
	}

	// used.at(i) is true if number i + 1 is already in the triangle while it is recursively built
	// Initially, used is all false because no number has been used yet
	vector<bool> used = vector<bool>(n * (n + 1) / 2);

	recursiveBuildTriangle(n, result, used, 0);
	return result;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> triangle = buildTriangle(n);

	for(int i = 0; i < triangle.size(); i++) {
		for(int j = 0; j < triangle.at(i).size(); j++) {
			cout << triangle.at(i).at(j) << " ";
		}
		cout << endl;
	}
}