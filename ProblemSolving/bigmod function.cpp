

int bigmod(int a, int b, int M){ // 'a' is the number, 'b' is power and 'M' is the modulo number

    if(b == 0) return 1;
    int x = bigmod(a, b/2, M);
    x = (x*x) % M;
    if(b % 2 == 1) x = (x*a) % M;
    return x;

}
