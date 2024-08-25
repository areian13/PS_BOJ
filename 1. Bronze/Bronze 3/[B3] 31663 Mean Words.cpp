#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> words(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        k = max(k, (int)words[i].size());
    }

    string result(k, '\0');
    for (int j = 0; j < k; j++)
    {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (j >= words[i].size())
                continue;

            sum += words[i][j];
            cnt++;
        }

        result[j] = (double)sum / cnt;
    }
    cout << result << '\n';
}