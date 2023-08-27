#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           100010


vector<int> heap;


//For building MAX HEAP
void Heapify_up(int i){
    if(i==0) return;
    int par_i = (i-1)/2;
    if(heap[i]>heap[par_i]){
        swap(heap[i], heap[par_i]);
        Heapify_up(par_i);
    }
}
void Heapify_down(int i){
    int sz = heap.size();
    int l = (2*i)+1; //left child of i
    int r = (2*i)+2; //right child of i
    if(l>=sz) return; //no child exists of ith node
    if(l<sz && r<sz){ //both children of ith node exists
        //As we've built a max heap, it's guaranteed that the last node is always smaller than it's parent
        //and we are removing the top element from max heap
        //and putting the last element in top and then heapify_down takes place
        if(heap[l]>heap[r] && heap[l]>heap[i]){ //left child is greater than the right child
            swap(heap[l], heap[i]);
            Heapify_down(l);
        }
        else if(heap[l]<=heap[r] && heap[r]>heap[i]){ //right child is greater than or equal to the left child
            //we are taking the right child when heap[l]==heap[r],
            //because right subtree must have less than or equal children of left subtree
            swap(heap[r], heap[i]);
            Heapify_down(r);
        }
    }
    else if(l<sz && heap[l]>heap[i]){ //ith node has only the left child
        swap(heap[l], heap[i]);
        Heapify_down(l);
    }
}

void Insert(int n){ //inserts an element in the heap
    heap.pb(n);
    Heapify_up(heap.size() - 1);
}

int Top(){
    return heap[0];
}

void Pop(){
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    Heapify_down(0);
}


//For building MIN HEAP
/*
void Heapify_up(int i){
    if(i==0) return;
    int par_i = (i-1)/2;
    if(heap[i]<heap[par_i]){
        swap(heap[i], heap[par_i]);
        Heapify_up(par_i);
    }
}
void Heapify_down(int i){
    int sz = heap.size();
    int l = (2*i)+1; //left child of i
    int r = (2*i)+2; //right child of i
    if(l>=sz) return; //no child exists of ith node
    if(l<sz && r<sz){ //both children of ith node exists
        if(heap[l]<heap[r] && heap[l]<heap[i]){
            swap(heap[l], heap[i]);
            Heapify_down(l);
        }
        else if(heap[l]>=heap[r] && heap[r]<heap[i]){
            swap(heap[r], heap[i]);
            Heapify_down(r);
        }
    }
    else if(l<sz && heap[l]<heap[i]){ //ith node has only the left child
        swap(heap[l], heap[i]);
        Heapify_down(l);
    }
}

void Insert(int n){ //inserts an element in the heap
    heap.pb(n);
    Heapify_up(heap.size() - 1);
}

int Top(){
    return heap[0];
}

void Pop(){
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    Heapify_down(0);
}
*/

int main()
{
    FasterIO

    int n, m; cin>>n;
    for(int i=0; i<n; i++){
        cin>>m;
        Insert(m);
    }
    int arr[n];
    for(int i=0; i<n; i++){ //printing sorted array in decreasing order
        arr[i] = Top();
        Pop();
    }

    cout<<arr[n/2]<<endl; //median of the given numbers; accepted code

    return 0;
}

