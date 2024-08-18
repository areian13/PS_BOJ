#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    int n;
    cin >> s >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string l;
        cin >> l;

        result += (s.substr(0, 5) == l.substr(0, 5));
    }
    cout << result << '\n';
}