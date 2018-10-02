class Solution {
public:
	bool debug = false;
	bool checkPivot(int x, int target) {
        if(debug) {
             cout << "x: " << x << " target: " << target << endl;
        }
       
		if(x >= target) {
			return true;
		} else {
			return false;
		}
	}

	int binarySearch(vector<int>& nums, int start, int end, int target) {
		int mid = 0;
		while(start < end) {
			mid = (start + end + 1) / 2;
			if(debug) {
				cout << "1 start: " << start << " end: " << end << " mid: " << mid << " target: "<< target << endl; 
			}
			if(checkPivot(nums[mid], target)) {
				start = mid;
			} else {
				end = mid - 1;
			}
			if(debug) {
				cout << "2 start: " << start << " end: " << end << " mid: " << mid << endl; 
			}
		} 
		return start;
	}

	int search(vector<int>& nums, int start, int end, int target) {
		while(start <= end) {
			int mid = (start + end) / 2;
            if(debug) {
				cout << "3 start: " << start << " end: " << end << " mid: " << mid << endl; 
			}
			if(nums[mid] == target) {
				return mid;
			} else if(nums[mid] > target) {
				end = mid - 1;
			} else {	
				start = mid + 1;
			}
			if(debug) {
				cout << "4 start: " << start << " end: " << end << " mid: " << mid << endl; 
			}
		}
		return -1;
	}

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        int pivot = binarySearch(nums, 0, nums.size() - 1, nums[0]);
        if(debug) {
            cout << "pivot is: " << pivot << endl;    
        }
        if(pivot == nums.size() - 1) {
        	return search(nums, 0, pivot, target);
        }
        
        int searchLeft = search(nums, 0, pivot, target);
        int searchRight = search(nums, pivot + 1, nums.size() - 1, target);
        if(searchLeft != -1) {
            return searchLeft;
        } else if(searchRight != -1) {
            return searchRight;
        }
        //return search(nums, 0, pivot, target) || search(nums, pivot + 1, nums.size() - 1, target);
        return -1;
    }
};