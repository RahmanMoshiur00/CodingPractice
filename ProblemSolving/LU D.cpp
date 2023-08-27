#include<bits/stdc++.h>

using namespace std;

const int k = 110000; //you can change this constant to whatever maximum int you would need to calculate
long int p[k]; //here we would store Sieve of Erathostenes from 2 to k
long int j;

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

void init_prime() //in here we set our array
{
    for (int i = 2; i <= k; i++)
    {
        if (p[i] == 0)
        {
            j = i;
            while (j <= k)
            {
                p[j] = i;
                j = j + i;
            }
        }
    }
    /*for (int i = 2; i <= k; i++)
        cout << p[i] << endl;*/ //if you uncomment this you can see the output of initialization...
}

string prime(int first, int last) //this is example of how you can use initialized array
{
    string result = "";
    for (int i = first; i <= last; i++)
    {
        if (p[i] == i)
            result += NumberToString(i);
    }
    return result;
}

int main() //I done this code some time ago for one contest, when first input was number of cases and then actual input came in so nocases means "number of cases"...
{
    int nocases, first, last;
    init_prime();
    cin >> nocases;
    for (int i = 1; i <= nocases; i++)
    {
        cin >> first >> last;
        cout << prime(first, last);
    }
    return 0;
}
