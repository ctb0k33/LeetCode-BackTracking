void back_tracking(int k, int n, vector<vector<int>> & res,vector<int> current,int pos){
    if(k==0){
        if(n==0){
        res.push_back(current);
        return;
                }
        else{
            return;
        }
    }
    for(int i=pos;i<=9;i++){
        current.push_back(i);
        back_tracking(k-1,n-i,res,current,i+1);
        current.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n<(k+1)*k/2){
            return res;
        }
        vector<int> current;
        back_tracking(k,n,res,current,1);
        return res;
    }
};
