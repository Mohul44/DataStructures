#include<bits/stdc++.h>
using namespace std;
class Segment{
  public:
  int n;
  int t[10001];
  
  void build(){
    for(int i=n-1;i>0;i--){
        t[i] = t[i<<1] + t[i<<1|1];
    }
  }
  
  void update(int ind, int value){
    for(t[ind+n]=value;ind>1;ind>>1){
        t[ind>>1] = t[ind] + t[ind^1]
    }
  }
  
  int query(int l, int r){
      int res = 0;
      for(l+=n,r+=n;l<r;l>>=1,r>>=1){
          if(l&1)res+=t[l++];
          if(r&1)res+=t[--r];
      }
      return res;
  }
    
    
};
int main()
{
    cout<<"Hello World";

    return 0;
}
