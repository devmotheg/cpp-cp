/* Solution #1 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, smallest = prices[0];
        
        for (int price : prices) {
            if (price - smallest > profit) profit = price - smallest;
            if (price < smallest) smallest = price;
        }
        
        return profit;
    }
};

/* Solution #2 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, min = INT_MAX;
        
        for (int price : prices) {
            if (price < min) min = price;
            else max = std::max(max, price - min);
        }
        
        return max;
    }
};

/* Solution #3 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Kadane's algorithm

        int maxcurr = 0, maxfar = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            maxcurr = max(0, maxcurr += prices[i] - prices[i - 1]);
            maxfar = max(maxfar, maxcurr);
        }
        
        return maxfar;
    }
};
