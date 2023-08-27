#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        vector<int> triangle(3);
        scanf("%d %d %d", &triangle[0], &triangle[1], &triangle[2]);
        sort(triangle.begin(), triangle.end());
        if((triangle[0]*triangle[0])+(triangle[1]*triangle[1]) == (triangle[2]*triangle[2])) printf("Case %d: yes\n", l);
        else printf("Case %d: no\n", l);
    }
    return 0;
}
