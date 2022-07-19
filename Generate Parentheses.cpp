void back_tracking(int n,string &current, vector<string>&res,int left,int right){
   if(left==right && right ==n){
       res.push_back(current);
       return;
   }
    if(right<=left && left<n){
        current.push_back('(');
        back_tracking(n,current,res,left+1,right);
        current.pop_back();
    }
    if(right<left && right<n){
        current.push_back(')');
        back_tracking(n,current,res,left,right+1);
        current.pop_back();
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string current="(";
        vector<string>res;
        back_tracking(n,current,res,1,0);
        return res;
    }
};
