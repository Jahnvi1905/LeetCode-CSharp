class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp ="";

        for(int i=0; i<s.length();i++){
            if(s[i]!=' '){
                temp = temp+s[i];
            }
            else{
                if(temp != ""){
                    words.push_back(temp);
                    temp="";
                }
            }
        }

        if(temp!=""){
            words.push_back(temp);
        }

        string ans="";

        for(int i=words.size() -1;i>=0;i--){
            ans=ans+words[i];

            if(i!=0){
                ans+=" ";
            }
        }
        return ans;
    }
};