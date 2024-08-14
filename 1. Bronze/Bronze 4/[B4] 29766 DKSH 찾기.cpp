#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    cin >> str;

    int n = str.size();

    int result = 0;
    for (int i = 0; i < n - 3; i++)
        result += (str.substr(i, 4) == "DKSH");
    cout << result << '\n';
}