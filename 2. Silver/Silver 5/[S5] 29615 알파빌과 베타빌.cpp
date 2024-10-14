#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> wait(n);
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++)
    {
        cin >> wait[i];
        idx[wait[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int f;
        cin >> f;

        wait[idx[f]] = 0;
    }

    int result = 0;
    for (int i = 0; i < m; i++)
        result += (wait[i] != 0);
    cout << result << '\n';
}