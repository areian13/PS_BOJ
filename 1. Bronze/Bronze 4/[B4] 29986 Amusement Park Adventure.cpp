#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, h;
    cin >> n >> h;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        result += (a <= h);
    }
    cout << result << '\n';
}