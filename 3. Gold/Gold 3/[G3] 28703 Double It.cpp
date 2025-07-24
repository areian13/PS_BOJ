#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> PQ;
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;

        PQ.push(a);
        maxA = max(maxA, a);
    }

    int originMaxA = maxA;
    int result = INT_MAX;
    while (true)
    {
        int minA = PQ.top();
        PQ.pop();

        result = min(result, maxA - minA);

        if (minA == originMaxA)
            break;

        PQ.push(minA * 2);
        maxA = max(maxA, minA * 2);
    }
    cout << result << '\n';
}