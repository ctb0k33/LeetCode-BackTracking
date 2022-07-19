bool back_tracking(string word, int row, int column, int index, vector<vector<bool>>&check,vector<vector<char>> & board){
    if(index==word.length()){
        return true;
    }
    if(row<0|| column<0||row>board.size()-1 || column> board[0].size()-1|| check[row][column] || board[row][column] != word[index]){
        return false;
    }
    check[row][column] = true;
    if(back_tracking(word,row+1,column,index+1,check,board)||
       back_tracking(word,row,column+1,index+1,check,board)||
       back_tracking(word,row-1,column,index+1,check,board)||
       back_tracking(word,row,column-1,index+1,check,board)){
    return true;
        }
    check[row][column]=false;
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int column=board[0].size();
        vector<vector<bool>> check(row,vector<bool>(column));
        for(int i=0; i<row;i++){
            for(int j=0;j<column;j++){
                if(word[0]==board[i][j] && back_tracking(word,i,j,0,check,board)){
                    return true;
                }
            }
        }
        return false;
    }
};
