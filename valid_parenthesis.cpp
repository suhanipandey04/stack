#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(std::string str) {
       stack<char> st;
        
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') { //opening
                st.push(str[i]);
            } else { //closing
                if(st.size() == 0) {
                    return false;
                }
                
                if((st.top() == '(' && str[i] == ')') ||
                   (st.top() == '{' && str[i] == '}') ||
                   (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                } else { //no match
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string testStr = "{[()]}";
    bool result = solution.isValid(testStr);
    cout << "Is the string valid? " << (result ? "true" : "false") << endl;
    return 0;
}