#include <bits/stdc++.h>
using namespace std;

double knapsack(pair<double, int> price_per_unit[], int n, int k)
{
    double ans = 0.0;
    for(int i = 0; i < n && k > 0; i++){
        int mn = min(price_per_unit[i].second, k);
        ans += price_per_unit[i].first * mn;
        k -= mn;
    }

    return ans;
}

int main()
{
    int n, k;
    cout << "Enter total number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> k;

    int weight[n], price[n];
    pair<double, int> price_per_unit[n];

    cout << "Enter weight and price of " << n << " items:\n";
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> price[i];
        price_per_unit[i].first = (double)price[i] / weight[i];
        price_per_unit[i].second = weight[i];
    }

    sort(price_per_unit, price_per_unit + n, greater< pair<double, int> >());

    double ans = knapsack(price_per_unit, n, k);

    cout << "Answer = " << fixed << setprecision(5) << ans << endl;
}


/*
5
10
4 20
3 10
2 15
1 3
6 33
*/
