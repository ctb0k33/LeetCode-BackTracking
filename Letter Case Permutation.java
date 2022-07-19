class Solution {
   public void back_tracking(String s,List<String> result, StringBuilder current, int pos){
        if(current.length()==s.length()) {
        	result.add(new String(current));
        	return;
        }
        for(int i=pos;i<s.length();i++) {
        	if(s.charAt(i)>=48 && s.charAt(i)<=57) {
        		current.append(s.charAt(i));
        		back_tracking(s,result,current,i+1);
        		current.delete(current.length()-1,current.length());
        	}
        	else {
        		current.append(s.charAt(i));
        		back_tracking(s,result,current,i+1);
        		current.delete(current.length()-1,current.length());
        		current.append(""+(char)(s.charAt(i)-32));
        		back_tracking(s,result,current,i+1);
        		current.delete(current.length()-1,current.length());
        	}
        	
        }
    }
    public List<String> letterCasePermutation(String s) {
        s=s.toLowerCase();
        List<String> res=new ArrayList<String>();
        StringBuilder current= new StringBuilder();
        back_tracking(s,res,current,0);
        return res;
    }
}
