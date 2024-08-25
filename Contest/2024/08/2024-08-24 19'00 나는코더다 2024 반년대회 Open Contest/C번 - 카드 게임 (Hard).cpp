#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountCard(int h, priority_queue<int>& PQ)
{
    int sum = 0;
    int result = 0;
    priority_queue<int> temp;
    while (!PQ.empty())
    {
        result++;

        sum += PQ.top();
        temp.push(PQ.top());
        PQ.pop();

        if (sum >= h)
        {
            while (!temp.empty())
            {
                PQ.push(temp.top());
                temp.pop();
            }
            return result;
        }
    }

    while (!temp.empty())
    {
        PQ.push(temp.top());
        temp.pop();
    }

    return -1;
}

int main()
{
    FastIO;

    int h, n, q;
    cin >> h >> n >> q;

    priority_queue<int> PQ;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        PQ.push(d);
    }

    cout << CountCard(h, PQ) << '\n';

    while (q--)
    {
        int x;
        cin >> x;

        PQ.push(x);

        cout << CountCard(h, PQ) << '\n';
    }
}