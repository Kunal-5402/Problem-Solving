class Solution {
private:
    void next_smaller_element(vector<int> heights,int n,vector<int> &next){
        stack<int> s;
        s.push(-1);

        for(int i=n-1;i>=0;i--){
            while(s.top() != -1 and heights[s.top()] >= heights[i])
                s.pop();
            next[i]=s.top();
            s.push(i);
        }
    }
    void prev_smaller_element(vector<int> heights,int n,vector<int> &prev){
        stack<int> s;
        s.push(-1);

        for(int i=0;i<n;i++){
            while(s.top() != -1 and heights[s.top()] >= heights[i])
                s.pop();
            prev[i]=s.top();
            s.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next_smaller_element(heights,n,next);

        vector<int> prev(n);
        prev_smaller_element(heights,n,prev);

        int area = INT_MIN;

        for(int i=0;i<n;i++){
            
            int l = heights[i];

            if(next[i]==-1){
                next[i]=n;
            }

            int b = next[i]-prev[i]-1;

            area = max(area,l*b);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();

        int maxi = INT_MIN;

        vector<int> heights(nCol,0);
        for(int i=0;i<nRow;i++){
            for(int j=0;j<nCol;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }
            }
            maxi = max(maxi,largestRectangleArea(heights));
        }
        return maxi;
    }
};