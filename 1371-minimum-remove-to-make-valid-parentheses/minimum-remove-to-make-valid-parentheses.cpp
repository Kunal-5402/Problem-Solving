class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> index;
        stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(s[i]);
            }
            if (s[i] == ')') {
                if (stack.size() > 0 and stack.top() == '(')
                    stack.pop();
                else
                    index.insert(i);
            }
        }

        while(stack.size() > 0){
            stack.pop();
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                stack.push(s[i]);
            }
            if (s[i] == '(') {
                if (stack.size() > 0 and stack.top() == ')')
                    stack.pop();
                else
                    index.insert(i);
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (index.count(i))
                continue;
            ans.push_back(s[i]);
        }

        return ans;
    }
};