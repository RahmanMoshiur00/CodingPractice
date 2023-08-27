#include <bits/stdc++.h>
using namespace std;

void show_size(vector<int>& v)
{
    cout<<v.size()<<endl;
}

void show_vector(vector<int>& v)
{
    for(int i=0; i<v.size(); i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    vector<int> vec;

    cout<<"Initial size: ";
    show_size(vec);
    cout<<"Initial vector: ";
    show_vector(vec);

    for(int i=0; i<5; i++){
        int v;
        cin>>v;
        vec.push_back(v);
    }

    cout<<"Size after inserting 5 elements: ";
    show_size(vec);
    cout<<"Elements after inserting 5 elements: ";
    show_vector(vec);

    int mx = *max_element(vec.begin(), vec.end());
    int mn = *min_element(vec.begin(), vec.end());
    cout<<"Max element: "<<mx<<endl;
    cout<<"Min element: "<<mn<<endl;

    sort(vec.begin(), vec.end());

    cout<<"Size after sorting: ";
    show_size(vec);
    cout<<"Elements after sorting(ascending order): ";
    show_vector(vec);

    sort(vec.begin(), vec.end(), greater<int>());

    cout<<"Size after sorting: ";
    show_size(vec);
    cout<<"Elements after sorting(descending order): ";
    show_vector(vec);

    vec.erase(vec.begin()+1, vec.begin()+2);
    cout<<"Size after erasion: ";
    show_size(vec);
    cout<<"Elements after erasion: ";
    show_vector(vec);

    vector<int> vec2(3, 5);
    cout<<"Size of vec2 after declaration: ";
    show_size(vec2);
    cout<<"vec2 elements after declaration: ";
    show_vector(vec2);

    vec2.insert(vec2.begin()+1, 7);
    vec2.insert(vec2.begin()+3, 9);
    cout<<"Size of vec2 after insertion: ";
    show_size(vec2);
    cout<<"vec2 elements after insertion: ";
    show_vector(vec2);

    reverse(vec2.begin(), vec2.end());
    cout<<"vec2 elements after reversion: ";
    show_vector(vec2);

    vector<int> vec3(vec.size() + vec2.size());
    merge(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec3.begin());

    cout<<"Vector #1: ";
    show_vector(vec);

    cout<<"Vector #2: ";
    show_vector(vec2);

    cout<<"Vector #3(merged): ";
    show_vector(vec3);

    return 0;
}

//4 2 7 3 9
