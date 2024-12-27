#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    bool dir = 0;
    long long speed = 1;
    for (int i = 0; i < n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        dir = (s == 0 ? dir : !dir);

        speed *= b;
        speed /= a;
    }
    cout << dir << ' ' << speed << '\n';
}