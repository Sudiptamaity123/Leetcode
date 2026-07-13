class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            int num=i;
            int nd=i+1;
            while(num<=high && nd<=9){
                num=10*num+nd;
                nd++;
                if(num>=low && num<=high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};