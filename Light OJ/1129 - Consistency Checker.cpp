#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[10];
    node()
    {
        endmark=false;
        for(int i=0;i<10;i++) next[i]=NULL;
    }
}*root;

void insert(char *str)
{
    node *curr=root;
    for(int i=0;str[i];i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=true;

}
bool search(char *str)
{
    int id;
    node *curr=root;
    for(int i=0;str[i];i++)
    {
        id=str[i]-'0';
        if(curr->endmark==true)
            return false;

        curr=curr->next[id];
    }
    return true;
}
void del(node *cur)
{
      for(int i=0;i<10;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;

         delete(cur) ;
}
int main()
{
    int i, j, k, l, m, n, t, c;

    char s[10010][11];
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        root=new node();
        c = 0;
        scanf("%d", &n);
        for(j=1;j<=n;j++){
            scanf("%s", s[j]);
            insert(s[j]);
        }
        for(j=1;j<=n;j++){
            if(search(s[j])==false){
                 printf("Case %d: NO\n", i);
                 c = 1;
                 break;
            }
        }
        if(c==0)
            printf("Case %d: YES\n", i);
        del(root);
    }


    return 0;
}
