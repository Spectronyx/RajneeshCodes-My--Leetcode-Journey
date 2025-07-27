class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //do array lenge pos aur negative fir usme store karenge
        //aur fir even odd ke hisaab se fill karenge
        int n = nums.size();
        vector<int> pos,neg;
        for(int i = 0; i< n;i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
        int j = 0;
        int k = 0;
        int i = 0;
        vector<int> arr(n);

        while(j < pos.size() && k < neg.size()){
            if(i%2 == 0){
                arr[i++] = pos[j++];
            }else{
                arr[i++] = neg[k++];
            }
        }
        while(j < pos.size()){
            arr[i++] = pos[j++];
        }
        while(k < neg.size()){
            arr[i++] = neg[k++];
        }
        return arr;
    }
};