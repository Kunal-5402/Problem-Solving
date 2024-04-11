class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        string ans = "";

        s.push(num[0]);

        for(int i=1;i<n;i++){

            while(k>0 and s.size() > 0 and s.top() > num[i]){
                s.pop();
                k--;
            }

            s.push(num[i]);

            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }

        while(k > 0 and s.size() > 0){
            k--;
            s.pop();
        }

        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans == "" ? "0" : ans;
    }
};