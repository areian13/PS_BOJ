#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k = 4;

    string bins = "";
    for (int i = 0; i < 3; i++)
    {
        int dec;
        cin >> dec;

        string bin = "";
        for (int j = 0; j < k; j++)
        {
            bin += dec % 2 + '0';
            dec /= 2;
        }
        reverse(bin.begin(), bin.end());

        bins += bin;
    }

    string result = to_string(stoi(bins, nullptr, 2));
    result = string(4 - result.size(), '0') + result;
    cout << result << '\n';
}