
class Solution {
        public void back_tracking(int[]nums, int prev, List<Integer> current, Set<List<Integer>> res, int index){
        if(current.size()>=2){
            res.add(new ArrayList<Integer>(current));
        }
        if(index>=nums.length){
            return;
        }
        for(int i=index; i<nums.length;i++){
            if(nums[i]<prev){
                continue;
            }
            if(nums[i]>=prev){
                current.add(nums[i]);
                back_tracking(nums, nums[i],current,res,i+1);
                current.remove(current.size()-1);
            }
        }
    }
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> res=new HashSet<>();
        List<Integer> current=new ArrayList<Integer>();
        back_tracking(nums,-999,current,res,0);
        return new ArrayList<>(res);
    }
}
