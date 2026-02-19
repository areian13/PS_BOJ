#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() > 1)
    {
        cout << q.front() << ' ';
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << '\n';
}