void back_tracking(int n, int k, vector<int>&current, vector<vector<int>>&res,int index){
    if(current.size()==k){
        res.push_back(current);
        return;
    }
    for(int i=index;i<=n;i++){
        current.push_back(i);
        back_tracking(n,k,current,res,i+1);
        current.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> res;
        back_tracking(n,k,current,res,1);
        return res;
    }
};
