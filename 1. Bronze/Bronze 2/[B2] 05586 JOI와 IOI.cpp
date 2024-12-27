#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    int joi = 0, ioi = 0;
    for (int i = 0; i < n - 2; i++)
    {
        string sub = s.substr(i, 3);
        joi += (sub == "JOI");
        ioi += (sub == "IOI");
    }
    cout << joi << '\n';
    cout << ioi << '\n';
}