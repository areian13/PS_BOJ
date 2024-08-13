#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Shell(int n)
{
    n--;

    string result = "";
    result += 'a' + n % 8;
    result += '0' + n / 8 + 1;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = Shell(n);
    cout << result << '\n';
}