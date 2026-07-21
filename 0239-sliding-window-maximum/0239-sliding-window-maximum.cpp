class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       if(k==1)
        return nums;
       deque<int>dq;
       int n=nums.size();
       for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
       } 
       vector<int>ans;
       ans.push_back(nums[dq.front()]);
       for(int i=k;i<n;i++){
            while(dq.front()<i-k+1)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
       }
       return ans;
    }
};