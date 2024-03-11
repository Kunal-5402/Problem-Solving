class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        int ans = 0;

        vector<bitset<26>> v(n);

        for(int i=0;i<n;i++){

            for(auto &it: words[i])
                v[i][it-'a'] = 1;

            for(int j=0;j<i;j++){
                
                bool flag = true;

                for(int k=0;k<26;k++){
                    if(v[i][k] && v[j][k]){
                        flag = false;
                        break;
                    }
                }

                if(flag)
                    ans = max(ans,int(words[i].size() * words[j].size()));
            }
        }

        return ans;
    }
};