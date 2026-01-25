#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        int l = 0, w = 0;
        while (true)
        {
            string s;
            getline(cin, s);

            if (s.empty())
                break;

            l += s.size();
            for (char c : s)
                w += (c == '#');
        }

        double result = round(1000. * (l - w) / l) / 10;
        cout << "Efficiency ratio is " << result << "%.\n";
    }
}