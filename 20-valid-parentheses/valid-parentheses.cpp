class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        stack<char> st;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                i++;
            } else {
                if (st.empty())
                    return false;
                if (s[i] == ')') {

                    char ch = st.top();
                    if (ch != '(')
                        return false;
                    st.pop();
                    i++;
                } else if (s[i] == '}') {

                    char ch = st.top();
                    if (ch != '{')
                        return false;
                    st.pop();
                    i++;
                } else if (s[i] == ']') {
                    if (i == 0)
                        return false;
                    char ch = st.top();
                    if (ch != '[')
                        return false;
                    st.pop();
                    i++;
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};