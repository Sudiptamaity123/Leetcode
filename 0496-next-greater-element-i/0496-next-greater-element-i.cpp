class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        unordered_map<int,int>m;
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            m[nums2[i]]=i;
            while(!st.empty() && nums2[i]>=st.top())
                st.pop();
            if(st.empty())
                nge[i]=-1;
            else
                nge[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto it:nums1)
            ans.push_back(nge[m[it]]);
        return ans;
        
    }
};