class Solution {
public:
    string intToRoman(int num) {
        string hundreds[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};        
        string tens[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string digits[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string ret = "";
        int tmp = num;
        while (tmp>=1000) {
            ret+="M";
            tmp-=1000;
        }
        int hun = tmp/100;
        ret+=hundreds[hun];
        tmp%=100;
        int ten = tmp/10;
        ret+=tens[ten];
        tmp%=10;
        ret+=digits[tmp];
        return ret;        
    }
};