#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, s;
    cin >> n >> s;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (result > s)
            result--;

        int a;
        cin >> a;

        result += a;
    }
    cout << result << '\n';
}