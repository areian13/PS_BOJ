#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int a, l;
        cin >> a >> l;

        sum += a * l;
    }

    int n, kwf;
    cin >> n >> kwf;

    int result = (sum / 5) * n / kwf;
    cout << result << '\n';
}