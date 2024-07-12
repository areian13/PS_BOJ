#include <iostream>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k;
    cin >> k;

    stack<int> S;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;

        if (a == 0)
            S.pop();
        else
            S.push(a);
    }

    int result = 0;
    while (!S.empty())
    {
        result += S.top();
        S.pop();
    }
    cout << result << '\n';
}