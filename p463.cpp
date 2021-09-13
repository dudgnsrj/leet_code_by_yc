class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer = 0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == 1){
                    answer += 4;
                    if (i > 0)
                        answer -= grid[i-1][j];
                    if (i < grid.size()-1)
                        answer -= grid[i+1][j];
                    if (j > 0)
                        answer -= grid[i][j-1];
                    if (j < grid[i].size()-1)
                       answer -= grid[i][j+1];
                }
            }
        }
        
        return answer;
    }
};
