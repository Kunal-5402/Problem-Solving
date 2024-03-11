class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for(auto &it: s){
            m[it]++;
        }

        s = "";
        int i = 0;
        while(i < order.size()){
            while(m.find(order[i]) != m.end() and m[order[i]] > 0){
                s.push_back(order[i]);
                m[order[i]]--;
            }
            i++;
        }

        for(auto &it: m){
            while(it.second--){
                s.push_back(it.first);
            }
        }
        return s;
    }
};