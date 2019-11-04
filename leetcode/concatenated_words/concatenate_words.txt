typedef struct TrieNode{
    bool isWord = false;
    unordered_map<char, TrieNode*> children;
} TrieNode;

class Solution {
public:
    
    TrieNode * root = new TrieNode();
    TrieNode * temp;
    
    void insert(string & word){
        temp = root;
        for(char  c: word){
            if(temp->children.find(c) == temp->children.end()) temp->children[c] = new TrieNode();
            temp = temp->children[c];
        }
        temp->isWord = true;
    }
    
    bool search(string & word, int start, TrieNode * searchNode, int count){
        if(start >= word.length()){
            return count > 1;
        }
        
        temp = searchNode;
        
        char c;
                
        bool isConcat = false;
        
        for(int i = start; i < word.length(); i++){
            c = word[i];
            if(temp->children.find(c) == temp->children.end()) return 0;
            temp = temp->children[c];
            if(temp->isWord){
                isConcat = search(word, i + 1, temp, count) || search(word, i + 1, root, count + 1);
                break;
            }
        }        
        
        return isConcat;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {        vector<string> ans;
        for(string & word: words){
            insert(word);
        }
        
        for(string & word: words){
            if(search(word, 0, root, 0) ) ans.push_back(word);
        }
        
        return ans;
    }

};
