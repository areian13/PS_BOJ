#include <iostream>
#include <queue>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int x;
            cin >> x;

            Q.push(x);
        }
        else if (cmd == "pop")
        {
            if (Q.empty())
                Q.push(-1);

            cout << Q.front() << '\n';
            Q.pop();
        }
        else if (cmd == "size")
            cout << Q.size() << '\n';
        else if (cmd == "empty")
            cout << Q.empty() << '\n';
        else if (cmd == "front")
            cout << (Q.empty() ? -1 : Q.front()) << '\n';
        else if (cmd == "back")
            cout << (Q.empty() ? -1 : Q.back()) << '\n';
    }
}