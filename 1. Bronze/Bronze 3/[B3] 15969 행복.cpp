#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int maxS = 0, minS = 1'000;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        maxS = max(maxS, s);
        minS = min(minS, s);
    }

    int result = maxS - minS;
    cout << result << '\n';
}