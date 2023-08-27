#include<bits/stdc++.h>
using namespace std;

string AND(string a, string b){
    int sz1 = a.length(), sz2 = b.length(), sz;
    if(sz1>sz2){
        reverse(b.begin(), b.end());
        for(int i=1; i<=(sz1-sz2); i++) b += '0';
        reverse(b.begin(), b.end());
    }
    else if(sz1<sz2){
        reverse(a.begin(), a.end());
        for(int i=1; i<=(sz2-sz1); i++) a += '0';
        reverse(a.begin(), a.end());
    }

    sz = max(sz1, sz2);

    string ans = "";

    for(int i=0; i<sz; i++){
        if(a[i]=='1' && b[i]=='1') ans += '1';
        else ans += '0';
    }
    return ans;
}

string NAND(string a, string b){
    int sz1 = a.length(), sz2 = b.length(), sz;
    if(sz1>sz2){
        reverse(b.begin(), b.end());
        for(int i=1; i<=(sz1-sz2); i++) b += '0';
        reverse(b.begin(), b.end());
    }
    else if(sz1<sz2){
        reverse(a.begin(), a.end());
        for(int i=1; i<=(sz2-sz1); i++) a += '0';
        reverse(a.begin(), a.end());
    }

    sz = max(sz1, sz2);

    string ans = "";

    for(int i=0; i<sz; i++){
        if(a[i]=='1' && b[i]=='1') ans += '0';
        else ans += '1';
    }
    return ans;
}

string OR(string a, string b){
    int sz1 = a.length(), sz2 = b.length(), sz;
    if(sz1>sz2){
        reverse(b.begin(), b.end());
        for(int i=1; i<=(sz1-sz2); i++) b += '0';
        reverse(b.begin(), b.end());
    }
    else if(sz1<sz2){
        reverse(a.begin(), a.end());
        for(int i=1; i<=(sz2-sz1); i++) a += '0';
        reverse(a.begin(), a.end());
    }

    sz = max(sz1, sz2);

    string ans = "";

    for(int i=0; i<sz; i++){
        if(a[i]=='0' && b[i]=='0') ans += '0';
        else ans += '1';
    }
    return ans;
}

string NOR(string a, string b){
    int sz1 = a.length(), sz2 = b.length(), sz;
    if(sz1>sz2){
        reverse(b.begin(), b.end());
        for(int i=1; i<=(sz1-sz2); i++) b += '0';
        reverse(b.begin(), b.end());
    }
    else if(sz1<sz2){
        reverse(a.begin(), a.end());
        for(int i=1; i<=(sz2-sz1); i++) a += '0';
        reverse(a.begin(), a.end());
    }

    sz = max(sz1, sz2);

    string ans = "";

    for(int i=0; i<sz; i++){
        if(a[i]=='0' && b[i]=='0') ans += '1';
        else ans += '0';
    }
    return ans;
}

string XOR(string a, string b){
    int sz1 = a.length(), sz2 = b.length(), sz;
    if(sz1>sz2){
        reverse(b.begin(), b.end());
        for(int i=1; i<=(sz1-sz2); i++) b += '0';
        reverse(b.begin(), b.end());
    }
    else if(sz1<sz2){
        reverse(a.begin(), a.end());
        for(int i=1; i<=(sz2-sz1); i++) a += '0';
        reverse(a.begin(), a.end());
    }

    sz = max(sz1, sz2);

    string ans = "";

    for(int i=0; i<sz; i++){
        if(a[i]==b[i]) ans += '0';
        else ans += '1';
    }
    return ans;
}

string XNOR(string a, string b){
    int sz1 = a.length(), sz2 = b.length(), sz;
    if(sz1>sz2){
        reverse(b.begin(), b.end());
        for(int i=1; i<=(sz1-sz2); i++) b += '0';
        reverse(b.begin(), b.end());
    }
    else if(sz1<sz2){
        reverse(a.begin(), a.end());
        for(int i=1; i<=(sz2-sz1); i++) a += '0';
        reverse(a.begin(), a.end());
    }

    sz = max(sz1, sz2);

    string ans = "";

    for(int i=0; i<sz; i++){
        if(a[i]==b[i]) ans += '1';
        else ans += '0';
    }
    return ans;
}

int main()
{
    string a, b, op;
    int n; cin>>n;
    for(int t=1; t<=(2*n)-1; t++){
        if(t&1){
            if(t==1) cin>>a;
            else{
                cin>>b;
                if(op=="AND") a = AND(a, b);
                else if(op=="NAND") a = NAND(a, b);
                else if(op=="OR") a = OR(a, b);
                else if(op=="NOR") a = NOR(a, b);
                else if(op=="XOR") a = XOR(a, b);
                else if(op=="XNOR") a = XNOR(a, b);
            }
        }
        else cin>>op;
    }
    cout<<a<<endl;
}
