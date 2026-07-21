class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        vector<int>ans;
        int n=ass.size();
        stack<int>s;
        for(auto it:ass){
            if(it>0)
                s.push(it);
            else{
                while(!s.empty()&& s.top()<-it)
                    s.pop();
                if(s.empty())
                    ans.push_back(it);
                if(!s.empty()&&s.top()==-it)
                    s.pop();
                
            }
        }
        vector<int>t;
        while(!s.empty()){
            t.push_back(s.top());
            s.pop();
        }
        for(int i=t.size()-1;i>=0;i--)
            ans.push_back(t[i]);
        return ans;
    }
};