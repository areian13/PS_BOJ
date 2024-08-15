#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Bill(int h, int w)
{
    if (h == 136)
        return 1'000;
    if (h == 142)
        return 5'000;
    if (h == 148)
        return 10'000;
    if (h == 154)
        return 50'000;
    return -1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;

        result += Bill(h, w);
    }
    cout << result << '\n';
}