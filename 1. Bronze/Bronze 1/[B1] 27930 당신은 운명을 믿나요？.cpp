#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string korea = "KOREA";
    string yonsei = "YONSEI";
    int k = 0;
    int y = 0;

    string str;
    cin >> str;

    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == korea[k])
            k++;
        if (str[i] == yonsei[y])
            y++;

        if (k == korea.size() || y == yonsei.size())
            break;
    }

    string result = (k == korea.size() ? korea : yonsei);
    cout << result << '\n';
}