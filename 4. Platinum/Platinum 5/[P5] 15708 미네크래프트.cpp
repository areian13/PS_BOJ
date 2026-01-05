#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxStone(int t, int p, vector<int>& k)
{
    int result = 0;
    long long sum = 0;
    priority_queue<int> pq;
    for (int r : k)
    {
        pq.push(r);
        sum += r;

        if (sum > t)
        {
            sum -= pq.top();
            pq.pop();
        }
        sum += p;
        result = max(result, (int)pq.size());
    }
    return result;
}

int main()
{
    FastIO;

    int n, t, p;
    cin >> n >> t >> p;

    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    int result = MaxStone(t, p, k);
    cout << result << '\n';
}