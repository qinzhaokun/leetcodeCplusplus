struct node{
  node* children[26];
  bool end;
};
class WordDictionary {
private:node* root = new node();
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        node* now = root;
        for(int i = 0;i < word.length();i++){
            int index = word[i]-'a';
            if(now->children[index] == NULL) now->children[index] = new node();
            now = now->children[index];
        }
        now->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        node* now = root;
        return dfs(now,word);
    }
    
    bool dfs(node* t, string word){
        node* c = t;
        if(word.length() == 0){
            if(c != NULL && c->end) return true;
            else return false;
        }
        if(c == NULL) return false;
        if(word[0] == '.'){
            for(int i = 0;i < 26;i++){
                if(dfs(c->children[i],word.substr(1))) return true;
            }
            return false;
        }
        else{
            int index = word[0]-'a';
            if(c->children[index] == NULL) return false;
            else return dfs(c->children[index],word.substr(1));
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
