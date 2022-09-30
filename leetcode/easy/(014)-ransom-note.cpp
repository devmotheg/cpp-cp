/* Solution #1 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> reps(26);
        for (char ltr : magazine) reps[ltr]++;
        for (char ltr : ransomNote) if (--reps[ltr] < 0) return false;
        return true;
    }
};

/* Solution #2 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::multiset<char> ran(ransomNote.begin(), ransomNote.end()),
                            mag(magazine.begin(), magazine.end());
        return std::includes(mag.begin(), mag.end(), ran.begin(), ran.end());
    }
};

/* Solution #3 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char c : unordered_set<char> (ransomNote.begin(), ransomNote.end()))
            if (count(ransomNote.begin(), ransomNote.end(), c) > count(magazine.begin(), magazine.end(), c))
                return false;
        return true;
    }
};
