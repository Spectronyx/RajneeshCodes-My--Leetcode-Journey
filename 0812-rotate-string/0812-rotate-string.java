class Solution {
    public boolean rotateString(String s, String goal) {
        int n = s.length();
        int m = goal.length();

        if( n != m) return false;

        for(int i = 0 ;i < n;i++){
            if(s.equals(goal)){
                return true;
            }

            char last = s.charAt(n-1);
            s = last+ s.substring(0,n-1);
        }
        return false;
    }
}