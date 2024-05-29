#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountParity(string& bits)
{
    int n = bits.size();
    int cntOne = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 8 != 7 && bits[i] == '1')
            cntOne++;
        else if (i % 8 == 7)
        {
            if (cntOne % 2 != bits[i] - '0')
                result++;
            cntOne = 0;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string bits;
        cin >> bits;

        int result = CountParity(bits);
        cout << result << '\n';
    }
}