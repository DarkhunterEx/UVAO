#include <bits/stdc++.h>

using namespace std;
vector<int> a;
vector<int>p;
void print_LIS(int i){
    if(p[i]==-1){
        cout<<a[i]<<endl;
        return;
    }
    print_LIS(p[i]);
    cout<<a[i]<<endl;
}

int main(){
    freopen("1.txt","w",stdout);
    freopen("12.txt","r",stdin);
    int x;
    while(cin>>x){
        a.push_back(x);
    }
    p.assign(a.size(),-1);
    int k=0,lis_end=0;
    vector<int>L(a.size(),0),L_id(a.size(),0);
    int pos;
    vector<int>LIS(a.size(),0);
    for(int j=0;j<a.size();j++){
        pos=lower_bound(L.begin(),L.begin()+k,a[j])-L.begin();
        L[pos]=a[j];
        L_id[pos]=j;
        p[j]=pos?L_id[pos-1]:-1;
        if(pos+1>=k){
            k=pos+1;
            lis_end=j;
        }
        LIS[j]=pos+1;
    }
    cout<<k<<endl;
    cout<<"-"<<endl;
    print_LIS(lis_end);
}
