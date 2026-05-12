// class Solution {
// public:
//     bool isPossible(vector<vector<int>>& tasks,int mid){
//         int currentEnergy = mid;

//         for(auto task: tasks){
//             if(currentEnergy < task[1]){
//                 return false;
//             }
//             currentEnergy -= task[0];
//         }
//         return true;
//     }
//     int minimumEffort(vector<vector<int>>& tasks) {
//         int n = tasks.size();

//         auto lambda = [](auto &task1,auto& task2){
//             int diff1 = task1[1] - task1[0];
//             int diff2 = task2[1] - task2[0];

//             return diff1 > diff2;
//         };

//         sort(tasks.begin(),tasks.end(), lambda);

        

//         int l = 0;
//         int r = 1e9;
//         int minPossible = INT_MAX;

//         while(l <= r){
//             int mid = l+(r-l)/2;

//             if(isPossible(tasks,mid)){
//                 minPossible = min(minPossible,mid);
//                 r = mid-1;
//             }else {
//                 l = mid+1;
//             }
//         }
//         return minPossible;
//     }
// };

class Solution{
public:
    int minimumEffort(vector<vector<int>> &tasks){
        sort(tasks.begin(),tasks.end(),[](auto 
        &task1,auto &task2){
            return ((task1[1]-task1[0] > (task2[1] - task2[0])));
        });


        int currentEnergy = 0;
        int initialEnergy = 0;

        for(auto task: tasks){
            int actual = task[0];
            int minimum = task[1];

            if(currentEnergy < minimum){
                initialEnergy += (minimum - currentEnergy);
                currentEnergy = minimum;
            }

            currentEnergy -= actual;
        }
        return initialEnergy;
    }
};