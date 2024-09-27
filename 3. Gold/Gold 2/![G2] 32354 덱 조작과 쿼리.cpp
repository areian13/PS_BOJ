#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Status
{
    int idx, prev;
    int cmd, value;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Status> tree(n + 1);
    int prev = 0;
    tree[0].idx = 0;
    stack<int> S;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        tree[i] = { i,prev };

        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int x;
            cin >> x;

            tree[i].cmd = 0;
            tree[i].value = x;

            S.push(x);
            result += x;
        }
        else if (cmd == "pop")
        {
            tree[i].cmd = 1;

            result -= S.top();
            S.pop();
        }
        else if (cmd == "restore")
        {
            int idx;
            cin >> idx;

            tree[i].cmd = 2;
            tree[i].value = idx;
        }
        else
            tree[i].cmd = 3;

        if (tree[i].cmd == 2)
        {
            prev = tree[i].value;

            while (!S.empty())
                S.pop();
            result = 0;

            stack<Status> temp;
            int idx = prev;
            while (idx != 0)
            {
                temp.push(tree[idx]);
                idx = tree[idx].prev;
            }

            while (!temp.empty())
            {
                Status status = temp.top();
                temp.pop();

                if (status.cmd == 0)
                {
                    S.push(status.value);
                    result += status.value;
                }
                else if (status.cmd == 1)
                {
                    result -= S.top();
                    S.pop();
                }
            }

            continue;
        }
        else if (tree[i].cmd == 3)
            cout << result << '\n';

        prev = i;
    }
}