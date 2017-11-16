#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,t,x;
    string s,r,cp;
    stack<string>fw,bw;
    scanf("%d",&t);
    for(x=1; x<=t; x++)
    {   bw.push("http://www.lightoj.com/");
        printf("Case %d:\n",x);
        while(1)
        {
            cin>>s;
            if(s[0]=='B')
            {
                fw.push(bw.top());
                bw.pop();
                if(bw.empty()){
                        printf("Ignored\n");
                bw.push(fw.top());
                fw.pop();     }
                else
                {cout<<bw.top()<<endl;}
            }
            else if(s[0]=='F')
            {
                if(fw.empty())printf("Ignored\n");
                else
                {
                    bw.push(fw.top());
                    cout<<fw.top()<<endl;
                    fw.pop();

                }
            }
            else if(s[0]=='V')
            {
                cin>>r;
                cout<<r<<endl;
                bw.push(r);
                while(!fw.empty())fw.pop();
            }


            else if(s[0]=='Q') break;
        }
        while(!fw.empty())fw.pop();
        while(!bw.empty())bw.pop();
    }


    return 0;
}
