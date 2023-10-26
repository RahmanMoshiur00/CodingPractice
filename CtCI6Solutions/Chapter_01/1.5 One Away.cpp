// CtCI 6: 1.5 One Away

#include <bits/stdc++.h>
using namespace std;


bool solve(int tc)
{
    string s, t;
    cin >> s >> t;

    int sizeDiff = s.size() - t.size();

    if(abs(sizeDiff) > 1)
        return false;

    if(s.size() < t.size())
        swap(s, t);

    // s is greater or equal to the size of t

    if(s.size() == t.size()){ // only replace case
        int notEqual = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] != t[i])
                notEqual++;
        }
        return (notEqual <= 1);
    }
    else{ // add to t
        bool isMismatchFound = false;
        for(int i=0, j = 0; i<s.size() && j<t.size(); i++, j++){
            if(s[i] != t[j]){
                if(isMismatchFound)
                    return false;
                else{
                    isMismatchFound = true;
                    j--;
                }
            }
        }
        return true;
    }

}

int main() {
	int tc;
	cin >> tc;

	for(int i=1; i<=tc; i++)
	    cout << solve(i) << endl;

	return 0;
}

