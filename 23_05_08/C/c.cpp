#include <iostream>
#include <unordered_set>

using namespace std;
const int maxP = 1e5 + 5;
int pref[maxP];
int cntSmallerTo[maxP];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    unordered_set<int> numberedPlaces;
    for (int i = 0; i < t; i++)
    {
        numberedPlaces.clear();

        int people, chairs;
        int min1Cnt = 0, min2Cnt = 0;
        cin >> people >> chairs;
        for (int j = 0; j < chairs + 2; j++)
            cntSmallerTo[j] = 0;
        for (int j = 0; j < people; j++)
        {

            cin >> pref[i];
            if (pref[i] > 0)
            {
                numberedPlaces.insert(pref[i]);
            }
            else if (pref[i] == -1)
                min1Cnt++;
            else
                min2Cnt++;
        }
        for (unordered_set<int>::iterator itr = numberedPlaces.begin(); itr != numberedPlaces.end(); itr++)
        {
            // cout << *itr << "\n";
            cntSmallerTo[*itr]++;
        }
        for (int j = 1; j <= chairs + 1; j++)
        {
            cntSmallerTo[j] += cntSmallerTo[j - 1];
            // cout << "cntSmallerTo[" << j << "] = " << cntSmallerTo[j] << "\n";
        }
        int res = 0;
        for (unordered_set<int>::iterator itr = numberedPlaces.begin(); itr != numberedPlaces.end(); itr++)
        {
            // cout << "Consider if first goes: " << *itr << "\n";
            int curRes = 0;
            int smaller = cntSmallerTo[*itr - 1];
            int larger = numberedPlaces.size() - cntSmallerTo[*itr];
            // cout << "Smaller than: " << smaller << "\n";
            // cout << "Larger than: " << larger << "(" << numberedPlaces.size() << " - " << cntSmallerTo[*itr] << "\n";
            // cout << "-1 rem: " << min(min1Cnt, *itr - 1 - smaller) << "\n";
            int rem2 = chairs - *itr - larger;
            // cout << "-2 rem: " << min(min2Cnt, rem2) << "\n";
            res = max(res, 1 + smaller + larger + min(min2Cnt, rem2) + min(min1Cnt, *itr - 1 - smaller));
        }

        // start from -1
        res = max(res, int(numberedPlaces.size()) + min(min1Cnt, (int)(chairs - numberedPlaces.size())));
        // start from -2
        res = max(res, int(numberedPlaces.size()) + min(min2Cnt, (int)(chairs - numberedPlaces.size())));

        cout << res << "\n";
    }

    return 0;
}