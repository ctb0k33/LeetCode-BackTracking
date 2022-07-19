void back_tracking(vector<int>&current, vector<int>&nums, int pos, vector<vector<int>>&res){
    res.push_back(current);
    for(int i=pos;i<nums.size();i++){
        current.push_back(nums[i]);
        back_tracking(current,nums,i+1,res);
        current.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        back_tracking(current,nums,0,res);
        return res;
    }
};
