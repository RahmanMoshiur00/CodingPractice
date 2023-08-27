#include<bits/stdc++.h>
using namespace std;

#define ERROR 0.01

int main()
{
    int n; // number of equations(variables)
    cin>>n;

    double arr[n+1][n+1], var[n];

    for(int i=0; i<n; i++){ //taking input
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
        cin>>arr[i][n];
    }

    for(int i=0; i<n; i++){
        var[i] = 0.0;
    }

    double mx_err = 1, sum, temp;
    while(mx_err > ERROR){
        mx_err = 0;
        for(int i=0; i<n; i++){
            sum = 0.0;
            for(int j=0; j<n; j++){
                if(j!=i) sum += arr[i][j] * var[j];
            }
            temp = (arr[i][n]-sum) / arr[i][i];
            mx_err = max(mx_err, fabs(var[i]-temp));
            var[i] = temp;
            cout<<"Variable["<<i+1<<"] = "<<var[i]<<endl;
        }
        cout<<endl;
    }

    cout<<"Converged solution:"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Variable["<<i+1<<"] = "<<var[i]<<endl;
    }

    return 0;
}

/*
3
5 -2 3 -1
-3 9 1 2
2 -1 -7 3
*/

