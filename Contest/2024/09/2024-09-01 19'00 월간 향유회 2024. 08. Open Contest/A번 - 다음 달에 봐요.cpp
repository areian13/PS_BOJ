#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int q;
    cin >> q;

    int sum = 0;
    while (q--)
    {
        int t, x;
        cin >> t >> x;

        sum += x * (t == 1 ? +1 : -1);

        if (sum < 0)
            break;
    }

    string result = (sum < 0 ? "Adios" : "See you next month");
    cout << result << '\n';
}