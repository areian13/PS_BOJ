#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Doc
{
    int idx;
    int priority;

    friend bool operator<(const Doc& a, const Doc& b)
    {
        return a.priority < b.priority;
    }
};

int main()
{
    FastIO;

    int tc;
    cin>> tc;

    while (tc--)
    {
        int n, m;
        cin>>n >> m;

        queue<Doc> Q;
        priority_queue<int> PQ;
        for (int i = 0; i < n; i++)
        {
            int priority;
            cin>>priority;

            Q.push({ i, priority });
            PQ.push(priority);
        }

        int result = 0;
        while (!Q.empty())
        {
            if (Q.front().priority == PQ.top())
            {
                result++;
                if (Q.front().idx == m)
                    break;

                Q.pop();
                PQ.pop();
            }
            else
            {
                Q.push(Q.front());
                Q.pop();
            }
        }
        cout << result << '\n';
    }
}