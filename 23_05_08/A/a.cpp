#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        int len = s.length();
        if (len == 1)
        {
            cout << "-1\n";
            continue;
        }
        char prev = s[0];
        for (int j = 1; j < len; j++)
        {
            if (s[j] != prev)
            {
                cout << len - 1 << "\n";
                goto end;
            }
        }
        cout << "-1\n";
    end:;
    }

    return 0;
}