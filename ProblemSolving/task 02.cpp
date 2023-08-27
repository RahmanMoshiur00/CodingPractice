#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    double mat[n+1][n+1], var[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            cin>>mat[i][j];
        }
    }

    if(mat[0][0] == 0){
        for(int i=1; i<n; i++){
            if(mat[i][0] != 0){
                for(int j=0; j<n; j++){
                    swap(mat[0][j], mat[i][j]);
                }
                break;
            }
        }
    }

    for(int k=0; k<n-1; k++){
        for(int i=k+1; i<n; i++){
            double p = mat[i][k] / mat[k][k];
            for(int j=k; j<n+1; j++){
                mat[i][j] = mat[i][j] - (p*mat[k][j]);
            }
        }
    }

    var[n-1] = mat[n-1][n] / mat[n-1][n-1];
    for(int i=n-2; i>=0; i--){
        double s = 0;
        for(int j=i+1; j<n; j++){
            s += (mat[i][j] * var[j]);
            var[i] = (mat[i][n]-s) / mat[i][i];
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
2 3 -1 5
4 4 -3 3
2 -3 2 2
*/
