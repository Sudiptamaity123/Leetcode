class Solution {
    int mod=1e9+7;
    vector<int> NSE(vector<int>& arr) {
        //  code here
        stack<int>s;
        int n=arr.size();
        vector<int>nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            if(s.empty())
                nse[i]=n;
            else
                nse[i]=s.top();
            
            s.push(i);
        }
        return nse;
    }
    vector<int> psee(vector<int>& arr) {
        //  code here
        stack<int>s;
        int n=arr.size();
        vector<int>nse(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i])
                s.pop();
            if(s.empty())
                nse[i]=-1;
            else
                nse[i]=s.top();
            
            s.push(i);
        }
        return nse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int sum=0;
        int n=arr.size();
        auto ns=NSE(arr);
        auto ps=psee(arr);
        for(int i=0;i<n;i++){
            int l=i-ps[i];
            int r=ns[i]-i;
            sum=(long long)((long long)sum+(long long )r*l*arr[i])%mod;
            sum%=mod;
        }
        return sum;
    }
};