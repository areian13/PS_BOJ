#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = 0;
    int angry = 0;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;

        angry += (r == 1 ? +1 : -1);
        result += angry;
    }
    cout << result << '\n';
}