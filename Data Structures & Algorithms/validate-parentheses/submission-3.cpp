// class Solution {
// public:
//     bool isValid(string s) {
//         //just after the operations need to check if the stack is empty or not
//         stack<char> st;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='{' || s[i]=='[' || s[i]=='('){
//                 st.push(s[i]);
//             }
//             else{
//                 // check the top
//                 if(s[i]=='}' && st.top()=='{')  st.pop();
//                 if(s[i]==']' && st.top()=='[') st.pop();
//                 if(s[i]==')' && st.top()=='(') st.pop();
//             }
//         }
//         if(st.empty()) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            else {
                // If there is no opening bracket
                if (st.empty()) {
                    return false;
                }

                // Check whether brackets match
                if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};