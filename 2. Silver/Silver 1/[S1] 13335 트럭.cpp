#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, w, l;
    cin >> n >> w >> l;

    queue<int> Q;
    for (int i = 0; i < w; i++)
        Q.push(0);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        while (true)
        {
            if (l + Q.front() >= t)
            {
                l += Q.front() - t;
                Q.pop();
                Q.push(t);

                result++;
                break;
            }

            l += Q.front();
            Q.pop();
            Q.push(0);
            result++;
        }
    }

    while (!Q.empty())
    {
        result++;
        Q.pop();
    }
    cout << result << '\n';
}