class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=0;
        int s=0;
        int i=1;
        while(n){
            int d=n%10;
            if(d!=0){
                x=i*d+x;
                i*=10;
            }
            s+=d;
            n/=10;
        }
        return (long long)x*s;
    }
};