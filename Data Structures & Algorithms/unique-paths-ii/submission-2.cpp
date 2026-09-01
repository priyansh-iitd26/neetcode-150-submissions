class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1)
            return 0;

        vector<int> next(n + 1, 0);

        for(int i = m - 1; i >= 0; i--){

            vector<int> curr(n + 1, 0);
            
            for(int j = n - 1; j >= 0; j--){

                if(grid[i][j] == 1)
                    curr[j] = 0;

                else if(i == m - 1 && j == n - 1)
                    curr[j] = 1;

                else
                    curr[j] = next[j] + curr[j + 1];
            }

            next = curr;
        }

        return next[0];
    }
};
// tc -> O(m*n)
// sc -> O(n)