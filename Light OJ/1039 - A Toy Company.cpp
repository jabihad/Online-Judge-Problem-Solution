#include<bits/stdc++.h>
using namespace std;

string st, fn;
map<string,int> dis;
int bfs()
{
    char a, b, c;
    string v, w;
    dis[st] = 0;
    queue<string> q;
    q.push(st);
    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(int i=0;i<3;i++){
            a = u[i]+1;
            b = u[i]-1;
            if(a>'z')
                a = 'a';
            if(b<'a')
                b = 'z';
            v = w = u;
            v[i] = a;
            w[i] = b;
            if(dis[v]==0){
                q.push(v);
                dis[v] = dis[u] + 1;
            }
            if(dis[w]==0){
                q.push(w);
                dis[w] = dis[u] + 1;
            }
            if(v==fn || w==fn)
                return dis[fn];
        }
    }
    return -1;
}

int main()
{
    int i, j, k, l, m, n, t, res;
    string c1, c2, c3;

    cin>>t;
    for(i=1;i<=t;i++){

        dis.clear();
        cin>>st>>fn>>n;

        for(j=1;j<=n;j++){

            cin>>c1>>c2>>c3;

            for(k=0;c1[k];k++){
                for(l=0;c2[l];l++){
                    for(m=0;c3[m];m++){
                        string s;
                        s  = c1[k];
                        s += c2[l];
                        s += c3[m];
                        dis[s] = -1;
                    }
                }
            }

        }

        if(st==fn && dis[st]!=-1 && dis[fn]!=-1)
            res = 0;
        else if(dis[st]==-1 || dis[fn]==-1)
            res = - 1;
        else
            res = bfs();

        cout<<"Case "<<i<<": "<<res<<endl;

    }

    return 0;
}
