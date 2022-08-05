class Solution {
public:
    void back_tracking(map<char,int>&my_map , vector<string> &res ,string current , int size) {
        if (current.length() != size && current.length()!=0) res.push_back(current);
        if (current.length()==size){
            res.push_back(current);
            return;
        }
        for (auto it : my_map) {
            if (it.second != 0) {
                current = current + it.first;
                my_map[it.first]--;
                back_tracking(my_map, res, current, size);
                my_map[it.first]++;
                current.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int size= tiles.length();
        vector<string> res;
        string current = "";
        map<char, int> my_map;
        for (int i = 0; i < tiles.size(); i++) {
            my_map[tiles[i]]++;
        }
        back_tracking(my_map, res, current, size);
        return res.size();
    }
};
