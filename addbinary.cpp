class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int ent = 0;
        int n1,n2;
        char c;
        if (a.size()>b.size())
            ret.resize(a.size());
        else
            ret.resize(b.size());
        for (int i = 0; i< ret.size(); i++) {
            if (i>=a.size())
                n1 = 0;
            else
                n1 = a[a.size()-i-1]-'0';
            if (i>=b.size())
                n2 = 0;
            else
                n2 = b[b.size()-i-1]-'0';
            c = '0'+(n1+n2+ent)%2;
            ent = (n1+n2+ent)/2;
            ret[i] = c;
        }
        if (ent>0)
            ret.resize(ret.size()+1,'1');
        for (int i = 0; i<ret.size()/2;i++) {
            c = ret[i];
            ret[i] = ret[ret.size()-1-i];
            ret[ret.size()-1-i] = c;
        }
        return ret;
    }
};
