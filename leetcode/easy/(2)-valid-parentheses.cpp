/* Solution #1 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } else if (stack.empty()) {
                return false;
            } else if (s[i] == ')' && stack.top() == '(' ||
                       s[i] == ']' && stack.top() == '[' ||
                       s[i] == '}' && stack.top() == '{') {
                stack.pop();
            } else {
                return false;
            }
        }
        
        return stack.empty() ? true : false;
    }
};

/* Solution #2 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (char c : s) {
            if (c == '(') stack.push(')');
            else if (c == '[') stack.push(']');
            else if (c == '{') stack.push('}');
            else if (stack.empty() || stack.top() != c) return false;
            else stack.pop();
        }
        
        return stack.empty();
    }
};

/* Solution #3 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (char c : s) {
            switch (c) {
                    case '(': stack.push(')'); break;
                    case '[': stack.push(']'); break;
                    case '{': stack.push('}'); break;
                    default:
                        if (stack.empty() || stack.top() != c) return false; else stack.pop();
            }
        }
        
        return stack.empty();
    }
};

/* Solution #4 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (char c : s) {
            switch (c) {
                    case ')':
                        if (stack.empty() || stack.top() != '(')
                            return false;
                        stack.pop();
                        break;
                    case ']':
                        if (stack.empty() || stack.top() != '[')
                            return false;
                        stack.pop();
                        break;
                    case '}':
                        if (stack.empty() || stack.top() != '{')
                            return false;
                        stack.pop();
                        break;
                    default: stack.push(c);
            }
        }
        
        return stack.empty();
    }
};
