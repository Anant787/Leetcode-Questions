class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a';
        char b = 'b';
        if(y > x) {
            swap(a, b);
            swap(x, y);
        }
        
        int score = 0;
        stack<char> forwardStack;
        for (char ch : s)
            if(!forwardStack.empty() && ch == b && forwardStack.top() == a) {
                score += x;
                forwardStack.pop();
            }
            else forwardStack.push(ch);
        
        stack<char> reverseStack;
        while (!forwardStack.empty())
            if(!reverseStack.empty() && reverseStack.top() == a && forwardStack.top() == b) { 
                score += y;
                forwardStack.pop();
                reverseStack.pop();
            } else { 
                reverseStack.push(forwardStack.top());
                forwardStack.pop();
            }

        return score;  
    }
};
