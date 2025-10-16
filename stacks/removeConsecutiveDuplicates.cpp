#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeConsecutiveDup(string s)
{
    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != st.top())
            st.push(s[i]);
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s = "aaaabbccdrree";
    cout << s << endl;
    s = removeConsecutiveDup(s);
    cout << s << endl;
}
