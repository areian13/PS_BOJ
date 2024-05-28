#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    int result = n;
    vector<bool> isInfected(n, false);
    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int x;
            cin >> x;
            x--;

            result -= !isInfected[x];
            isInfected[x] = true;
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            x--;

            result += isInfected[x];
            isInfected[x] = false;
        }
        else
            cout << result << '\n';
    }
}