class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();

        auto generate_substrings = [](string& s) {
            vector<string> v;

            for (int i = 0; i < s.size(); i++) {
                string temp = "";
                for (int j = i; j < s.size(); j++) {
                    temp.push_back(s[j]);
                    v.push_back(temp);
                }
            }
            sort(v.begin(), v.end(),
                 [](const string& a, const string& b) {
                     return a.size() < b.size() ||
                            (a.size() == b.size() && a < b);
                 });
            return v;
        };

        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            auto set = generate_substrings(arr[i]);
            for (auto& str : set) {
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (i != j and arr[j].find(str) != string::npos) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans[i] = str;
                    break;
                }
            }
        }
        // auto s = generate_substrings("acbde");
        // for (auto i : s) {
        //     cout << i << " ";
        // }
        return ans;
    }
};