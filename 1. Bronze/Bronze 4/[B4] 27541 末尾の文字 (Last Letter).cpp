#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    if (s[n - 1] == 'G')
        s.pop_back();
    else
        s.push_back('G');

    cout << s << '\n';
}