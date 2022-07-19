class Solution {
    public void reverse(int[] nums){
	        int n=nums.length;
	        List<Integer> temp= new ArrayList<Integer>();
	        for(int i=0;i<n/2;i++){
	            temp.add(nums[i]);
	            nums[i]=nums[n-i-1];
	            nums[n-i-1]=temp.get(i);
	        }
	    }
    public boolean is_duplicate(List<Integer> state, int pos){
        for(int i=0;i<pos;i++){
            if(state.get(i)==state.get(pos)){
                return true;
            }
        }
        return false;
    }
    public boolean check_condition(List<Integer> state, int sum , int k){
        for(int i=0;i<k;i++){
            if(state.get(i)!=sum) return false;
        }
        return true;
    }
    public boolean back_tracking(int[] nums, List<Integer> state, int pos, int sum, int k){
        if(pos==nums.length){
            return check_condition(state,sum,k);
        }
        for(int i=0;i<k;i++){
            if(nums[pos]+state.get(i)>sum || is_duplicate(state,i)) continue;
            state.set(i,nums[pos]+state.get(i));
            if(back_tracking(nums,state,pos+1,sum,k)) return true;
            state.set(i,state.get(i)-nums[pos]);
        }
        return false;
    }
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
        sum=sum/k;
        List<Integer> state= new ArrayList<Integer>();
        for(int i=0;i<k;i++){
            state.add(0);
        }
        Arrays.sort(nums);
        reverse(nums);
        if(nums[0]>sum){
            return false;
        }
        return back_tracking(nums,state,0,sum,k);
       
    }
}
  
       
