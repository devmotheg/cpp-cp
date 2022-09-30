/* Solution #1 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int j = n, i = 1, f;
        
        while (j >= i) {
            int k = (j - i) / 2 + i;
            if (isBadVersion(k)) j = k - 1, f = k;
            else i = k + 1;
        }
        
        return f;
    }
};

/* Solution #2 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int find(int below, int above) {
        if (below == above) return below;
        
        int middle = below + (above - below) / 2;
        
        if (not isBadVersion(middle)) below = middle + 1;
        else above = middle;
        
        return find(below, above);
    }
    
public:
    int firstBadVersion(int n) {
        return find(1, n);
    }
};
