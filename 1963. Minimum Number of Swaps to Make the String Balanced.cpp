class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
                balance++;
            }else if(balance > 0){
                balance--;
            }
        }
        return (balance + 1) / 2;
    }
};
