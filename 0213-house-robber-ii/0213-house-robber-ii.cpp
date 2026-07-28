class Solution {
    int f(int ind,vector<int>&nums,vector<int>&dp){
    if(ind<0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    //pick
    int pick=nums[ind]+f(ind-2,nums,dp);
    //not pick
    int notpick=f(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);

}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>t1(nums.begin(),nums.begin()+n-1);
        vector<int>t2(nums.begin()+1,nums.end());
        return max(maximumNonAdjacentSum(t1),maximumNonAdjacentSum(t2));
    }
};