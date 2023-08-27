#include <bits/stdc++.h>
using namespace std;

const int mxn = 100010;

int tree[3 * mxn];

void build(int ind, int bg, int ed)
{
    if(bg == ed){
        tree[ind] = arr[bg];
        return;
    }

    int mid = (bg + ed) / 2;
    int left_ind = 2 * ind;
    int right_ind = left_ind + 1;

    build(left_ind, bg, mid);
    build(right_ind, mid+1, ed);
}

int query(int ind, int bg, int ed, int i, int j)
{
    if(i>=bg and ed<=j){ //into the segment
        return tree[ind];
    }
    if(ed<i or bg>j){ //out of the segment
        return 0;
    }

    //overlaped with the segment
    int mid = (bg + ed) / 2;
    int left_ind = 2 * ind;
    int right_ind = left_ind + 1;

    return ( query(left_ind, bg, mid, i, j) + query(right_ind, mid+1, ed, i, j) );
}

void update(int ind, int bg, int ed, int i, int j, int value)
{
    if(i>=bg and ed<=j){
        tree[i] = value;
        return;
    }
    if(ed<i or bg>j){
        return;
    }

    int mid = (bg + ed) / 2;
    int left_ind = 2 * ind;
    int right_ind = left_ind + 1;

    update(left_ind, bg, mid, i, j, value);
    update(right_ind, mid+1, ed, i, j, value);

    tree[ind] = tree[left_ind] + tree[right_ind];
}

int main()
{

}
