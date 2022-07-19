void back_tracking(string digits,string dict[9],string &current,vector<string>&res,int pos){
    if(digits.length()==0){
        return ;
    }
    if(current.length()==digits.length()){
        res.push_back(current);
        return;
    }
        for(int j=0;j<dict[digits[pos]-'0'].length();j++){
        current+=dict[digits[pos]-'0'][j];
        back_tracking(digits,dict,current,res,pos+1);
        current.pop_back();
        }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string current;
        vector<string>res;
        back_tracking(digits,dict,current,res,0);
        return res;
    }
};
