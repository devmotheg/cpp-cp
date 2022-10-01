/* Solution #1 */

class Solution {
    unordered_map<int, int> cache;
    
public:
    int climbStairs(int n, int steps = 0) {
        if (cache.find(steps) != cache.end()) return cache[steps];
        if (steps > n) return 0; else if (steps == n) return 1;
        return (cache[steps] = climbStairs(n, steps + 1) + climbStairs(n, steps + 2));
    }
};

/* Solution #2 */

class Solution {
    unordered_map<int, int> memo = { { 1, 1 }, { 2, 2 } };
    
public:
    int climbStairs(int n) {
        if (memo.count(n)) return memo.at(n);
        memo.insert(make_pair(n, climbStairs(n - 1) + climbStairs(n - 2)));
        return memo.at(n);
    }
};

/* Solution #3 */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        vector<int> dp(n + 1, 0); dp[1] = 1, dp[2] = 2;
        
        for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};

/* Solution #4 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int all_ways = 0, one_step_back = 2, two_steps_back = 1;
        
        for (int i = 2; i < n; i++) {
            all_ways = one_step_back + two_steps_back;
            two_steps_back = one_step_back;
            one_step_back = all_ways;
        }
        
        return all_ways;
    }
};

/* Solution #5 */

class Solution {
public:
    int climbStairs(int n) {
        long int a = 1; int b = 1;
        while (n--)
            a = (b += a) - a;
        return a;
    }
};
