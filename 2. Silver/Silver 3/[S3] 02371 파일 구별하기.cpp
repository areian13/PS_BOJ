#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> files(n);
    int maxFile = 0;
    for (auto& file : files)
    {
        while (true)
        {
            int d;
            cin >> d;
            if (d == -1)
                break;
            file.push_back(d);
        }
        maxFile = max(maxFile, (int)file.size());
    }

    for (auto& file : files)
        file.resize(maxFile, 0);
    sort(files.begin(), files.end());

    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t = 0;
        while (t < maxFile && files[i][t] == files[i + 1][t])
            t++;
        k = max(k, t);
    }


    cout << k + 1 << '\n';
}