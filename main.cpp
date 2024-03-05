#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int aSum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        aSum += a;
    }

    int bSum = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        bSum += b;
    }

    cout << bSum << ' ' << aSum << '\n';
}