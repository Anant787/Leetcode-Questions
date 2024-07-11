// class Solution {
// public:
//     string reverseParentheses(string s) {
//         //Wormhole - Teleportation Technique
//         int n = s.length();
//         stack<int> openBracketIdx;
//         vector<int> door(n);

//         //First Pass : Build up door[] array
//         for(int i = 0; i < n; i++){
//             char ch = s[i];
//             if(ch == '('){
//                 openBracketIdx.push(i);
//             }
//             else if(ch == ')'){
//                 int ind = openBracketIdx.top();
//                 openBracketIdx.pop();
//                 door[i] = ind;
//                 door[ind] = i;
//             }
//         }

//         string result = "";
//         int flag = 1;
//         //Second Pass : Build the result string
//         for(int i = 0; i < n; i += flag){
//             char ch = s[i];
//             if(ch == '(' || ch == ')'){
//                 i = door[i];
//                 flag *= -1;
//             }
//             else{
//                 result.push_back(ch);
//             }
//         }

//         return result;
//     }
// };
// // T.C. : O(n)
// // S.C. : O(n + n) ~ O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> temp; //temp stores the characters to be left at the time of reversal
        string result = "";
        int n = s.length();

        for(int i = 0; i < n; i++){ //O(n)
            char ch = s[i];
            if(ch == '('){
                temp.push_back(result.length());
            }
            else if(ch >= 'a' && ch <= 'z'){
                result.push_back(ch);
            }
            else{
                int index = temp.back(); //O(1) operation
                temp.pop_back(); //O(1) operation
                reverse(result.begin() + index, result.end()); //O(n) in the worst case
            }
        }

        return result;
    }
};
// T.C. : O(n^2)
// S.C. : O(number of open brackets) ~ O(n) but mentioned in constraints that
// it is guaranteed that the paranthesis are balanced. So, S.C. << O(n) in actual
