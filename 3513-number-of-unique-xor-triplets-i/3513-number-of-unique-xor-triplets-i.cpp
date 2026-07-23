class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return n;
        int i=0;
        while((1<<i)<=n){
            // cout<<(1<<i)<<" ";
            i++;
        }
        // cout<<1<<i<<" ";
        return 1<<i;
    }
};