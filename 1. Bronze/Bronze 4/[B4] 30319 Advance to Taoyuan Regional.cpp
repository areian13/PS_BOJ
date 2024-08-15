#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string date;
    cin >> date;

    string result = (date <= "2023-09-16" ? "GOOD" : "TOO LATE");
    cout << result << '\n';
}