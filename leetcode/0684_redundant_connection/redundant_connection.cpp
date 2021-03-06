class Solution {
public:
    
    // Use union-find. In the case where two items you inputing
    // have the same parent you have found the cyle.
    
    
    vector<int> parent;
    
    
    int find(int i){
        if(i == parent[i]) return i;
        return find(parent[i]);
    }
    
    bool doUnion(int i, int j){
        int x = find(i);
        int y = find(j);
        if(x == y) return false;
        
        if(x < y){
            parent[i] = x;
            parent[j] = x;
            parent[y] = x;
        } else {
            parent[i] = y;
            parent[j] = y;
            parent[x] = y;
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() * 2 + 1, -1);
        
        vector<int> ans;
        
        for(auto & v: edges){
            parent[ v[0] ] = v[0]; 
            parent[ v[1] ] = v[1]; 
        }
        
        for(auto & v: edges){
            if(!doUnion(v[0], v[1])){
                ans = v;
                break;
            }
            
        }

        return ans;        
    }
};
