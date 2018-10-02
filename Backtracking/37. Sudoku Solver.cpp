class Solution {
public:
	bool debug = true;
	bool canPlaceBox(vector<vector<char>>&board, int i, int j, char k) {
		int firstRow, lastRow, firstCol, lastCol;
		if(i < 3) {
			firstRow = 0;
			lastRow = 2;
		} else if (i >= 3 && i < 6) {
			firstRow = 3;
			lastRow = 5;
		} else {
			firstRow = 6;
			lastRow = 8;
		}

		if(j < 3) {
			firstCol = 0;
			lastCol = 2;
		} else if (j >= 3 && j < 6) {
			firstCol = 3;
			lastCol = 5;
		} else {
			firstCol = 6;
			lastCol = 8;
		}

		for(int a = firstRow; a <= lastRow; a++) {
			for(int b = firstCol; b <= lastCol; b++) {
				if(board[a][b] == k) {
					return false;
				}
			}
		}
		return true;
	}

	bool canPlace(vector<vector<char>>&board, int i, int j, char k) {
		for(int a = 0; a < board.size(); a++) {
			if(board[i][a] == k || board[a][j] == k) {
				return false;
			}
		}
		if(!canPlaceBox(board, i, j, k)) {
			return false;
		}
		return true;
	}

	bool recursive(vector<vector<char>>&board, int i, int j) {
		if(debug) {
			cout << i << j << endl;
		}
		// if(i > board.size()) {
		// 	return false;
		// }

		if(i == board.size() && j == 0) {
			return true;
		}

		if(board[i][j] == '.') {
			for(char k = '1'; k <= '9'; k++) {
				if(canPlace(board, i, j, k)) {
					board[i][j] = k;
					if(j == board.size() - 1) {
						if(recursive(board, i + 1, 0)) {
							return true;
						}
					} else {
						if(recursive(board, i, j + 1)) {
							return true;
						}
					}
					board[i][j] = '.';
				}
			}
		} else {
			if(j == board.size() - 1) {
				if(recursive(board, i + 1, 0)) {
					return true;
				}
			} else {
				if(recursive(board, i, j + 1)) {
					return true;
				}
			}
		}
		return false;
	}

    void solveSudoku(vector<vector<char>>& board) {
    	recursive(board, 0, 0);
    	return;
    }
};