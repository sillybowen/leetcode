class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits[digits.size()-1] ++;
        int dit = digits.size()-1;        
        while (dit>=0 && digits[dit]>9) {
            digits[dit] %= 10;
            if (dit>0) digits[dit-1]++;
            else digits.insert(digits.begin(),1);
            dit --;
        }
        return digits;
    }
};