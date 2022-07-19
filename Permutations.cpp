bool used(vector<int>nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return false;
        }
    }
    return true;
}
void back_tracking(vector<vector<int>>& res, vector<int> current, vector<int>& nums, int pos) {
    if (current.size() == nums.size()) {
        res.push_back(current);
        return;
    }
    else {
        for (int i = 0; i < nums.size(); i++) {
            if (used(current, nums[i])) {
                current.push_back(nums[i]);
                back_tracking(res, current, nums, pos + 1);
                current.pop_back();
            }
        }
    }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> current;
        back_tracking(result, current, nums, 0);
        return result;
    }
};
