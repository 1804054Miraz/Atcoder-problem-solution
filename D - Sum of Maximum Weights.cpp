//Bismillahir Rahmanir Rahim
//Allahumma Rabbi Jhidni Elma
///A lot of mistakes is happened without understanding questions clearly.\
Please,make sure that understand question clearly.Think from every possible output.\
Make different algorithm to answer the question.Don't think that you have tried all possible ways.\
There is always simple and tricky way to solve the brute force type question.
/*--------Please carefully check--------
    1.Overflow and underflow
    2.Corner test case
    3. divide zero

*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
typedef long double ld;
const ld PI = 2*acosl(0.0);
const int inf=2e9+7;
const int mxN=3000000;
const int mod=998244353;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define reset(a) memset(a,0,sizeof a)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define abs(a) (a<0?-(a):a)
#define debug1(x)  cout << #x << "=" << x << endl
#define debug2(x, y)  cout << #x << "=" << x << "," << #y << "=" << y << endl
#define digit2(x) floor((log2(x)))
#define digit2(x) floor((log2(x)))
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d\n",a)
#define DEBUG 0
//cout<<"Case "<<cas<<": "<<
ll parent[100001],sz[100001];
int disjoint(int x)
{
    if(parent[x]==x)
        return x;
    else
        return parent[x]=disjoint(parent[x]);
}
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
    vector<array<ll,3LL>>edges(n);
    for(i=1;i<n;i++)
    {
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
    }
    sort(edges.begin(),edges.end());
    ll ans=0;
    for(i=1;i<n;i++)
    {
        int x=disjoint(edges[i][1]),y=disjoint(edges[i][2]);
       //  cout<<x<<" "<<y<<" "<<edges[i][0]<<" "<<sz[x]<<" "<<sz[y]<<endl;
        ans += (sz[x]*sz[y]*1LL)*edges[i][0]*1LL;

        if(sz[x]>sz[y])
        {
            parent[y]=x;
            sz[x]+=sz[y];
        }
        else
        {
            parent[x]=y;
            sz[y]+=sz[x];
        }
    }
    cout<<ans<<endl;

}

