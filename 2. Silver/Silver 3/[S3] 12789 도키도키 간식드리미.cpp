#include <iostream>
#include <queue>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin>>n;

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin>>s;

        Q.push(s);
    }

    int k = 1;
    stack<int> S;
    while (!Q.empty())
    {
        if (Q.front() == k)
        {
            Q.pop();
            k++;
        }
        else if(!S.empty() && S.top() == k)
        {
            S.pop();
            k++;
        }
        else
        {
            S.push(Q.front());
            Q.pop();
        }
    }
    while (!S.empty())
    {
        if (S.top() == k)
        {
            S.pop();
            k++;
        }
        else
            break;
    }

    string result = (k - 1 == n ? "Nice" : "Sad");
    cout << result << '\n';
}