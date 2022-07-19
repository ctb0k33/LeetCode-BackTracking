
void back_tracking(vector<int>candidates,int target,vector<vector<int>>&res, vector<int> current,int i){
    if(target==0 ){
        res.push_back(current);
        return;
    }
    while(i<candidates.size() && target-candidates[i]>=0){
        current.push_back(candidates[i]);
            back_tracking(candidates,target-candidates[i],res,current,i);
            ++i;
            current.pop_back();
        }
    }

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end()); 
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
           vector<vector<int>>res;
            vector<int>current;
        back_tracking(candidates,target, res,current,0);
        return res;
    }
};
