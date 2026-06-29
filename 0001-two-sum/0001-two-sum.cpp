class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]]=i;
        for(int i=0;i<n;i++){
            long long int res=(long long )target-nums[i];
            if(m.find(res)!=m.end() && m[res]!=i)
                return {i,m[res]};
        }
        return {0,0};
    }
};