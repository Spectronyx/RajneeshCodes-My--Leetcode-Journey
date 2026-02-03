class Solution {
    public void reverse(int[] arr,int start,int end){
        while(start < end){

            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    public void rotate(int[] arr, int k) {
        int n = arr.length;

        k %= n;
        
        //reverse whole array
        reverse(arr,0,n-1);

        //reverse first k element
        reverse(arr,0,k-1);

        //reverse last k element
        reverse(arr,k,n-1);

        
        
    }
}