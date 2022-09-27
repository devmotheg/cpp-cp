/* Solution #1 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid - 1;
            else return mid;
        }
        
        return -1;
    }
};

/* Solution #2 */

class Solution {
    int binary(vector<int>& nums, int target, int lo, int hi) {
        if (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) return binary(nums, target, mid + 1, hi);
            if (nums[mid] > target) return binary(nums, target, lo, mid - 1);
            if (nums[mid] == target) return mid;
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size() - 1);
    }
};
