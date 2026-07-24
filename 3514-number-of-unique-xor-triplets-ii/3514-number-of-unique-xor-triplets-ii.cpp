class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>Xor;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Xor.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>s;
        for(auto it:Xor){
            for(int i=0;i<n;i++)
                s.insert(it^nums[i]);
        }
        return s.size();
    }
};