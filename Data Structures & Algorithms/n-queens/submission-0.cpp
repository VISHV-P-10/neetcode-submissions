class Solution {
public:
    vector<vector<string>> res;
    int N;

    bool valid(vector<string>& board, int row,int col){
        // check vertivally up
        // need to word with the row
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }

        // check the digonally left
        for(int i=row-1,j = col-1 ; i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }

        // check digonally right
        for(int i=row-1,j=col+1;i>=0&& j<N;i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
    void solve(vector<string>& board, int row){
        // base case
        if(row >= N){
            res.push_back(board);
            return;
        }

        for(int col=0;col<N;col++){
            // check the validness of the queens position
            if(valid(board,row,col)){
                board[row][col] = 'Q';
                solve(board,row+1);
                board[row][col] ='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N =n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return res;
    }
};
