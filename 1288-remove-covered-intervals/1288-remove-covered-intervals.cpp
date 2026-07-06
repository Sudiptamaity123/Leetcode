class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inte) {
        int n = inte.size();
        sort(inte.begin(), inte.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            else
                return a[0]<b[0];
        });
        vector<vector<int>>res;
        
        for(int i=0;i<n;i++){
            int sz=res.size();
            bool fl=false;
            for(int j=sz-1;j>=0;j--){
                int l=res[j][0],h=res[j][1];
                if(inte[i][1]<=h){
                    if(inte[i][0]>=l){
                        fl=true;
                        break;
                    }
                }
            }
            if(!fl)
                res.push_back({inte[i][0],inte[i][1]});
        }
        return res.size();
    }
};