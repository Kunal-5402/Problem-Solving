class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        vector<bitset<26>> v(n);

        for(int i = 0; i < n; i++){
            for(auto &it: words[i]){
                v[i].set(it - 'a');
            }

            for(int j = 0; j < i; j++){
                if((v[i] & v[j]).none()){
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;
    }
};
