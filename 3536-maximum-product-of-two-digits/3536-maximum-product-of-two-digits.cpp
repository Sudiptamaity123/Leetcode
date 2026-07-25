class Solution {
public:
    int maxProduct(int n) {
        string num=to_string(n);
        sort(num.begin(),num.end());
        int nz=num.size();
        return (num[nz-1]-'0') * (num[nz-2]-'0');
    }
};