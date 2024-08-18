#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (s[i] - '0') % 2 == 0 ? +1 : -1;

    int result = (cnt == 0 ? -1 : (cnt > 0 ? 0 : 1));
    cout << result << '\n';
}