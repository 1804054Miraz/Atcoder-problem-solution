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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
typedef long double ld;
const ld PI = 2*acosl(0.0);
const int inf=2e5+7;
const int mxN=3000000;
const int mod=1e9+7;
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
 int ar[200001],p[200001];
int find_par(int u)
{
    //cout<<u<<endl;
    if(p[u]==u)
    {
        return u;
    }
    else
    return find_par(p[u]);


}
int main()
{
    speed;
    int n,i,j,cn=0;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
        p[ar[i]]=ar[i];
    }
    int x,y;
    for(i=1,j=n+1-i;i<=j;i++,j--)
    {
        if(p[ar[i]]!=p[ar[j]]){
        x=find_par(p[ar[i]]);
        y=find_par(p[ar[j]]);

        if(x!=y)
        {
            //cout<<ar[i]<<" "<<x<<" "<<ar[j]<<" "<<y<<endl;
            cn++;
            p[y]=x;
        }
        }
    }
    cout<<cn<<endl;
}

