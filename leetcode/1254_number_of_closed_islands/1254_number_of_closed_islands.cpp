class Solution {
public:
    // Intitial solution used the outer rim as an exclusion zone name 'danger'.
    // Code was later optimitised to work without the extra memory.
    // Search through graph when grid[i][j] = 0. Transform all searched positions to -1.
    // If graph cannot be altered an N X M grid of booleans can be created.
    
    /* 
    bool search(vector<vector<int>>& grid, int i, int j, vector< vector<bool> > & danger){
        if(danger[i][j] == true || i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        if(grid[i][j] == -1) return true;
                                                                                          
        grid[i][j] = -1;
        bool a,b,c,d;
        a = b = c = d = true;
        
        if(i + 1 < grid.size()      && grid[i + 1][j] == 0) a = search(grid, i + 1, j, danger);
        if(j + 1 < grid[0].size()   && grid[i][j + 1] == 0) c = search(grid, i, j + 1, danger);
        
        if(i - 1 >= 0               && grid[i - 1][j] == 0) b = search(grid, i - 1, j, danger);        
        if(j - 1 >= 0               && grid[i][j - 1] == 0) d = search(grid, i, j - 1, danger);
                                                                                          
            
        return a && b && c && d;
    }
    */
    
    bool search(vector<vector<int>>& grid, int i, int j){
        if( i < 1 || j < 1 || i + 1 >= grid.size()  || j + 1 >= grid[0].size()) return false;
        if(grid[i][j] == -1) return true;
                                                                                          
        grid[i][j] = -1;
        bool a,b,c,d;
        a = b = c = d = true;
        
        if(i + 1 < grid.size()      && grid[i + 1][j] == 0) a = search(grid, i + 1, j);
        if(j + 1 < grid[0].size()   && grid[i][j + 1] == 0) c = search(grid, i, j + 1);
        
        if(i - 1 >= 0               && grid[i - 1][j] == 0) b = search(grid, i - 1, j);        
        if(j - 1 >= 0               && grid[i][j - 1] == 0) d = search(grid, i, j - 1);
                                                                                          
            
        return a && b && c && d;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        //vector< vector<bool> > danger(grid.size(), vector<bool>(grid[0].size(), false));
        
        
        
        /*for(int i = 0; i < grid.size(); i++){
            danger[i][0] = true;
            danger[i][grid[0].size() -1] = true;
        }
        
        for(int i = 0; i < grid[0].size(); i++){
            danger[0][i] = true;
            danger[grid.size() - 1][i] = true;
        }*/
        
        
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    //if(search(grid, i, j, danger)) count++;
                    if(search(grid, i, j)) count++;
                }
            }
        }
        
        return count;
    }
};
