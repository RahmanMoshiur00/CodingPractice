#include<bits/stdc++.h>
using namespace std;

#define num 1000000 //defining the range of 1 to num to find the prime numbers

int main()
{

    bool mark[num]={}; //all the elements are "false" initialized by default

    mark[0] = true; //marks 0 as not prime number
    mark[1] = true; //marks 1 as not prime number

    vector<int> prime;

    prime.push_back(2); //putting 2 in prime vector as it is a prime number

    for(int i=4; i<=num; i+=2) mark[i] = true; //marking all the even numbers as not prime

    int sqt = sqrt(num+1.0); //adding 1.0 for betterment

    for(int i=3; i<=num; i+=2){ //starts multiple cutting with the odd numbers

        if(!mark[i]){

            prime.push_back(i);

            if(i<=sqt){ //because, we know, only the prime numbers between 2 to sqrt(num) are usable for multiple cutting
                for(int j=i*i; j<=num; j += i*2) mark[j] = true;
            }
        }
    }

    for(int i=0; i<prime.size(); i++) cout<<prime[i]<<" "; //printing primes from vector
    cout<<endl<<"count = "<<prime.size()<<endl; //printing how many primes are in the 1 to num range

    return 0;
}
