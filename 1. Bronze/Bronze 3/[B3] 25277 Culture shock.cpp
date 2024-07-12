#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsGendered(string& str)
{
    return str == "he" || str == "him" || str == "she" || str == "her";
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        result += IsGendered(str);
    }
    cout << result << '\n';
}