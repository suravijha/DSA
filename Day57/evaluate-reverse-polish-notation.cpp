// LeetCode 150
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (auto &c : tokens)
        {
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                if (c == "+")
                    st.push(first + second);
                if (c == "-")
                    st.push(first - second);
                if (c == "*")
                    st.push(first * second);
                if (c == "/")
                    st.push(first / second);
            }
            else
            {
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};