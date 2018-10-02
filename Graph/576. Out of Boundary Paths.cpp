class Solution {
public:
	int move_x[4] = {1, -1, 0, 0};
	int move_y[4] = {0, 0, 1, -1};

	void recursive(int m, int n, int N, int i, int j, int &result, int &step) {
        if(step > N)
    		return;
        
		if(i < 0 || j < 0 || i >= m || j >= n) {
			result++;
    		return;
		}

    	for(int k = 0; k < 4; k++) {
            step++;
        	recursive(m, n, N, i + move_x[k], j + move_y[k], result, step);
            step--;
        }
        return;
	}

    int findPaths(int m, int n, int N, int i, int j) {
    	int result = 0;
        int step = 0;
    	recursive(m, n, N, i, j, result, step);
    	return result;
    }
};