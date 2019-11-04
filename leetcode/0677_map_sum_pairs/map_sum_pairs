typedef struct TrieNode{
    unordered_map<char, TrieNode*> children;
    int sum = 0;
    int val = 0;
} TrieNode;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        temp = root;
        for(char & c: key ){
            
            if(temp->children.find(c) == temp->children.end()) {
                temp->children[c] = new TrieNode();
                temp->children[c]->val = val;
                temp->children[c]->sum = val;
            } else {
                if(used.find(key) != used.end() ) { 
                    temp->children[c]->sum -= used[key];
                }
                temp->children[c]->sum += val;
            }
            
            temp = temp->children[c];
        }
        used[key] = val;
    }
    
    int sum(string prefix) {
        temp = root;
        for(char & c: prefix ){
            if(temp->children.find(c) == temp->children.end()) return 0;
            temp = temp->children[c];
        }
        
        return temp->sum;
    }
    
private:
    TrieNode * root;
    TrieNode * temp;
    unordered_map<string, int> used;
};


/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
