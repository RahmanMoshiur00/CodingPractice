#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // number of equations
    cin>>n;

    double arr[n+1][n+1], var[n];

    for(int i=0; i<n; i++){ //taking input
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
        cin>>arr[i][n];
    }

    if(arr[0][0] == 0){ //pivoting
        for(int i=1; i<n; i++){
            if(arr[i][0] != 0){
                for(int j=0; j<n; j++){
                    swap(arr[0][j], arr[i][j]); //swapping pivot row
                }
                break;
            }
        }
    }

    for(int k=0; k<n-1; k++){
        for(int i=k+1; i<n; i++){
            double p = arr[i][k] / arr[k][k];
            for(int j=k; j<n+1; j++){
                arr[i][j] = arr[i][j] - (p*arr[k][j]);
            }
        }
    }

    var[n-1] = arr[n-1][n] / arr[n-1][n-1];
    for(int i=n-2; i>=0; i--){
        double s = 0;
        for(int j=i+1; j<n; j++){
            s += (arr[i][j] * var[j]);
            var[i] = (arr[i][n]-s) / arr[i][i];
        }
    }

    cout<<"Results:"<<endl;
    for(int i=0; i<n; i++){
        cout<<fixed<<setprecision(5)<<"Variable["<<i+1<<"] = "<<var[i]<<endl;
    }

    return 0;
}

/*
3
3 6 1 16
2 4 3 13
1 3 2 9
*/
