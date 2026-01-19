#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, int> cnt;
    string result;
    int maxC = 0;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;

        for (int j = 0; j < t; j++)
        {
            string a;
            cin >> a;
            cnt[a]++;

            if (cnt[a] > maxC)
            {
                maxC = cnt[a];
                result = a;
            }
            else if (cnt[a] == maxC)
                result = "-1";
        }
    }

    cout << result << '\n';
}