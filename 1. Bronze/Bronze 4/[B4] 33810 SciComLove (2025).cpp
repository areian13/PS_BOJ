#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string origin = "SciComLove";

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = 0;
    for (int i = 0; i < origin.size(); i++)
        result += (s[i] != origin[i]);
    cout << result << '\n';
}