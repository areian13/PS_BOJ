#include <iostream>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    stack<pair<int, int>> stk;
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;

        while (!stk.empty() && stk.top().first < h)
        {
            result += stk.top().second;
            stk.pop();
        }

        if (!stk.empty() && stk.top().first == h)
            result += stk.top().second++;
        else
            stk.push({ h,1 });

        if (stk.size() > 1)
            result++;
    }
    cout << result << '\n';
}