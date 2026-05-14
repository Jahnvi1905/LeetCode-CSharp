class Solution {
public:
    string largestOddNumber(string num) {
        int index=-1;
        for(int i=0;i<num.length();i++){
            if(num[i]%2==1){
                index = i;
            }
        }
        if(index == -1)
            return "";

        return num.substr(0,index+1);
    }
};