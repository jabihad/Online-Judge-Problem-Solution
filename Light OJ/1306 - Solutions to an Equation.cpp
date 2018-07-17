/* https://brilliant.org/wiki/linear-diophantine-equations-one-equation/

* Concept: This kind of problem can be solved by Extended Euclidean Algorithm.
           If an equation of straight line is given like Ax + By = C, then
           extended euclidean algorithm can find a solution of it using
           diophantine equation. From this concept, all the solution in a
           certain range can also be counted and be found.
           Let  ax1 + by1 = c
                ax1 + a*b*T/g - a*b*T/g + by1 = c, where g = GCD get using EGCD
                a (x1 + b*T/g) + b (y1 + a*T/g) = c
           Comparing this equation with the previous, we get,
                x = x1+(b*T/g)
                y = y1-(a*T/g)
            Now, x>= min_x
                x1+(b*T/g) >= min_x
                (b*T/g) >= min_x - x1
                T >= (min_x-x1)* g/b
            On the other hand, y >= min_y
                y1-(a*T/g) >= min_y
                y1 - min_y >= (a*T/g)
                T <= (y1-min_y)* g/a
            Combining these two, we get
                (min_x-x1)* g/b <= T <= (y1-min_y)* g/a
            Again, x<= max_x
                x1+(b*T/g) <= max_x
                (b*T/g) <= max_x - x1
                T <= (max_x-x1)* g/b
            On the other hand, y <= max_y
                y1-(a*T/g) <= max_y
                y1 - max_y <= (a*T/g)
                T >= (y1-max_y)* g/a
            Combining these two, we get
                (y1-max_y)* g/a <= T <= (max_x-x1)* g/b
            So, the solution of our problem T would be:
            max((min_x-x1)* g/b,  (y1-max_y)* g/a ) <= T
                                <= min( (y1-min_y)* g/a , (max_x-x1)* g/b)
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll egcd(ll a, ll b, ll &x, ll &y)
{
    if(a==0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd(b%a, a, x1, y1);

    x = y1 - (b/a)*x1;
    y = x1;

    return d;
}
ll count_solution(ll a, ll b, ll c, ll mina, ll maxa, ll minb, ll maxb)
{
    ll x0, y0, x1, y1, a1, b1, p, q, r, s;
    ll g = egcd(a, b, x0, y0);
    if(g>0 && c%g!=0)return 0;
    if(a==0 && b==0){
        if(c==0)
            return (maxa-mina+1)*(maxb-minb+1);
        return 0;
    }
    if(a==0){
        if(c/b>=minb && c/b<=maxb)
            return (maxa-mina+1);
        return 0;
    }
    if(b==0){
        if(c/a>=mina && c/a<=maxa)
            return (maxb-minb+1);
        return 0;
    }
    x1 = (c/g)*x0;
    y1 = (c/g)*y0;
    a1 = (b/g);
    b1 = (a/g);

    p = ceil((mina-x1)*1.0/a1);
    q = ceil((y1-maxb)*1.0/b1);
    r = floor((y1-minb)*1.0/b1);
    s = floor((maxa-x1)*1.0/a1);

    p = max(p, q);
    r = min(r, s);

    return max(r-p+1, 0ll);
}
int main()
{
    ll i, j, k, t, a, b, c, x1, x2, y1, y2, ans, tmp;
    scanf("%lld", &t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);
        c = -c;
        if(a<0){
           a = -a;
           tmp = x1;
           x1 = -x2;
           x2 = -tmp;
        }
        if(b<0){
            b = -b;
            tmp = y1;
            y1 = -y2;
            y2 = -tmp;
        }

        ans = count_solution(a, b, c, x1, x2, y1, y2);
        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
