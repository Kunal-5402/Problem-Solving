class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int i,int j, vector<vector<bool>> &visited){
            if(visited[i][j])
                return;
            
            visited[i][j] = true;

            if(i + 1 < rows and grid[i+1][j] >= grid[i][j])
                dfs(i+1,j,visited);
            if(j + 1 < cols and grid[i][j+1] >= grid[i][j])
                dfs(i,j+1,visited);
            if(i - 1 >= 0 and grid[i-1][j] >= grid[i][j])
                dfs(i-1,j,visited);
            if(j - 1 >= 0 and grid[i][j-1] >= grid[i][j])
                dfs(i,j-1,visited);
        };


        for(int i=0;i<rows;i++){
            dfs(i, 0, atlantic);
            dfs(i, cols-1, pacific);
        }
        for(int j=0;j<cols;j++){
            dfs(0, j, atlantic);
            dfs(rows-1, j, pacific);
        }

        vector<vector<int>> ans;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};