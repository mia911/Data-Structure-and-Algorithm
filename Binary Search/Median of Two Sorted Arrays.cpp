class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) const;
    int findNumWithAtMostKSmallerNums(const vector<int>& nums1, const vector<int>& nums2, int k) const;
    int countNumsSmallerThanX(const vector<int>& nums, int x) const;
};

class Checker {
public:
    virtual bool check(int val) const = 0;
};

class BinarySearcher {
public:
    int binarySearchTF(int low, int high, const Checker& checker) const;
};

class CheckerNumsValSmallerThanX : public Checker {
private:
    vector<int> nums;
    int x;
    
public:
    CheckerNumsValSmallerThanX(const vector<int>& nums, int x);
    virtual bool check(int val) const;
};

class CheckerCountSmallerThanValNotSmallerThanK : public Checker {
private:
    vector<int> nums1;
    vector<int> nums2;
    int k;
    Solution solution;
    
public:
    CheckerCountSmallerThanValNotSmallerThanK(const vector<int>& nums1, const vector<int>& nums2, int k, const Solution& solution);
    virtual bool check(int val) const;
};

double Solution::findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) const {
    if(nums1.empty() && nums2.empty()) {
        return 0;
    }
    else if(nums1.empty()) {
        return (double)(nums2.at((nums2.size() - 1) / 2) + nums2.at(nums2.size() / 2)) / 2;
    }
    else if(nums2.empty()) {
        return (double)(nums1.at((nums1.size() - 1) / 2) + nums1.at(nums1.size() / 2)) / 2;
    }
    int leftMedian = findNumWithAtMostKSmallerNums(nums1, nums2, (nums1.size() + nums2.size() - 1) / 2);
    int rightMedian = findNumWithAtMostKSmallerNums(nums1, nums2, (nums1.size() + nums2.size()) / 2);
    return (double)(leftMedian + rightMedian) / 2;
}

int Solution::findNumWithAtMostKSmallerNums(const vector<int>& nums1, const vector<int>& nums2, int k) const {
    int low = min(nums1.front(), nums2.front());
    int high = max(nums1.back(), nums2.back());
    CheckerCountSmallerThanValNotSmallerThanK checker(nums1, nums2, k, *this);
    BinarySearcher binarySearcher;
    return binarySearcher.binarySearchTF(low, high, checker);
}

int Solution::countNumsSmallerThanX(const vector<int>& nums, int x) const {
    int low = 0;
    int high = nums.size() - 1;
    CheckerNumsValSmallerThanX checker(nums, x);
    BinarySearcher binarySearcher;
    return binarySearcher.binarySearchTF(low, high, checker) + 1;
}

int BinarySearcher::binarySearchTF(int low, int high, const Checker& checker) const {
    while(low < high) {
        int mid = (low + high + 1) / 2;
        if(checker.check(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    if(!checker.check(low)) {
        return low - 1;
    }
    return low;
}

CheckerNumsValSmallerThanX::CheckerNumsValSmallerThanX(const vector<int>& nums, int x) {
    this->nums = nums;
    this->x = x;
}

bool CheckerNumsValSmallerThanX::check(int val) const {
    return nums[val] < x;
}

CheckerCountSmallerThanValNotSmallerThanK::CheckerCountSmallerThanValNotSmallerThanK(const vector<int>& nums1, const vector<int>& nums2, int k, const Solution& solution) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    this->k = k;
    this->solution = solution;
}

bool CheckerCountSmallerThanValNotSmallerThanK::check(int val) const {
    return solution.countNumsSmallerThanX(nums1, val) + solution.countNumsSmallerThanX(nums2, val) <= k;
}