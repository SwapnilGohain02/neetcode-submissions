class Solution {
public:
    struct Node{
        Node* links[26];
        string word = "";
        Node(){
            for(int i=0;i<26;i++){
                links[i] = NULL;
            }
        }

        bool contains(char ch){
            return links[ch-'a'] != NULL;
        }

        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }
    };

    Node* root = new Node();
    vector<string>ans;
    int n;
    int m;

    void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->contains(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node){
        if(r>=n || r<0 || c<0 || c>=m)  return;
        if(board[r][c] == '#')  return;
        char ch = board[r][c];
        if(!node->get(ch)){
            return ;
        }

        node = node->get(ch);
        if(node->word != ""){
            ans.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';
        dfs(board,r-1,c,node);
        dfs(board,r+1,c,node);
        dfs(board,r,c-1,node);
        dfs(board,r,c+1,node);

        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        for(auto word:words){
            insert(word);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,i,j,root);
            }
        }
        return ans;
    }
};