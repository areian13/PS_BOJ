#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountWow(string& s)
{
    int n = s.size();

    int result = 0;
    for (int i = 0; i < n - 2; i++)
        result += (s.substr(i, 3) == "WOW");
    return result;
}

int main()
{
    FastIO;

    int q;
    cin >> q;

    while (q--)
    {
        string s;
        cin >> s;

        int result = CountWow(s);
        cout << result << '\n';
    }
}