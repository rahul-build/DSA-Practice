#include <iostream>
#include <stack>
using namespace std;

// Problem: Next Greater Element
// Pattern: Stack / Arrays

// Brute Force
// Logic: For each element, check all elements to the right
// Time: O(n^2), Space: O(n)
// int main()
// {
//     int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     // Print original array
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;

//     int ngx[n];

// -------------------- Brute Force --------------------
//     // Logic: For each element, check all elements to the right to find next greater
//     // Time: O(n^2), Space: O(n)
//     for (int i = 0; i < n; i++)
//     {
//         ngx[i] = -1; // default if no greater element exists
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] > arr[i])
//             {
//                 ngx[i] = arr[j];
//                 break;
//             }
//         }
//     }

//     // Print next greater elements
//     for (int i = 0; i < n; i++)
//         cout << ngx[i] << " ";
// }

// --------------------

// Optimal Approach (using stack)
// Logic: Traverse from end, use stack to track next greater
// Time: O(n), Space: O(n)

int main()
{

    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int ngx[n];

    stack<int> st;
    ngx[n - 1] = -1;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() < arr[i])
        {
            st.pop();
        }
        if (st.size() == 0)
            ngx[i] = -1;

        else
            ngx[i] = st.top();
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ngx[i] << " ";
}
// Approach | Time | Space(Auxiliary) | Total Space(including output) |

//     | Optimal(stack) | O(n) | O(n)(stack) | O(n) + O(n) = O(n) |
