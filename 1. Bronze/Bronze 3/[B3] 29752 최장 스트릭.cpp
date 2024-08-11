#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        cnt += (s != 0 ? 1 : -cnt);
        result = max(result, cnt);
    }
    cout << result << '\n';
}