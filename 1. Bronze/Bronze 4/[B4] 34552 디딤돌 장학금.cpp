#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<int> m(11);
    for (int i = 0; i < 11; i++)
        cin >> m[i];

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int b, s;
        double l;
        cin >> b >> l >> s;

        if (l >= 2.0 && s >= 17)
            result += m[b];
    }
    cout << result << '\n';
}