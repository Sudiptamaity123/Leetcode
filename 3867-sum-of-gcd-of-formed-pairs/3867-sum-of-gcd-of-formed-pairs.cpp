class Solution {
    
public:
    long long gcdSum(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        vector<int>pre(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            pre[i]=__gcd(mx,nums[i]);
        }
        sort(pre.begin(),pre.end());
        long long ans=0;
        int l=0,e=n-1;
        while(l<e){
            ans+=__gcd(pre[l],pre[e]);
            l++;
            e--;
        }
        return ans;
    }
};