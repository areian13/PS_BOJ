#include <iostream>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    stack<int> S;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int x;
            cin >> x;

            S.push(x);
        }
        else if (q == 2)
        {
            if (S.empty())
                S.push(-1);

            cout << S.top() << '\n';
            S.pop();
        }
        else if (q == 3)
            cout << S.size() << '\n';
        else if (q == 4)
            cout << S.empty() << '\n';
        else if (q == 5)
            cout << (S.empty() ? -1 : S.top()) << '\n';
    }
}