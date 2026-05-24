class Solution {
public:

    void solve(int index,
               string path,
               long value,
               long prev,
               string num,
               int target,
               vector<string>& ans) {

        // Reached end
        if(index == num.size()) {

            if(value == target)
                ans.push_back(path);

            return;
        }

        string temp = "";

        long number = 0;

        for(int i = index; i < num.size(); i++) {

            // Avoid leading zeros
            if(i > index && num[index] == '0')
                break;

            temp += num[i];

            number = number * 10 + (num[i] - '0');

            // First number
            if(index == 0) {

                solve(i + 1,
                      temp,
                      number,
                      number,
                      num,
                      target,
                      ans);
            }
            else {

                // Addition
                solve(i + 1,
                      path + "+" + temp,
                      value + number,
                      number,
                      num,
                      target,
                      ans);

                // Subtraction
                solve(i + 1,
                      path + "-" + temp,
                      value - number,
                      -number,
                      num,
                      target,
                      ans);

                // Multiplication
                solve(i + 1,
                      path + "*" + temp,
                      value - prev + (prev * number),
                      prev * number,
                      num,
                      target,
                      ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0, "", 0, 0, num, target, ans);

        return ans;
    }
};