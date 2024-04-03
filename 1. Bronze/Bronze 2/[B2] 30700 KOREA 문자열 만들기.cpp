#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    cin >> str;

    string korea = "KOREA";
    int result = 0;
    for (char c : str)
        result += (c == korea[result % 5]);
    cout << result << '\n';
}