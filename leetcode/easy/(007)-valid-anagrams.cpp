/* Solution #1 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, pair<int, int>> ocu;
        
        for (char c : s) ++ocu[c].first;
        for (char c : t) ++ocu[c].second;
        
        for (unordered_map<char, pair<int, int>>::iterator itr = ocu.begin();
             itr != ocu.end();
             ++itr)
             if (itr->second.first != itr->second.second) return false;
        
        return true;
    }
};

/* Solution #2 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() < s.length()) swap(s, t);
        
        int chars[26] = { 0 };
        
        for (int i = 0; i < s.length(); ++i) ++chars[s[i] - 'a'];
        for (int i = 0; i < t.length(); ++i) if (--chars[t[i] - 'a'] < 0) return false;
        
        return true;
    }
};

/* Solution #3 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end()); sort(t.begin(), t.end());
        return s == t;
    }
};
