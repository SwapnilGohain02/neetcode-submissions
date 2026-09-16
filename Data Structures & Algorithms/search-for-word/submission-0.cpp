class Solution {
public:
    bool bfs(vector<vector<char>>& board, int i, int j,
             vector<vector<int>>& vis, string& word, int idx) {

        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size() ||
           vis[i][j] == 1) {
            return false;
        }
        if(board[i][j] != word[idx])
            return false;


        if(idx == word.size() - 1)
            return true;

        vis[i][j] = 1;

        bool down = bfs(board, i+1, j, vis, word, idx+1);
        bool up = bfs(board, i-1, j, vis, word, idx+1);
        bool right = bfs(board, i, j+1, vis, word, idx+1);
        bool left = bfs(board, i, j-1, vis, word, idx+1);

        vis[i][j] = 0;

        return down || up || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<int>> vis(
            board.size(),
            vector<int>(board[0].size(), 0)
        );

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {

                if(bfs(board, i, j, vis, word, 0))
                    return true;
            }
        }

        return false;
    }
};