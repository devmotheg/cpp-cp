/* Solution #1 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cntr;
        
        for (int n : nums) if (++cntr[n] > nums.size() / 2) return n;
        
        return -1;
    }
};

/* Solution #2 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int answ[2] = { }, cand[2] = { nums[0], 0 };
        
        for (int i = 0; i <= nums.size(); ++i) {
            if (i < nums.size() && nums[i] == cand[0]) ++cand[1];
            else {
                if (cand[1] > answ[1]) copy(cand, cand + 2, answ);
                cand[0] = nums[i < nums.size() ? i : i - 1], cand[1] = 1;
            }
        }
        
        return answ[0];
    }
};

/* Solution #3 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};

/* Solution #4 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer–Moore majority vote algorithm

        int major = nums[0], votes = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (!votes) major = nums[i];
            
            votes += major == nums[i] ? +1 : -1;
        }
        
        return major;
    }
};

/* Solution #5 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        
        for (unsigned int i = 0, mask = 1; i < 32; ++i, mask <<= 1) {
            int ith_set_bit_count = 0;
            
            // Mask is just `1 << i`
            for (int n : nums) if (n & mask) ++ith_set_bit_count;
            
            // Can also use `majority += (1 << i)`
            if (ith_set_bit_count > nums.size() / 2) majority |= mask;
        }
        
        return majority;
    }
};

/* Solution #6 */

class Solution {
    int conquer(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        
        int middle = left + ceil((float) (right - left) / 2),
            left_majority = conquer(nums, left, middle - 1),
            right_majority = conquer(nums, middle, right);
        
        if (left_majority == right_majority) return left_majority;
        
        return count(nums.begin() + left, nums.begin() + right + 1, left_majority) >
            count(nums.begin() + left, nums.begin() + right + 1, right_majority) ?
            left_majority : right_majority;
    }
    
public:
    int majorityElement(vector<int>& nums) {
        return conquer(nums, 0, nums.size() - 1);
    }
};
