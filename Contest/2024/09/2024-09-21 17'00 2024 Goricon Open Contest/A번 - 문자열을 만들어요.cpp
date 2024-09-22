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

    string result = (s.find("gori") != -1 ? "YES" : "NO");
    cout << result << '\n';
}