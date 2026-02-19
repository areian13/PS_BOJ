#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Op(string& a, string& o, string& b)
{
    bool ab = (a == "true");
    bool bb = (b == "true");
    return (o == "AND" ? ab & bb : ab | bb) ? "true" : "false";
}

int main()
{
    FastIO;

    string a, o, b;
    cin >> a >> o >> b;

    string result = Op(a, o, b);
    cout << result << '\n';
}