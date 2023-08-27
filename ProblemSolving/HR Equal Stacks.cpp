#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int a1[n1], a2[n2], a3[n3], s1 = 0, s2 = 0, s3 = 0;
    for(int i=0; i<n1; i++) scanf("%d", &a1[i]), s1 += a1[i];
    for(int i=0; i<n2; i++) scanf("%d", &a2[i]), s2 += a2[i];
    for(int i=0; i<n3; i++) scanf("%d", &a3[i]), s3 += a3[i];

    int at1 = 0, at2 = 0, at3 = 0;
    while(!(s1==s2 && s2==s3)){
        if(s1>=s2 && s1>=s3){
            s1 -= a1[at1++];
        }
        else if(s2>=s1 && s2>=s3){
            s2 -= a2[at2++];
        }
        else{
            s3 -= a3[at3++ ];
        }
    }

    printf("%d\n", s1);
}
