class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans;
        ans.resize(num1.size()+num2.size(),0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for (int i = 0; i<num1.size();i++)
            for (int j = 0; j<num2.size();j++) {
                ans[i+j] += (num1[i]-'0')*(num2[j]-'0');
                if (ans[i+j]>9) {
                    ans [i+j+1] += ans[i+j]/10;
                    ans [i+j]%=10;
                }
            }
        int largest=0;
        for (int i = 0; i<ans.size(); i++) {
            if (ans[i]!=0) largest = i;
            if (ans[i]>9) {
                ans[i+1]+= ans[i]/10;
                ans[i]%=10;
            }
        }
        string ret;
        ret.resize(largest+1);
        for (int i = 0; i<ret.size();i++)
            ret[ret.size()-1-i]= '0'+ans[i];
        
        return ret;
        
    }
};