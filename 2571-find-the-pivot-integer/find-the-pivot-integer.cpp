class Solution {
public:
    int pivotInteger(int n) {

        for(int i=1;i<=n;i++){
            int prefix = 0;
            int suffix = 0;
            for(int j=1;j<=i;j++){
                prefix+=j;
            }
            for(int k=i;k<=n;k++){
                suffix+=k;
            }
            if(prefix == suffix)
                return i;
        }
        return -1;
    }
};