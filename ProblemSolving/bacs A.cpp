#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d ", &t);
    for(int Case=1; Case<=t; Case++){
        int n;
        scanf("%d", &n);
        vector<int> arr(n);
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        bool allGoodDays=true, allBadDays=true;

        for(int i=1; i<n; i++){
            if(arr[i]<arr[i-1]){
                allGoodDays = false;
                break;
            }
        }

        for(int i=0; i<n-1; i++){
            if(arr[i]<arr[i+1]){
                allBadDays = false;
                break;
            }
        }

        int counter = 0, prev=0;
        for(int i=1; i<n-1; i++){
            if((arr[i]>arr[i-1] && arr[i]>arr[i+1])){
                if(prev==0) prev = i;
                else{
                    if(counter < (i - prev - 1)) counter = (i - prev - 1);
                    prev = i;
                }
            }
        }

        int Max = *max_element(arr.begin(), arr.end());
        int Min = *min_element(arr.begin(), arr.end());
        if(Max == Min){
            printf("neutral\n");
        }
        else if(counter>0) printf("%d\n", counter);
        else if(allGoodDays){
            printf("allGoodDays\n");
        }
        else if(allBadDays){
            printf("allBadDays\n");
        }
        else printf("none\n");

        arr.clear();
    }

    return 0;
}
