class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>c(26);
        for(auto it:s)
            c[it-'a']++;
        char ch='A';
        string res;
        for(int i=0;i<26;i++){
            char ab='a'+i;
            if(c[i]%2==1){
                ch='a'+i;
                // c[i]--;
            }
            for(int j=0;j<c[i]/2;j++)
                res+=ab;
        }
        string t=res;
        reverse(t.begin(),t.end());
        if(ch!='A')
            return res+ch+t;
        else
            return res+t;
        
    }
};