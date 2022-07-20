class Solution {
    public boolean check(List<Integer>current){
        for(int i=0;i<current.size()-2;i++){
            if(current.get(i)+current.get(i+1)!= current.get(i+2)){
                return false;
            }
        }
        return true;
    }
    public void back_tracking(String num, List<Integer> current, List<List<Integer>>result, int pos){
        if(pos>=num.length()){
            if(current.size()>=3 && check(current)) {result.add(new ArrayList<Integer>(current));}
            return;
        }
        for(int i=pos;i<num.length();i++){
            if(current.size()>=3){
                if(
        current.get(current.size()-1)!=(current.get(current.size()-2)+current.get(current.size()-3))){
                    break;
                }
            }
            String temp2=num.substring(pos,i+1);
	        if(temp2.length()>=2 && temp2.charAt(0)=='0') {
	        	break;
	        }
            long temp= Long.valueOf(num.substring(pos,i+1));
            if(temp>=Integer.MAX_VALUE) break;
            current.add((int)temp);
            back_tracking(num,current,result,i+1);
            current.remove(current.size()-1);
            
        }
    }
    public List<Integer> splitIntoFibonacci(String num) {
        List<Integer> current=new ArrayList<Integer>();
        List<List<Integer>> result= new ArrayList<>();
        back_tracking(num,current,result,0);
        if(result.size()==0){
            return new ArrayList<Integer>();
        }
        else{
            return result.get(0);
        }
    }
}
