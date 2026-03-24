#include <iostream>
#include <string>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    getline(cin, a) >> b;

    stringstream ss(a);
    string t;

    int result = 0;
    while (ss >> t)
        result += (t != b && t.substr(0, b.size()) == b);
    cout << result << '\n';
}