class Solution {
public:
    vector<string> ans;

    void solve(string& num,
               int index,
               long long result,
               long long last,
               long long target,
               string expression) {

        if(index == num.size()) {
            if(result == target)
                ans.push_back(expression);

            return;
        }

        long long current = 0;

        for(int i = index; i < num.size(); i++) {

            // Don't allow numbers like 05
            if(i > index && num[index] == '0')
                break;

            current = current * 10 + (num[i] - '0');

            string part = num.substr(index, i - index + 1);

            // First number
            if(index == 0) {

                solve(num,
                      i + 1,
                      current,
                      current,
                      target,
                      part);

            }
            else {

                // +
                solve(num,
                      i + 1,
                      result + current,
                      current,
                      target,
                      expression + "+" + part);

                // -
                solve(num,
                      i + 1,
                      result - current,
                      -current,
                      target,
                      expression + "-" + part);

                // *
                solve(num,
                      i + 1,
                      result - last + last * current,
                      last * current,
                      target,
                      expression + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, 0, 0, 0, target, "");

        return ans;
    }
};