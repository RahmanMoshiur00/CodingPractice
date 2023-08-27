
int main()
{
    char ch[1001];
    scanf("%s", ch);

    if(ch[0]>='a' && ch[0]<='z') ch[0] = ch[0] - ('a' - 'A');
    printf("%s\n", ch);

}
