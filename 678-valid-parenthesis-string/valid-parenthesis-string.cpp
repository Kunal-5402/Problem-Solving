class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int open = 0;
        int close = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' or s[i] == '*')
                open++;
            else
                open--;
            if (open < 0)
                return false;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' or s[i] == '*')
                close++;
            else
                close--;
            if (close < 0)
                return false;
        }
        
        return true;
    }
};