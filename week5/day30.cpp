/*
Word Search II

Solution
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
   Hide Hint #1  
You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
   Hide Hint #2  
If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
*/
class Solution {    
    struct node{    //TrieNode
        char c;
        int ends;
        string word;
        node *child[26];
    };
    struct node *getNode(char c)    //get newnode
    {
        node *newnode = new node;
        newnode->c = c;
        newnode->ends = 0;
        newnode->word = "";
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    node *root = getNode('/');  //root
    
    //Trie INSERT
    void insert(string s)
    {
        node *curr=root;
        int index,i=0;
        while(s[i])
        {
            index = s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = getNode(s[i]);
            
            curr=curr->child[index];
            i+=1;
        }
        curr->ends += 1;
        curr->word = s;
    }
    
    void solve(vector<vector<char>>& board,int i,int j,int r,int c,vector<string>& ans,node *curr)
    {
        //Base case
        //If the trie doesn't have the current char OR cell is Visited
        int index = board[i][j]-'a';
        if(board[i][j]=='$' || curr->child[index]==NULL)  
            return;
        
        curr = curr->child[index];
        if(curr->ends > 0)
        {
            ans.push_back(curr->word);
            curr->ends -=1;
        }
        
        //Body
        char ch = board[i][j];   //Store current char
        board[i][j] = '$';  //Mark current node visited
        
        if(i>0)     //TOP
            solve(board,i-1,j,r,c,ans,curr);
        if(i<r-1)   //DOWN
            solve(board,i+1,j,r,c,ans,curr);
        if(j>0)     //LEFT
            solve(board,i,j-1,r,c,ans,curr);
        if(j<c-1)   //RIGHT
            solve(board,i,j+1,r,c,ans,curr);
        
        board[i][j] = ch;    //Mark current node as Unvisited by restoring the value
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        int r=board.size();
        int c=board[0].size();
        
        //Insert all words in TRIE
        for(int i=0;i<words.size();++i)
            insert(words[i]);
        
        //Now search words
        vector<string> ans;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
                solve(board,i,j,r,c,ans,root);
        }
        return ans;
    }
};


static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();