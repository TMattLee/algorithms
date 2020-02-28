// Perform level order traversal while keeping track of the size of the queue during each iteration.
// Left most value should be a the front of each level.
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> tq;
        TreeNode* current;
        
        tq.push(root);
        
        int leftMost = 0;
        
        while(!tq.empty()){
            int sz = tq.size();
            leftMost = tq.front()->val;            
            while(sz--){
                current = tq.front();
                tq.pop();
                if(current->left) tq.push(current->left);
                if(current->right) tq.push(current->right);
                
            }
        }
        
        return leftMost;
    }
};
