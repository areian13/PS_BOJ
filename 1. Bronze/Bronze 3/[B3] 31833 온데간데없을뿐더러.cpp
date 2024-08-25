#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string x = "";
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;

        x += a;
    }

    string y = "";
    for (int i = 0; i < n; i++)
    {
        string b;
        cin >> b;

        y += b;
    }

    long long result = min(stoll(x), stoll(y));
    cout << result << '\n';
}