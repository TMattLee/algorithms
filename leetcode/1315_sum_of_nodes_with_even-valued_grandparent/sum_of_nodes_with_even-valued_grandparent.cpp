// Level order traversal with tuple.
// Current node's value become next nodes' parent.
// Current node's parent become next nodes grand parent.
// If the current nodes grandparent is even then add the current nodes value to the total.

class Solution {
public:
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        queue< tuple<TreeNode*, int, int> > tpq;
        
        tuple<TreeNode *, int, int> current;
        
        tpq.push({root, -1, -1});
        
        int total = 0;
        
        TreeNode * temp;
        
        while(!tpq.empty()){
            int sz = tpq.size();
            current = tpq.front();
            tpq.pop();
            
            temp = get<0>(current);
            int target = get<2>(current);            
            
            if(target % 2 == 0) total += temp->val;
            
            int parent = temp->val;
            int gParent = get<1>(current);
            
            if(temp->left){
                tpq.push({temp->left, parent, gParent});
            }
            
            if(temp->right){
                tpq.push({temp->right, parent, gParent});
            }
            
        }
        
        return total;
    }
};
