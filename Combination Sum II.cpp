void back_tracking(int index,int target,vector<int>& candidates, vector<int>& current, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(current);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (i>index and candidates[i] == candidates[i-1]) continue;
        if (candidates[i] > target) break;
        current.push_back(candidates[i]);
        back_tracking(i+1, target - candidates[i], candidates, current, res);
        current.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        back_tracking(0, target, candidates, current, res);
        return res;
    }
};
