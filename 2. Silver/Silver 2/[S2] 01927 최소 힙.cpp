#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != 0)
            PQ.push(x);
        else
        {
            if (PQ.empty())
                PQ.push(0);

            cout << PQ.top() << '\n';
            PQ.pop();
        }
    }
}