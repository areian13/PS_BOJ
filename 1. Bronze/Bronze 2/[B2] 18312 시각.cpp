#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool HasK(int t, int k)
{
    string h = to_string(t / (60 * 60));
    string m = to_string(t / 60 % 60);
    string s = to_string(t % 60);

    if (h.size() == 1) h = '0' + h;
    if (m.size() == 1) m = '0' + m;
    if (s.size() == 1) s = '0' + s;

    return (h + m + s).find(k + '0') != -1;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int t = n * 60 * 60 + 59 * 60 + 59;
    int result = 0;
    for (int i = 0; i <= t; i++)
        result += HasK(i, k);
    cout << result << '\n';
}