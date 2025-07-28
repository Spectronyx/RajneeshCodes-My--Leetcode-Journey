class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     vector<int> ans;

    //     for(auto num: nums){
    //         if(mp.find(num) != mp.end()){
    //             mp[num]++;
    //         }else{
    //             mp[num] = 1;
    //         }
    //     }

    //     for(auto& pair: mp){
    //         if(pair.second > nums.size()/3){
    //             ans.push_back(pair.first);
    //         }
    //     }
    //     return ans;

//another solution//
    int n = nums.size();

    int count1 = 0;
    int count2 = 0;
    
    int candidate1 = 0;
    int candidate2 = 1;

    // ==========================
    //      First pass
    // find potential candidate
    // ==========================
    for(int num: nums){
        //if num is candidate 1

        if(num == candidate1){
            count1++;
        }else if(num == candidate2){
            count2++;
        }else if(count1 == 0){
            candidate1 = num;
            count1++;
        }else if(count2 == 0){
            candidate2 = num;
            count2++;
        }else{
            count1--;
            count2--;
        }
    }

    //Second pass
    //Actual candidate verfication
    vector<int> ans;

    count1 = 0;
    count2 = 0;

    for(int num : nums){
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
    }

    // push onlhy those have count > n/3

    if(count1 > n/3) ans.push_back(candidate1);
    if(count2 > n/3) ans.push_back(candidate2);

    return ans;
    }
};