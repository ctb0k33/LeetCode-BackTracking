class Solution {
    public int digit(int current_num){
	        int count =0;
	        while(current_num>0){
	            current_num = current_num/10;
	            count++;
	        }
	        return count;
	    }
	    public void back_tracking(int n, int k, List<Integer> res, int current_num,int pos){
	        if(digit(current_num)==n){
	            res.add(current_num);
	            return;
	        }
	        if(digit(current_num)==0){
	        current_num+=pos;}
            if(k==0){
	            if(current_num % 10 + k < 10){
	                current_num= current_num*10 + (current_num % 10 + k );
	                back_tracking(n,k,res,current_num,pos);
	                current_num=current_num/10;}         
                }
            else{
                if(current_num % 10 + k < 10){
	                current_num= current_num*10 + (current_num % 10 + k );
	                back_tracking(n,k,res,current_num,pos);
	                current_num=current_num/10;}         
	            if(current_num%10 - k >=0){
	                current_num= current_num*10 + (current_num % 10 - k );
	                back_tracking(n,k,res,current_num,pos);
	                current_num=current_num/10;
                }
	        }
	    }
    public int[] numsSameConsecDiff(int n, int k) {
        List<Integer> res= new ArrayList<Integer>();
	        for(int i=1;i<=9;i++) {
	        	back_tracking(n,k,res,0,i);
	        }
	        int[] arr = new int[res.size()];  
	        for(int i=0;i<res.size();i++) {
	        	arr[i]=res.get(i);
	        }
	        return arr;
    }
}
