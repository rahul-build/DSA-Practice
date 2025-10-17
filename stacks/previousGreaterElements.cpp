#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int pre[n];
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        // Pop elements smaller than current
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        // Assign previous greater
        pre[i] = st.empty() ? -1 : st.top();

        // Push current element
        st.push(arr[i]);
    }

    cout << "Previous Greater Elements: ";
    for (int i = 0; i < n; i++)
        cout << pre[i] << " ";
    cout << endl;

    // Complexity:
    // Time: O(n), Space: O(n) (stack) + O(n) (output array)
}
