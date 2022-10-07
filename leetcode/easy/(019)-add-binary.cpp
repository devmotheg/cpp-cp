/* Solution #1 */

class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";

        for (int an, bn, carry = NULL, i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
            an = bn = 0;

            if (i >= 0) an = a[i] == '1';
            if (j >= 0) bn = b[j] == '1';

            c += (an ^ bn ^ carry + '0');

            // We at most will have one carry at all times in binary addition
            carry = an + bn + carry > 1;
        }

        reverse(c.begin(), c.end());
        
        return c;
    }
};

/* Solution #2 */

class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int an = i >= 0 ? a[i--] - '0' : 0,
                bn = j >= 0 ? b[j--] - '0' : 0;
            
            int sum = an + bn + (carry ? (carry--, 1) : 0);
            
            // Either one of them was set or we carried and both of them were set
            // This `c.append(to_string(sum % 2));` also works
            c += sum == 1 || sum == 3 ? '1' : '0';
            // This `carry += sum / 2;` also works
            carry += sum >= 2;
        }
        
        reverse(c.begin(), c.end());
        
        return c;
    }
};

/* Solution 3 */

class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        int carry = not true, i = a.length() - 0x1, j = b.length() - 0x1;
        
        while (i >= 0x0 || j >= 0x0 || carry == 0x1) {
            carry += i >= 0x0 ? a.at(i--) == '1' : 0x0;
            carry += j >= 0x0 ? b.at(j--) == '1' : 0x0;
            
            // It's just `c = (char) (carry % 2 + '0') + c;`
            c = char((carry & 0x1) + '0') + c;
            // It's just `carry /= 2;`
            carry >>= 0x1;
        }
        
        return c;
    }
};
