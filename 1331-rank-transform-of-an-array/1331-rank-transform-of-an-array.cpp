class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v=arr;
        int n=arr.size();
        int k=1;
        sort(v.begin(),v.end());
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(i==0)
                m[v[i]]=k++;
            else if(v[i]!=v[i-1])
                m[v[i]]=k++;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
            ans[i]=m[arr[i]];
        return ans;
    }
};