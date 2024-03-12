class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {

        int n = grid.size();

        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count_0++;
                else if (grid[i][j] == 1)
                    count_1++;
                else
                    count_2++;
            }
        }

        int count_0_y = 0;
        int count_1_y = 0;
        int count_2_y = 0;

        for (int i = 0; i < n / 2; i++) {
            if (grid[i][i] == 0)
                count_0_y++;
            else if (grid[i][i] == 1)
                count_1_y++;
            else if (grid[i][i] == 2)
                count_2_y++;
        }
        for (int i = 0; i < n / 2; i++) {
            if (grid[i][n - i - 1] == 0)
                count_0_y++;
            else if (grid[i][n - i - 1] == 1)
                count_1_y++;
            else if (grid[i][n - i - 1] == 2)
                count_2_y++;
        }
        for (int i = 0; i <= n / 2; i++) {
            if (grid[i + n / 2][n / 2] == 0)
                count_0_y++;
            else if (grid[i + n / 2][n / 2] == 1)
                count_1_y++;
            else if (grid[i + n / 2][n / 2] == 2)
                count_2_y++;
        }

        count_0 = count_0 - count_0_y;
        count_1 = count_1 - count_1_y;
        count_2 = count_2 - count_2_y;

        int sum1 = count_0 + count_1 + count_2;
        int sum2 = count_0_y + count_1_y + count_2_y;
        int ans = INT_MAX;

        int n1 = sum1 - count_0;
        int n2 = sum2 - max(count_1_y, count_2_y);
        ans = min(ans, n1 + n2);

        n1 = sum1 - count_1;
        n2 = sum2 - max(count_0_y, count_2_y);
        ans = min(ans, n1 + n2);

        n1 = sum1 - count_2;
        n2 = sum2 - max(count_0_y, count_1_y);
        ans = min(ans, n1 + n2);

        return ans;
    }
};