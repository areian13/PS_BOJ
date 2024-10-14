#include <iostream>
#include <deque>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    deque<int> DQ;
    while (n--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int x;
            cin >> x;

            DQ.push_front(x);
        }
        else if (cmd == 2)
        {
            int x;
            cin >> x;

            DQ.push_back(x);
        }
        else if (cmd == 3)
        {
            if (DQ.empty())
                DQ.push_front(-1);

            cout << DQ.front() << '\n';
            DQ.pop_front();
        }
        else if (cmd == 4)
        {
            if (DQ.empty())
                DQ.push_back(-1);

            cout << DQ.back() << '\n';
            DQ.pop_back();
        }
        else if (cmd == 5)
            cout << DQ.size() << '\n';
        else if (cmd == 6)
            cout << DQ.empty() << '\n';
        else if (cmd == 7)
            cout << (DQ.empty() ? -1 : DQ.front()) << '\n';
        else if (cmd == 8)
            cout << (DQ.empty() ? -1 : DQ.back()) << '\n';
    }
}