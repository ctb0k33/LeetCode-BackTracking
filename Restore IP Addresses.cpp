int convert(string s) {
    int res = stoi(s);
    return res;
}
bool is_valid(vector<string>& current) {
    for (int i = 0; i < 4; i++) {
        if (current[i].length() > 3) {
            return false;
        }
        if (current[i].length() >= 2 && current[i][0] == '0') {
            return false;
        }
        if (convert(current[i]) > 255) {
            return false;
        }
    }
    return true;
}

void back_tracking(string current, vector<string>check, vector<string>& res) {
    if (check.size() == 4 ) {
        if (is_valid(check)&& current=="") {
            string word;
            for (int i = 0; i < 4; i++) {
                word += check[i];
                if (i != 3) word += ".";
            }
            res.push_back(word);
            return;
        }
        return;
    }
    for (int i = 1; i <= current.length(); i++) {
        check.push_back(current.substr(0, i));
        current = current.substr(i);
        back_tracking(current, check, res);
        current = check[check.size() - 1] + current;
        check.pop_back();
    }
}
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12){
            return {};
        }
        vector<string> res;
        vector<string> check;
        string current=s;
        back_tracking(current,check,res);
        return res;
    }
};
