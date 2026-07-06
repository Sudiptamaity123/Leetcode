class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0;
        int ans=INT_MIN;
        for(auto it:nums){
            s+=it;
            if(s<it){
                s=it;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};