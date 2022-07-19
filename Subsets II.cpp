void back_tracking(vector<int>nums, vector<vector<int>>&res, vector<int> current, int pos,set<vector<int>> &check){
    check.insert(current);
    for(int i=pos;i<nums.size();i++){
        current.push_back(nums[i]);
        back_tracking(nums,res,current,i+1,
                      check);
        current.pop_back();
        }

    }

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        set<vector<int>> check;
        vector<vector<int>> res;
        vector<int> current;
        back_tracking(nums,res,current,0,
                      check);
        for( auto it:check ){
            res.push_back(it);
        }
        return res;
    }
};
