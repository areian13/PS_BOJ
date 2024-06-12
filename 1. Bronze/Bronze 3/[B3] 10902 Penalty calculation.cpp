#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int maxS = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int t, s;
        cin >> t >> s;
        if (maxS < s)
        {
            maxS = s;
            result = t + i * 20;
        }
    }
    cout << result << '\n';
}