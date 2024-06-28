#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string code;
    int n;
    cin >> code >> n;

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        string format;
        cin >> format;

        int l = (format == "char" ? 2 : (format == "int" ? 8 : 16));
        long long result = stoll(code.substr(idx, l), nullptr, 16);
        cout << result << ' ';

        idx += l;
    }
}