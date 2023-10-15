class Solution {
public:
bool isSafe(vector<vector<int>>chess,int row,int col){
    for(int i=0,j=col;i<row;i++){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<chess[0].size();i--,j++){
        if(chess[i][j]==1){
            return false;
        }
    }
    return true;
}
void NQueens(vector<vector<int>>chess,string ans,int row){
    if(row>=chess.size()){
        vector<string>res;
        string s="";
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans.size();j++){
            if(j==ans[i]-'0'){
                s+="Q";
            }
            else{
                s+=".";
            }
            }
        res.push_back(s);
        s="";
        }
        result.push_back(res);
        return;
    }
    for(int i=0;i<chess[0].size();i++){
        if(isSafe(chess,row,i)==true){
        chess[row][i]=1;
        NQueens(chess,ans+to_string(i),row+1);
        chess[row][i]=0;
        }
    }
}
    vector<vector<string>> result;
    int totalNQueens(int n) {
        vector<vector<int>>arr(n,vector<int>(n));
        NQueens(arr,"",0);
     return result.size(); 
    }
};
