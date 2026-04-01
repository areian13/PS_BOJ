#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Omission(string& s)
{
    int n = s.size();
    if (n <= 25) return s;

    string m = s.substr(11, n - 22);
    int i = m.find('.');
    if (i == -1 || i == m.size() - 1)
        return s.substr(0, 11) + "..." + s.substr(n - 11);

    return s.substr(0, 9) + "......" + s.substr(n - 10);
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = Omission(s);
    cout << result << '\n';
}