#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    string str;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        str += c;
    }

    string target = str;
    sort(target.begin(), target.end());

    unordered_map<string, bool> isVisited;
    isVisited[str] = true;

    queue<pair<string, int>> Q;
    Q.push({ str,0 });

    int result = -1;
    while (!Q.empty())
    {
        pair<string, int> cur = Q.front();
        Q.pop();

        if (cur.first == target)
        {
            result = cur.second;
            break;
        }
        for (int i = 0; i < n - k + 1; i++)
        {
            string temp = cur.first;
            reverse(temp.begin() + i, temp.begin() + i + k);

            if (isVisited[temp])
                continue;

            isVisited[temp] = true;
            Q.push({ temp, cur.second + 1 });
        }
    }
    cout << result << '\n';
}