void back_tracking( vector<int>& nums, vector<int> current, vector<vector<int>>& res, map<int,int> freq){
    if(current.size()==nums.size()){
        res.push_back(current);
        return;
    }
    for(auto it=freq.begin();it!=freq.end();it++){
        if(it->second >0){
            current.push_back(it->first);
            it->second --;
            back_tracking(nums,current,res,freq);
            it->second++;
            current.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        back_tracking(nums, current,res,freq);
        return res;
    }
};
