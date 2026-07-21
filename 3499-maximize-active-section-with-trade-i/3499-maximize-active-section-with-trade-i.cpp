class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>ans;
        int n=s.size();
        char ch='0';
        int c1=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch)
                c++;
            else{
                c1++;
                if(c!=0)
                    ans.push_back(c);
                c=0;
            }
        }
        if(c!=0)
            ans.push_back(c);
        
        int res=0;
        if(ans.size()>=2){
            int r=ans[0]+ans[1];
            res=max(res,r);
            int i=2;
            while(i<ans.size()){
                r+=ans[i]-ans[i-2];
                res=max(res,r);
                i++;
            }
        }else
            return c1;
        return res+c1;

    }
};