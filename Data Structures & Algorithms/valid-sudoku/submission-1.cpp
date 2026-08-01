class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            vector<int>f(10,0);
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')    continue;
                if(f[board[i][j]-'0']>0)   return false;
                f[board[i][j]-'0']++;
            }
        }

        for(int j=0;j<m;j++){
            vector<int>f(10,0);
            for(int i=0;i<n;i++){
                if(board[i][j]=='.')    continue;
                if(f[board[i][j]-'0']>0)   return false;
                f[board[i][j]-'0']++;
            }
        }

        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
                vector<int>f(10,0);
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(board[i+k][j+l]=='.')    continue;
                        if(f[board[i+k][j+l]-'0']>0)   return false;
                        f[board[i+k][j+l]-'0']++;
                    }
                }
            }
        }
        return true;
    }
};
