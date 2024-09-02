class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int index = 0;
        int n  = chalk.size();

        int sum = 0;
        for(auto &it: chalk){
            sum += it;
            if(sum > k){
                break;
            }
        }
        
        k %= sum;

        while(1){
            if(k < chalk[index%n])
                break;
            k -= chalk[index%n];
            index++;
        }

        return (index%n);
    }
};