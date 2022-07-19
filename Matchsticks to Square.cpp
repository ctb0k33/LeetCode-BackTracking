bool is_happend(vector<int> state, int pos){
    for(int i=0;i<pos;i++){
        if(state[pos]==state[i]) return true;
    }
    return false;
}

bool back_tracking(vector<int> state, vector<int> matchsticks, int sum,int pos){
    if(pos==matchsticks.size()){
        return state[0]==sum && state[1]==sum && state[2] == sum && state[3] ==sum; 
    }
    for(int i=0;i<4;i++){
        if(state[i]+matchsticks[pos]>sum || is_happend(state,i)) continue;
        
        state[i]+=matchsticks[pos];
        
        if(back_tracking(state,matchsticks,sum,pos+1)) return true;
        
        state[i]-=matchsticks[pos];
    }
    return false;
}



class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i=0;i<matchsticks.size();i++){
            sum+=matchsticks[i];
        }
        if(sum%4 != 0 || matchsticks.size()<4){
            return false;
        }
        sum=sum/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        if(matchsticks[0]>sum){
            return false;
        }
        vector<int> state(4,0);
        return back_tracking(state,matchsticks, sum,0);
    }
};
