#include<iostream>
using namespace std;
class Solution {
    double find(int A[],int B[],int as,int ae,int bs,int be,int index) {
        if (as>ae) {
            return B[bs+index-1];
        }
        if (bs>be) {
            return A[as+index-1];
        }
        if (index == 1) return A[as]<B[bs]? A[as]:B[bs];
        int ma = index/2;
        int mb = index-ma;

        if (ae-as+1<ma) {
            ma = ae-as+1;
            mb = index-ma;
        }
        if (be-bs+1<mb) {
            mb = be-bs+1;
            ma = index -mb;
        }

        ma = as + ma -1;
        mb = bs + mb -1;
        if (A[ma]>B[mb]) {
            return find(A,B,as,ma,mb+1,be, index - (mb-bs+1));
        }
        else if (A[ma]<B[mb]){
            return find(A,B,ma+1,ae,bs,mb, index - (ma-as+1));            
        }
        else return A[ma];
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2==0) {
            return (find(A,B,0,m-1,0,n-1,(m+n)/2) +
                    find(A,B,0,m-1,0,n-1,(m+n)/2+1))/2;
        }
        else 
        return find(A,B,0,m-1,0,n-1,(m+n)/2+1);
    }
};

int main () {
  int a[] = {1,2};
  int b[] = {1,2};
  Solution s;
  cout<<s.findMedianSortedArrays(a,2,b,2)<<endl;
}
