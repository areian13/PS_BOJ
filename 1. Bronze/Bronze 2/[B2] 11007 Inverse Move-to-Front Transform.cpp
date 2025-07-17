#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        string abc = "abcdefghijklmnopqrstuvwxyz";
        string result = "";
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            char c = abc[a];
            result += c;
            abc.erase(abc.begin() + a);
            abc = c + abc;
        }
        cout << result << '\n';
    }
}