class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int>st;   // initialize stack 
        int j = 0;
        for(auto val : pushed)  //iterate over pushed vector
        {
            st.push(val);   //push the element of pushed vector

            while(st.size() > 0 && st.top() == popped[j])  //check the condition
            {
                st.pop();
                j++;
            }
        }
        return st.size() == 0;  //return true if the stack is empty
        
    }
};
