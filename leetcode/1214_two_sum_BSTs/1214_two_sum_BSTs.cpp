class Solution {
public:
    
    void insert(TreeNode* root, vector<int> & vec){
        if(root == NULL) return;
        
        insert(root->left, vec);
        vec.push_back(root->val);
        insert(root->right, vec);
    }    
    
    TreeNode* nextLeft(TreeNode * currLeft, stack<TreeNode*> & left){
        while(currLeft){
            left.push(currLeft);
            currLeft = currLeft->left;
        }
        
        currLeft = left.top();
        left.pop();
        return currLeft;
    }
    
    TreeNode * nextRight(TreeNode * currRight, stack<TreeNode*> & right){
        while(currRight){
            right.push(currRight);
            currRight = currRight->right;
        }
            
        currRight = right.top();
        right.pop();
        return currRight;
    }        
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1 || !root2) return false;
        
        //Recursive solution. Dump both into separate arrays using inorder traversal.
        /*--------------------------------
        vector<int> low;
        vector<int> high;
        
        if(root1->val <= root2->val){            
            insert(root1, low);
            insert(root2, high);
        } else {
            insert(root1, low);
            insert(root2, high);
        }
        
        int i = 0;
        int j = high.size() - 1;
        
        int total;
        
        while(i < low.size() && j >= 0){
            total = low[i] + high[j];
            if(total == target ){
                return true;
            } else if(total > target){
                j--;
            } else {
                i++;
            }
        }*/
        
        // Iterative solution
        // one stack inorder the other stack reverse inorder.
        stack<TreeNode*> left;
        stack<TreeNode*> right;
        
        TreeNode * currLeft;
        TreeNode * currRight;
        
        int total;
        
        if(root1->val <= root2->val){
            currLeft = root1;
            currRight = root2;
        } else {
            currLeft = root2;
            currRight = root1;
        }
        
        left.push(NULL);
        right.push(NULL);
        
        currLeft = nextLeft(currLeft, left);
        currRight = nextRight(currRight, right);
                
        while(!left.empty() && !right.empty()){
            //cout << currLeft->val << " " << currRight->val <<endl;
            total = currLeft->val + currRight->val;          
            if(total == target) {
                return true;
            } else if(total > target){
                currRight = nextRight(currRight->left, right);
            } else {
                currLeft = nextLeft(currLeft->right, left);
            }
        }        
        
        return false;
        
    }
};
