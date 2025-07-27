#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<long long> result;
    queue<long long> Q;

    for (int i = 0; i <= 9; i++)
    {
        result.push_back(i);
        Q.push(i);
    }

    while (!Q.empty())
    {
        long long cur = Q.front();
        Q.pop();

        for (int i = 0; i < cur % 10; i++)
        {
            long long nxt = cur * 10 + i;
            result.push_back(nxt);
            Q.push(nxt);
        }
    }

    int n;
    cin >> n;

    if (n <= result.size())
        cout << result[n] << '\n';
    else
        cout << -1 << '\n';
}