class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0;
        int ind[3]={-1,-1,-1};
        for(int i=0;i<n;i++){
           ind[s[i]-'a']=i;
           ans+=min({ind[0],ind[1],ind[2]})+1;
        }
        return ans;
    }
};