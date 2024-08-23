#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int maxP = 0;
    string result = "";
    for (int i = 0; i < n; i++)
    {
        int p;
        string s, c;
        cin >> p >> s >> c;

        if (c == "Russia" && p > maxP)
        {
            result = s;
            maxP = p;
        }
    }
    cout << result << '\n';
}