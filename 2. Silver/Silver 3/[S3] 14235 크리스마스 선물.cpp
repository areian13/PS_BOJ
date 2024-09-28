#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

int main()
{
    FastIO;

    int n;
    cin >> n;

    priority_queue<int> PQ;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a == 0)
        {
            if (PQ.empty())
                PQ.push(-1);
            cout << PQ.top() << '\n';
            PQ.pop();
        }
        else
        {
            for (int i = 0; i < a; i++)
            {
                int p;
                cin >> p;

                PQ.push(p);
            }
        }
    }
}