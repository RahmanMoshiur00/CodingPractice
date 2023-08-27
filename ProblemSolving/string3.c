#include<stdio.h>
int string_compare(char a[], char b[])
{
int i, j;
for(i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
if(a[i] < b[i]) {
return -1;
}
if(a[i] > b[i]) {
return 1;
}
else if(a[i] < b[i]){
    return -1;
}
else if(a[i] = b[i]){
    return 0;
}
}
/*if(string_length(a) == string_length(b)) {
return 0;
}
if(string_length(a) < string_length(b)) {
return -1;
}
if(string_length(a) > string_length(b)) {
return 1;
}*/
}
int main()
{
    char c[100], d[100];
    gets(c);
    gets(d);
    int value = string_compare(c, d);
    printf("if 1st big (1),if 2nd big (-1),equal (0)\n%d", value);
}
