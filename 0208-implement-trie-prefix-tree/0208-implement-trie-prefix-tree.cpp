class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;
    TrieNode(char d){
        data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {
public:
    TrieNode*root;
    /** Initialize your data structure here. */
    Trie() {
    root=new TrieNode('\0');

    }
    void insertUtil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        char ch=word[0];
        int index=ch-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(ch);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        char ch=word[0];
        int index=ch-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);
    }
    bool startUtil(TrieNode*root,string word){
        if(word.length()==0){
            return true;
        }
        char ch=word[0];
        int index=ch-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return startUtil(child,word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startUtil(root,prefix);
    }
};