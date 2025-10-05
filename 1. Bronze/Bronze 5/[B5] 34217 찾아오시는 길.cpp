#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Fast(int a, int b, int c, int d)
{
    if (a + c == b + d) return "Either";
    return a + c < b + d ? "Hanyang Univ." : "Yongdap";
}

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string result = Fast(a, b, c, d);
    cout << result << '\n';
}