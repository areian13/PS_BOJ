#include <iostream>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        result += max((int)pow(s, m), 0);
    }
    cout << result << '\n';
}