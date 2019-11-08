typedef struct TrieNode{
    bool isWord = false;
    int frequency = 0;
    unordered_map<char, TrieNode*> children;
} TrieNode;

class Solution {
public:
    
    TrieNode * root;
    TrieNode * temp;
    
    
    unordered_map<string, int> frequencyMap;
    
    Solution(){
        root = new TrieNode();
    }    
    
    bool comp(string & a, string & b){
        return frequencyMap[a] < frequencyMap[b];
    }
    
    void insert(string & word){
        temp = root;
        for(char & c: word){
            if(temp->children.find(c) == temp->children.end()) {
                temp->children[c] = new TrieNode();
            }
            temp = temp->children[c];
        }
        
        temp->isWord = true;
        temp->frequency++;
        frequencyMap[word] = temp->frequency;
    }    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        vector<pair<string, int> > vec;
                
        auto l = [this](const pair<string, int> & a, const pair<string, int> & b) -> bool{
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        };
        
        make_heap(vec.begin(), vec.end(), l);

        // Trie solution -- much slower. 
        // for(string & word: words){
        //     insert(word);
        // }
        
        for(string & word: words){
            frequencyMap[word]++;   
        }
        
        for(auto p: frequencyMap){
            vec.push_back(p);
            push_heap(vec.begin(), vec.end(),l);
            if(vec.size() > k) {
                pop_heap(vec.begin(), vec.end(),l);
                vec.pop_back();
            }
        }
        
        pair<string, int> temp;        
        
        while(!vec.empty()){
            pop_heap(vec.begin(), vec.end(), l);            
            ans.push_back(vec.back().first);
            vec.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
                
        return ans;
    }
};
