class Solution {
public:

    void slove(int open,int close, string temp,vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        if(open>0){
            slove(open -1,close,temp + '(',ans);
        }

        if(close>open){
            slove(open,close-1,temp+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        slove(n,n,"",ans);
        return ans;

    }
};