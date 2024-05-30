#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 100005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e9
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

struct Point{
    int x,y;
    void read(){ cin >> x >> y; }
    Point operator + (const Point& b) const { return Point{x+b.x,y+b.y}; }
    Point operator - (const Point& b) const { return Point{x-b.x,y-b.y}; }
    int operator *(const Point& b) const { return (int) x*b.y - (int) y*b.x; }
    bool operator < (const Point& b) const { return x==b.x?y<b.y:x<b.x; }
    void operator += (const Point& b) { x+=b.x; y+=b.y; }
    void operator -= (const Point& b) { x-=b.x; y-=b.y; }
    void operator *= (const int k) { x*=k; y*=k; }

    int cross(const Point& b, const Point& c) const { return (b - *this)*(c-*this); }
};

int n,s;
Point p[NMAX];
vector<Point>hull;

int32_t main(){ faster
    map<pii,int>mp;
    cin >> n;
    for(int i=0;i<n;i++){
        p[i].read();
        mp[{p[i].x,p[i].y}] = i;
    } 
    sort(p,p+n);
    for(int t=0;t<2;t++){
        for(int i=0;i<n;i++){
            while( (int) hull.size()-s>=2 ){
                Point p1 = hull[hull.size()-2];
                Point p2 = hull[hull.size()-1];
                if(p1.cross(p2,p[i])<=0) break;
                hull.pop_back();
            }
            hull.push_back(p[i]);
        }
        hull.pop_back();
        s = hull.size();
        reverse(p,p+n);
    }
    set<int>ans;
    for(auto it:hull){
        if(mp.count({it.x,it.y})) ans.insert(mp[{it.x,it.y}]);
    }
    for(auto it:ans) cout << it+1    << " ";
    cout << '\n';
}