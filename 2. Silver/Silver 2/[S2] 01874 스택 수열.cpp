#include <iostream>
#include <vector>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void StackArray(vector<int>& arr)
{
    int n = arr.size();

    vector<char> result;
    stack<int> stk;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        while (stk.empty() || stk.top() < arr[i])
        {
            result.push_back('+');
            stk.push(num);
            num++;
        }

        if (stk.top() > arr[i])
        {
            cout << "NO" << '\n';
            return;
        }

        result.push_back('-');
        stk.pop();
    }

    for (char op : result)
        cout << op << '\n';
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    StackArray(arr);
}