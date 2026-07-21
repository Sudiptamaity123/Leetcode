class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='[' || it=='('|| it=='{')
                st.push(it);
            else{
                if(!st.empty() && st.top()=='('&&it==')')
                    st.pop();
                else if(!st.empty() && st.top()=='{'&&it=='}')
                    st.pop();
                else if(!st.empty() && st.top()=='['&&it==']')
                    st.pop();
                else 
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};