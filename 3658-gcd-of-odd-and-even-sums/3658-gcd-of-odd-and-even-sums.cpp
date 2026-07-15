class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int i=2,j=1;
        int so=0,se=0;
        while(n--){
            so+=j;
            se+=i;
            i+=2;
            j+=2;
        }
        return __gcd(so,se);
    }
};