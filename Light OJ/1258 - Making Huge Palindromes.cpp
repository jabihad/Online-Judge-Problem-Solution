#include<bits/stdc++.h>
using namespace std;

int f[1000100];
char pattern[1000100], text[1000100];
void kmp_preprocess()
{
    f[0] = 0;
    int i, j = 0;
    for(i=1; pattern[i]; i++){
        if(pattern[i] == pattern[j]){
            f[i] = j + 1;
            j++;
        }
        else{
            while(j!=0){
                j = f[j-1];
                if(pattern[i]==pattern[j]){
                    f[i] = j + 1;
                    j++;
                    break;
                }
            }
        }
    }
}
int kmp()
{
    int n, m, i, j=0;
    n = strlen(text);
    m = strlen(pattern);
    for(i=0; i<n; i++){
        if(text[i]==pattern[j]){
            if(j==m-1){
                j = f[j];
                return m;
            }
            else
                j++;
        }
        else{
            while(j!=0){
                j = f[j-1];
                if(text[i]==pattern[j]){
                    j++;
                    break;
                }
            }
        }
    }
    return j;
}
int main()
{
    int i, j, k, t, match, l;

    scanf("%d", &t);
    for(i=1;i<=t;i++){

        scanf("%s", text);
        l = strlen(text);
        match = 0;
        reverse_copy(text, text+l, pattern);
        memset(f, 0, sizeof f);
        kmp_preprocess();
        match = kmp();
        printf("Case %d: %d\n", i, 2*l-match);
    }
    return 0;
}

