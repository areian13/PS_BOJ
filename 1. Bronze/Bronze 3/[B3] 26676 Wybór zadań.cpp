#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsRightSet(unordered_map<string, int>& cnt)
{
    for (char round = '1'; round <= '5'; round++)
    {
        for (char work = 'A'; work <= 'C'; work++)
        {
            string set = round + string() + work;
            if (cnt[set] < 1 + (round == '5'))
                return false;
        }
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin>> n;

    unordered_map<string, int> cnt;
    for (int i = 0; i < n; i++)
    {
        string set;
        cin>>set;

        cnt[set]++;
    }

    string result = (IsRightSet(cnt) ? "TAK" : "NIE");
    cout << result << '\n';
}