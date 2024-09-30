#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, d;
    cin >> n >> d;

    priority_queue<int> pq;
    for (int i = 0; i < n - 1; i++)
    {
        int k;
        cin >> k;

        pq.push(k);
    }

    int result = 0;
    while (!pq.empty() && pq.top() >= d)
    {
        pq.push(pq.top() - 1);
        pq.pop();

        d++;
        result++;
    }
    cout << result << '\n';
}