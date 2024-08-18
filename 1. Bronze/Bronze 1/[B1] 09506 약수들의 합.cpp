#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin>>n;

        if (n == -1)
            break;

        vector<int> div;
        int sum = 0;
        for (int d = 1; d <= n / 2; d++)
        {
            if (n % d == 0)
            {
                div.push_back(d);
                sum += d;
            }
        }

        string result = to_string(n);
        if (sum != n)
            result += " is NOT perfect.";
        else
        {
            result += " = ";
            for (int d : div)
                result += to_string(d) + " + ";
            result.pop_back();
            result.pop_back();
        }
        cout << result << '\n';
    }
}