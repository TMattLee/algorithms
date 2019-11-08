typedef struct TrieNode{
    bool isEnd = false;
    unordered_map<char, TrieNode*> children;
} TrieNode;

class Solution {
public:
    
    TrieNode * root = new TrieNode();
    TrieNode * temp;
    
    
    bool isCap(char & c){
        return c >= 'A' && c <= 'Z';
    }
    
    void insert(string word) {
        temp = root;
        for(char & c: word){
            if(temp->children.find(c) == temp->children.end()) temp->children[c] = new TrieNode();
            temp = temp->children[c];
        }
        temp->isEnd = true;
    }
    
    bool isMatch(string & q){
        
        temp = root;
        
        bool found = false;
        
        for(char & c: q){
            
            if(found && isCap(c)) return false;
            
            if(temp->children.find(c) == temp->children.end()) {
                if(isCap(c)) return false;
                continue;
            }
            
            temp = temp->children[c]; 
            
            if(temp->isEnd) {
                
                found = true;
                
            }
        }
        
        return found;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        
        insert(pattern);
        
        for(string & q: queries){
            
            if(isMatch(q))ans.push_back(true);
            else ans.push_back(false);
            
        }
        
        return ans;
    }
    
};
