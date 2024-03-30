#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GetSecRecord(string& record)
{
    int result = 0;
    result += (record[0] - '0') * 3600;
    result += ((record[2] - '0') * 10 + (record[3] - '0')) * 60;
    result += (record[5] - '0') * 10 + (record[6] - '0');
    return result;
}

int main()
{
    FastIO;

    int n;
    double d;
    cin >> n >> d;

    while (true)
    {
        int t;
        cin >> t;

        if (cin.eof())
            break;

        double sum = 0;
        bool isDisqualified = false;
        for (int i = 0; i < n; i++)
        {
            string record;
            cin >> record;

            if (isDisqualified || record == "-:--:--")
            {
                isDisqualified = true;
                continue;
            }
            
            sum += GetSecRecord(record);
        }
        
        int m = sum / 60 / d;
        int s = (sum / 60 / d - m) * 60 + 0.5;
        if (s == 60)
        {
            m++;
            s = 0;
        }

        if (isDisqualified)
            printf("%3d: -\n", t);
        else
            printf("%3d: %d:%02d min/km\n", t, m, s);
    }
}