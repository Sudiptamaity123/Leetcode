class Solution {
    vector<int> nge(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i])
                st.pop();
            if(i<n){
                if(st.empty())
                    nge[i]=-1;
                else
                    nge[i]=max(st.top(),nge[i+1]);
            }
            st.push(nums[i]);
        }
        return nge;
    }
    vector<int> pge(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top()<=nums[i])
                st.pop();
            if(i<n){
                if(st.empty())
                    nge[i]=-1;
                else
                    nge[i]=max(st.top(),nge[i-1]);
            }
            st.push(nums[i]);
        }
        return nge;
    }
public:
    int trap(vector<int>& height) {
        int n=height.size();
        auto ng=nge(height);
        auto pg=pge(height);
        int ans=0;
        for(int i=0;i<n;i++){
            int h=min(ng[i],pg[i]);
            if(h==-1)
                continue;
            cout<<h<<" ";
            ans+=(h-height[i]);
        }
        return ans;
    }
};