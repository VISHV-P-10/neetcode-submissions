class Solution {
public:
    vector<vector<string>> res;
    int N;
    bool valid(vector<string> &board, int row,int col){
        //vertically upwords
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }

        // diognal left
        for(int i=row-1,j=col-1;i>=0 && j>=0; i--,j--){
             if(board[i][j]=='Q') return false;
        }
        // diaonaly right
         for(int i=row-1,j=col+1;i>=0 && j<N; i--,j++){
             if(board[i][j]=='Q') return false;
        }

        return true;
    }
    void solve(vector<string> & board, int row){
        // base case
        if(row >= N){
            res.push_back(board);
            return;
        }

        for(int col=0;col<N;col++){
            if(valid(board,row,col)){
            board[row][col] = 'Q';
            solve(board,row+1);
            board[row][col] = '.';
            }   
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        N=n;
        solve(board,0);
        int ans = res.size();
        return ans;
    }
};