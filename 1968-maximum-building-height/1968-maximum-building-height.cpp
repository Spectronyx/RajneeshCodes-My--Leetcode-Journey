class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        // --------------------------------------------------
        // Building 1 always has height 0
        // So add it as a restriction
        // --------------------------------------------------
        restrictions.push_back({1, 0});

        // --------------------------------------------------
        // Check if building n already has a restriction
        // --------------------------------------------------
        bool hasN = false;

        for(auto &r : restrictions){
            if(r[0] == n){
                hasN = true;
                break;
            }
        }

        // --------------------------------------------------
        // If building n is not restricted,
        // maximum possible height is n-1
        //
        // Example:
        // Building 1 = 0
        //
        // 0 -> 1 -> 2 -> 3 -> ... -> n-1
        // --------------------------------------------------
        if(!hasN){
            restrictions.push_back({n, n-1});
        }

        // --------------------------------------------------
        // Sort by building number
        // --------------------------------------------------
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // ==================================================
        // LEFT TO RIGHT PROPAGATION
        // ==================================================
        //
        // Suppose:
        //
        // Building 2 <= 1
        // Building 5 <= 10
        //
        // Impossible because:
        //
        // 1 -> 2 -> 3 -> 4
        //
        // Building 5 can be at most 4
        //
        // So we tighten restrictions.
        // ==================================================

        for(int i = 1; i < m; i++){

            int prevBuilding = restrictions[i-1][0];
            int prevHeight   = restrictions[i-1][1];

            int currBuilding = restrictions[i][0];
            int currHeight   = restrictions[i][1];

            int distance = currBuilding - prevBuilding;

            // maximum reachable height from left side
            int maxAllowed = prevHeight + distance;

            restrictions[i][1] =
                min(currHeight, maxAllowed);
        }

        // ==================================================
        // RIGHT TO LEFT PROPAGATION
        // ==================================================
        //
        // Same idea but now future restrictions
        // can tighten previous buildings.
        //
        // Example:
        //
        // Building 2 <= 100
        // Building 5 <= 1
        //
        // Building 2 cannot really be 100.
        // It must respect building 5.
        // ==================================================

        for(int i = m-2; i >= 0; i--){

            int nextBuilding = restrictions[i+1][0];
            int nextHeight   = restrictions[i+1][1];

            int currBuilding = restrictions[i][0];
            int currHeight   = restrictions[i][1];

            int distance = nextBuilding - currBuilding;

            int maxAllowed = nextHeight + distance;

            restrictions[i][1] =
                min(currHeight, maxAllowed);
        }

        // ==================================================
        // Now all restrictions are consistent.
        //
        // Find maximum possible peak between every
        // consecutive restricted buildings.
        // ==================================================

        long long answer = 0;

        for(int i = 1; i < m; i++){

            long long building1 = restrictions[i-1][0];
            long long height1   = restrictions[i-1][1];

            long long building2 = restrictions[i][0];
            long long height2   = restrictions[i][1];

            long long distance = building2 - building1;

            // ------------------------------------------------
            // Highest peak possible between:
            //
            // (building1, height1)
            // (building2, height2)
            //
            // Formula:
            //
            // (height1 + height2 + distance)/2
            //
            // Example:
            //
            // (2,1) -------- (6,1)
            //
            // Heights:
            //
            // 1 2 3 2 1
            //
            // Peak = 3
            //
            // (1+1+4)/2 = 3
            // ------------------------------------------------

            long long peak =
                (height1 + height2 + distance) / 2;

            answer = max(answer, peak);
        }

        return (int)answer;
    }
};