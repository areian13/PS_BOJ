#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define KIND 15'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<bool, KIND> has = { false, };
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        t--;

        has[t] = true;
    }

    int result = 0;
    for (int i = 0; i < KIND; i++)
        result += !has[i];
    cout << result << '\n';
}