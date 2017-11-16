#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n,t,e;
    char s[50];
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        printf("Case %d:\n",i);
        deque<int>dq;
        for(j=1;j<=m;j++){
            scanf("%s",s);
            if(strcmp(s,"pushLeft")==0){
                    scanf("%d",&e);
                    if(dq.size()==n)
                        printf("The queue is full\n");
                    else{

                         dq.push_back(e);
                         printf("Pushed in left: %d\n",e);
                    }
            }
            else if(strcmp(s,"pushRight")==0){
                   scanf("%d",&e);
                   if(dq.size()==n)
                        printf("The queue is full\n");
                    else{

                         dq.push_front(e);
                         printf("Pushed in right: %d\n",e);
                    }
            }
            else if(strcmp(s,"popLeft")==0){
                if(!dq.empty()){
                    printf("Popped from left: %d\n",dq.back());
                    dq.pop_back();
                }
                else
                    printf("The queue is empty\n");
            }
            else if(strcmp(s,"popRight")==0){
                if(!dq.empty()){
                    printf("Popped from right: %d\n",dq.front());
                    dq.pop_front();
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }
return 0;
}
