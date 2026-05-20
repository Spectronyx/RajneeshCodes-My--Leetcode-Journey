// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();
//         vector<int> result(n);


//         for(int currIdx = 0;currIdx < n;currIdx++){
//             int countCommon = 0;

//             for(int i = 0;i<= currIdx;i++){
//                 for(int j = 0;j <= currIdx;j++){
//                     if(A[i] == B[j]){
//                         countCommon++;
//                         break;
//                     }
//                 }
//             }
//             result[currIdx] = countCommon;
//         }

//         return result;
//     }
// };

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);

        unordered_set<int> elementInA,elementInB;

        for(int i = 0;i < n;i++){
            elementInA.insert(A[i]);
            elementInB.insert(B[i]);

            int countCommon = 0;

            for(auto element: elementInA){
                if(elementInB.count(element)){
                    countCommon++;
                }
            }

            result[i] = countCommon;
        }

        return result;
    }
};