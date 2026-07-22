class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,e=n-1;
        int ans=0;
        while(l<e){
            int a=(e-l)*(min(height[l],height[e]));
            ans=max(ans,a);
            if(height[l]<height[e])
                l++;
            else
                e--;
        }
        return ans;
    }
};