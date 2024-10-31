#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> PQ;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        PQ.push(a);
    }

    for (int i = 0; i < m; i++)
    {
        long long a = PQ.top();
        PQ.pop();
        long long b = PQ.top();
        PQ.pop();

        PQ.push(a + b);
        PQ.push(a + b);
    }

    long long result = 0;
    while (!PQ.empty())
    {
        result += PQ.top();
        PQ.pop();
    }
    cout << result << '\n';
}