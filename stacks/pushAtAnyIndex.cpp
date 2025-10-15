#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> &st)
{
    stack<int> temp;

    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        st.push(temp.top()); // restore stack
        temp.pop();
    }

    cout << endl;
}

void pushAtAnyIndex(stack<int> &st, int index, int val)
{
    stack<int> temp;
    while (st.size() > index)
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while (temp.size() > 0)
    {
        st.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    print(st);
    pushAtAnyIndex(st, 3, 80);
    print(st);
}
