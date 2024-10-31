#include <iostream>
#include <queue>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    queue<int> Q;
    for (int i = 1; i <= n; i++)
        Q.push(i);

    string result = "<";
    while (!Q.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }

        result += to_string(Q.front()) + ", ";
        Q.pop();
    }
    result.pop_back();
    result.pop_back();
    result += ">";

    cout << result << '\n';
}