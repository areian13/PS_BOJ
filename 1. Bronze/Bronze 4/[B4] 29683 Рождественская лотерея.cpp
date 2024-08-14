#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a;
    cin >> n >> a;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        result += k / a;
    }
    cout << result << '\n';
}