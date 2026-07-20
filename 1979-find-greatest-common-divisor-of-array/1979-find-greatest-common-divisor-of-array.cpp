class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX,mx=INT_MIN;
        for(auto it:nums){
            mx=max(mx,it);
            mn=min(mn,it);
        }
        return __gcd(mx,mn);
    }
};