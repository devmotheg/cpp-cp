/* Solution #1 */

class Solution {
    bool is_alphanumeric(int ascii) {
        if (ascii >= 65 && ascii <= 90 ||
            ascii >= 65 + 32 && ascii <= 90 + 32 ||
            ascii >= 48 && ascii <= 57) return true;
        
        return false;
    }
    
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); ++i) {
            s[i] = tolower(s[i]);
            
            if (!is_alphanumeric((int) s[i])) s.erase(i, 1), --i;
        }
        
        int i = 0, j = s.length() - 1;
        
        while (i <= j) if (s[i++] != s[j--]) return false;
        
        return true;
    }
};

/* Solution #2 */

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            while (isalnum(s[i]) == false && i < j) ++i;
            while (isalnum(s[j]) == false && i < j) --j;
            
            if (toupper(s[i]) != toupper(s[j])) return false;
        }
        
        return true;
    }
};
