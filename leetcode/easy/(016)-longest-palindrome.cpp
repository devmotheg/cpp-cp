/* Solution #1 */

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> reps;
        int mono = 0, di = 0;
        
        for (char c : s) {
            if (++reps[c] == 2) reps[c] = 0, di++, mono--;
            else mono++;
        }
        
        return di * 2 + (mono ? 1 : 0);
    }
};

/* Solution #2 */

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> odds;
        for (char c : s) if (odds.count(c)) odds.erase(c); else odds.insert(c);
        return s.length() - odds.size() + (odds.size() ? 1 : 0);
    }
};

/* Solution #3 */

class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        
        for (char c = 'A'; c <= 'z'; c++) {
            if ((int) c == 91) c = 97;
            
            odds += count(s.begin(), s.end(), c) & 1;
        }
        
        return s.length() - odds + (odds > 0);
    }
};

/* Solution #4 */

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0, freq[123] = { };
        for (char c : s) if (++freq[c] % 2 == 0) ans += 2;
        return s.length() > ans ? ans + 1 : ans;
    }
};

/* Solution #5 */

class Solution {
public:
    int longestPalindrome(string s) {
        int longest_palindrome = 0, freq[56] = { 0 };
        bool isodd = false;
        
        for (char c : s)
            if (c <= 'Z') freq[c - 'A']++;
            else freq[c - 'a' + 26]++;
        
        for (int* start = freq; start < freq + 56; start++) {
            longest_palindrome += *start / 2;
            
            if (*start & 1) isodd = true;
        }
        
        return isodd ? 1 + 2 * longest_palindrome : 2 * longest_palindrome;
    }
};
