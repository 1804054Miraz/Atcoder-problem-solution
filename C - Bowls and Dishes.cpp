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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
typedef long double ld;
const ld PI = 2*acosl(0.0);
const int inf=2e5+7;
const int mxN=3000000;
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
int main()
{
    int n,k,m,a,b,c,d;
    cin>>n>>m;
    vector<pair<int,int>>vec1,vec;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        vec1.pb(make_pair(a,b));
    }

    cin>>k;
     bool mark[101];
     reset(mark);
    int ar[101];

    for(int i=0;i<k;i++)
    {
        cin>>c>>d;
        vec.pb(make_pair(c,d));
        ar[c]++;
        ar[d]++;
        mark[c]=1, mark[d]=1;
    }

    int dish=0;
    for(int i=0;i<=100;i++)
    {
        if(mark[i])
        {
            dish++;
        }
    }

   // reset(mark);
   cout<<k<<" "<<dish<<endl;
   if(k>=dish)
    {
        for(int i=0;i<vec.size();i++)
        {
            mark[vec[i].first]=1;
            mark[vec[i].second]=1;
        }
    }
    else{
    for(int i=0;i<vec.size();i++)
    {
        if(mark[vec[i].first]==0 and mark[vec[i].second]==0)
        {
            if(ar[vec[i].first] > ar[vec[i].second])
            {
                mark[vec[i].first]=1;
            }
            else
                mark[vec[i].second]=1;
        }
        else if(mark[vec[i].first]==0 )
        {
            mark[vec[i].first]=1;
        }
        else if(mark[vec[i].second]==0)
        {
            mark[vec[i].second]=1;
        }
    }
    }
    //cout<<k<<" "<<dish<<endl;

    int cn=0;
    for(int i=0;i<vec1.size();i++)
    {

        if(mark[vec1[i].first]and mark[vec1[i].second])
        {
            cout<<vec1[i].first<<" "<<vec1[i].second<<endl;
            cn++;
        }
    }
    cout<<cn<<endl;

}

