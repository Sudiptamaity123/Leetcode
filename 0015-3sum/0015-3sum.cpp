class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        int i=0;
        sort(nums.begin(),nums.end());
        while(i<n-2){
            int l=i+1,e=n-1;
            while(l<e){
                int s=nums[i]+nums[l]+nums[e];
                if(s==0){
                    ans.push_back({nums[i],nums[l],nums[e]});
                    int c=nums[l];
                    l++;
                    while(l<e && nums[l]==c)
                        l++;
                    c=nums[e];
                    e--;
                    while(l<e && nums[e]==c)
                        e--;
                }else if(s<0){
                    l++;
                }else
                    e--;
            }
            int c=nums[i];
            i++;
            while(i<n && nums[i]==c)
                i++;
        }
        return ans;
    }
};