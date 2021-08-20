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
string st[501];
int grid[501][501];


void dfs(int h,int w)
{
    grid[0][0]=0;
    deque<pair<int,int>>deq;
    deq.push_back({0,0});
    int cell_dis,x,y,levelup;

    while(!deq.empty())
    {
        pair<int,int>temp;
        temp=deq.front();
        deq.pop_front();

        x = temp.first, y=temp.second; //root cell
       // cout<<"level ("<<x<<","<<y<<") = "<<grid[x][y]<<endl;
        for(int i=max(0,x-2);i<=min(x+2,h);i++) //iterate every cell up and down belonging to 2x2 blocks which is adjacent to cell(x,y)
        {
            for(int j=max(0,y-2);j<=min(y+2,w);j++)//iterate every cell left-right belonging to 2x2 blocks which is adjacent to cell(x,y)
            {
                cell_dis = abs(x-i)+abs(y-j);
                if(cell_dis>3) //we will skip the cell(i,j) which is not belongs to 2x2 blocks that adjacent to root cell(x,y)
                    continue;
                levelup=0;
                if(st[i][j]=='#' || cell_dis>1)
                {
                    levelup=1; //levelup will be 1,if any obstacle found to in cell(i,j) from cell(x,y) or if (i,j) not adjacent to (x,y)
                }
                if(grid[i][j]>grid[x][y]+levelup)//Check level of between cell(i,j) and  cell(x,y)
                {
                    grid[i][j]=grid[x][y]+levelup; //child-level will be root-level+1
                    if(levelup)
                    deq.push_back({i,j});//here, cell(i,j) is less priority as level grow up from root
                    else
                    deq.push_front({i,j});//here, cell(i,j) is greater priority as level equal to root
                }
               // cout<<"\tchild level ("<<i<<","<<j<<") = "<<grid[i][j]<<endl;

            }
        }
    }
}
int main()
{
    speed;
    int h,w,n,i,j;
    cin>>h>>w;
    for(i=0;i<h;i++)
    {
        cin>>st[i];//2D string input
        for(j=0;j<w;j++)
        {
            grid[i][j]=inf; //assign inf value at first in grid matrix
        }
    }
    dfs(h,w);
    cout<<grid[h-1][w-1]<<endl;
    return 0;
}

