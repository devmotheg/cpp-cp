/* Solution #1 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                
                if (nums[i] + nums[j] == target) return { i, j };
            }
        }
        
        return { };
    }
};

/* Solution #2 */

template<typename Dynamic>
bool comparator(Dynamic x, Dynamic y) {
    return x.second < y.second;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_copy;
        
        for (int i = 0; i < nums.size(); ++i)
            nums_copy.push_back({ i, nums[i] });
        
        sort(nums_copy.begin(), nums_copy.end(), comparator<pair<int, int>>);
        
        int i = 0, j = nums.size() - 1;
        
        while (i < j) {
            if (nums_copy[i].second + nums_copy[j].second < target) ++i;
            else if (nums_copy[i].second + nums_copy[j].second > target) --j;
            else return { nums_copy[i].first, nums_copy[j].first };
        }
        
        return { };
    }
};

/* Solution #3 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(target - nums[i])) return { map[target - nums[i]], i };
            else map[nums[i]] = i;
        }
        
        return { };
    }
};
