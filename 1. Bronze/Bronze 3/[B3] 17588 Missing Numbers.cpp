#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 200

int main()
{
    FastIO;


    int n;
    cin >> n;

    array<bool, MAX + 1> num = { false, };
    int lastNum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        num[a] = true;
        lastNum = a;
    }

    string result = "";
    bool isGood = true;
    for (int i = 1; i <= lastNum; i++)
    {
        if (!num[i])
            result += to_string(i) + '\n';
        isGood &= num[i];
    }

    if (isGood)
        result = "good job";
    cout << result << '\n';
}