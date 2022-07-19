
class Solution {
   public static void back_tracking(int[]nums, int target ,int sum, int i, List<Integer> my_list){
	    if(i==nums.length){
	        if(target==sum) my_list.set(0,my_list.get(0)+1);
	        return;
	    }
	        back_tracking(nums,target,sum+nums[i], i+1,my_list);
	        back_tracking(nums,target ,sum-nums[i],i+1,my_list);
	}
	    public static int findTargetSumWays(int[] nums, int target) {
	        List<Integer> my_list=new ArrayList<>();
	        my_list.add(0);
	        back_tracking(nums,target,0,0,my_list);
	        return my_list.get(0);
	    }
    }
