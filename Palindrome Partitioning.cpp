bool is_palindrome(string s){
    string temp;
    for(int i=s.length()-1;i>=0;i--){
        temp+=s[i];
    }
    if(temp==s){
        return true;
    }
    return false;
}

void back_tracking(string s,vector<vector<string>>&res,vector<string> current,int pos ){
    if(pos>=s.length()){
        res.push_back(current);
        return;
    }
    for(int i=pos;i<s.length();i++){
        if(is_palindrome(s.substr(pos,i-pos+1))){
            current.push_back(s.substr(pos,i-pos+1));
            back_tracking(s,res,current,i+1);
            current.pop_back();
        }
        
    }
}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        back_tracking(s,res,current,0);
        return res;
    }
};
