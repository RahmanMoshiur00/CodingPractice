//LightOJ 1048

    //int lo = 0, hi = sum, mid, ans = -1;
    while(lo < hi){
        mid = (hi+lo) / 2;
        if(f(mid)) ans = hi = mid;
        else lo = mid + 1;
    }
    //if(ans != -1) cout<<"Valid Answer = "<< ans <<endl;



///==============================================================================///
//LightOJ 1076

    //int lo = 0, hi = sum, mid;
    rep(i, 0, 35){
        mid = (lo+hi) / 2;
        if(f(mid)) hi = mid;
        else lo = mid + 1;
    }
    //cout<<"Answer = "<<hi<<endl;



///==============================================================================///
//LightOJ  1076
    //int lo = 0, hi = sum, mid;
    while(hi - lo > 1){ //it's safe to stop binary search when (1 <= hi-lo <=5)
        mid = (lo+hi) / 2;
        if(f(mid)) hi = mid;
        else lo = mid + 1;
    }

    rep(i, lo, hi+1){ //finding required answer
        if(f(i)){
            cout<<"Answer = "<<i<<endl; // required valid answer
            break;
        }
    }
    //check if answer is not found



///==============================================================================///
//SPOJ Aggressive Cows
    //int lo = 0, hi = a[n-1] - a[0], mid;
    while(lo<hi){
        mid = (hi+lo+1)/2;
        if(f(mid)) lo = mid; //if number of cows for x is greater than or equal to c, then we have to increase the lower bound. because X is inversly propotional to C and we are finding maximum X
        else hi = mid-1; //as cows for x is less then c, reducing the higher bound
    }
    //cout<<"Answer: "<<lo+1<<endl;



///==============================================================================///
