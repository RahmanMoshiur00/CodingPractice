#include<bits/stdc++.h>
using namespace std;

struct crane{
    int position = 1;
    int weight = 0;
};

int main()
{
    int max_weight, n, cmnd=1;
    cin>>n>>max_weight;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];
    crane cr;
    while(cmnd){
        cin>>cmnd;
        if(cmnd==1){
            if(cr.position>1) cr.position--;
        }
        else if(cmnd==2){
            if(cr.position<n) cr.position++;
        }
        else if(cmnd==3){
            if(arr[cr.position]>0 && cr.weight==0){
                cr.weight = arr[cr.position];
                arr[cr.position]--;
            }
        }
        else if(cmnd==4){
            if(arr[cr.position]<max_weight && cr.weight>0){
                arr[cr.position]++;
                cr.weight = 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<arr[i];
        if(i!=n) cout<<" ";
    }
    cout<<endl;

    return 0;
}
