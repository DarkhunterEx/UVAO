#include <bits/stdc++.h>

using namespace std;
vector<int>ps;

int main(){
    //freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    int t=0;
    while(z--){
        t++;
        int pr[62505];
        for(int i=0;i<62505;i++){
            pr[i]=-1;
        }
        ps.clear();
        int a,b,c;
        cin>>a>>b>>c;
        b++;
        c++;
        for(int i=0;i<b;i++){
            int k;
            cin>>k;
            pr[k]=i;
        }
        for(int i=0;i<c;i++){
            int k;
            cin>>k;
            if(pr[k]!=-1){
                ps.push_back(pr[k]);
            }
        }
        int k=0,lis_end=0;
        vector<int>L(ps.size(),0),L_id(ps.size(),0);
        vector<int>p;
        p.assign(ps.size(),-1);
        for(int i=0;i<ps.size();i++){
            int pos=lower_bound(L.begin(),L.begin()+k,ps[i])-L.begin();
            L[pos]=ps[i];
            L_id[pos]=i;
            p[i]=pos?L_id[pos-1]:-1;
            if(pos==k){
                k=pos+1;
                lis_end=i;
            }
        }
        cout<<"Case "<<t<<": "<<k<<endl;
    }
}
