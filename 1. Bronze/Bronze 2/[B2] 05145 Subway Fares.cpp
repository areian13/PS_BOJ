#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;

        vector<int> s(n);
        for (int i = 1; i < n; i++)
            cin >> s[i];

        unordered_map<string, int> station;
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;

            station[name] = i;
        }

        string start, end;
        cin >> start >> end;

        int dist = abs(station[start] - station[end]);

        int result = s[dist];
        printf("Data Set %d:\n%d\n\n", t, result);
    }
}