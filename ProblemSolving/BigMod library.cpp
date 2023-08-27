
/* below two functions works for b<=10^9 and p<=10^18 */
intl bigmod(intl b, intl p){ //finds (b^p)%mod
    intl res = 1LL;
    b = b % mod;  //Update b if it is more than or equal to p
    while(p > 0LL)
    {
        if(p & 1) res = (res*b) % mod; // If p is odd, multiply b with result
        p = p>>1; // p must be even now; then, p = p/2
        b = (b*b) % mod;
    }
    return res;
}
intl modinv(intl n){ //finds (1/n)%mod
    return bigmod(n, mod-2);
}



/*below two functions are used when (b,p)<=10^18 */
intl mul(intl b, intl p){ //finds summation
    b %= mod;
    intl res = 0LL;
    while(p){
        if(p % 2) res = (res + b) % mod;
        b = (b + b) % mod;
        p /= 2LL;
    }
    return res;
}
intl bigmod(intl b, intl p){ //finds (b^p)%mod
    b %= mod;
    intl res = 1LL;
    while(p){
        if(p % 2) result = mul(res, b);
        b = mul(b, b);
        p /= 2;
    }
    return res;
}
