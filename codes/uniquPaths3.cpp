class Solution {
public:
    int sol = 0;
    
    void dfs(int x, int y, vector<vector<int>>& grid, int count, int total) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1)
            return;
        if(grid[x][y] == 2 and count == total) {
            sol++;
            return;
        }
        if(grid[x][y] == 2 and count != total)
            return;
        if(total >= count)
            return;
        
        grid[x][y] = -1;
        dfs(x + 1, y, grid, count, total + 1);
        dfs(x - 1, y, grid, count, total + 1);
        dfs(x, y + 1, grid, count, total + 1);
        dfs(x, y - 1, grid, count, total + 1);
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int count = 0;
        int x, y;
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == 0)
                    count++;
                else if(grid[row][col] == 1)
                    x = row, y = col;
            }
        }
        
        dfs(x, y, grid, count + 1, 0);
        return sol;
    }
};