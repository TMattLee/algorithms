// Add items to be removed to a set.
// Use post order traversal.
// Return null if root is a member of deletion set.

class Solution {
public:
    
    vector<TreeNode*> ans;
    unordered_set<int> toDelete;
    
    TreeNode *  traverse(TreeNode* root){
        if(!root) return NULL;
        
        int test = root->val;
     
        root->left = traverse(root->left);
        root->right = traverse(root->right);
        
        if(toDelete.count(test) > 0){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);    
            return NULL;
        } 
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        TreeNode * temp = root;
        
        for(int i: to_delete){
            toDelete.insert(i);
        }
        
        if(toDelete.count(root->val) == 0) {             
            ans.push_back(root);    
        } 
        
        root = traverse(root);
        
        return ans;
    }
};
