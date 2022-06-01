#include <bits/stdc++.h>

using namespace std;
vector<int>primo;
#define Mid (l + ((r - l) >> 1))
typedef int no;

no Seg[4*78499];
int Vet[78499], n=78499;

no Modify(no a, no b){
    return a + b;
}

no build(int l = 0, int r = n - 1, int id = 1){
    if (l == r)
        return Seg[id] = Vet[l];
    return Seg[id] = Modify(build(l, Mid, 2 * id), build(Mid + 1, r, 2 * id + 1));
}

no query(int i, int j, int l = 0, int r = n - 1, int id = 1){
    if (i > r || j < l) return 0;
    if (i <= l && j >= r) return Seg[id];
    return Modify(query(i, j, l, Mid, 2 * id), query(i, j, Mid + 1, r, 2 * id + 1));
}

void upd(int i, int x, int l = 0, int r = n - 1, int id = 1){
    if (l > r) return;
    if (l == r){ Seg[id] = x; return; }
    if (i <= Mid) upd(i, x, l, Mid, 2 * id);
    else upd(i, x, Mid + 1, r, 2 * id + 1);
    Seg[id] = Modify(Seg[2 * id], Seg[2 * id + 1]);
}

bool a[1000000];
int bb(int in,int fim,int z){
    int meio=(in+fim)/2;
    if(in>=fim){
        if(primo[meio]<z)
        return meio;
        else{
        return meio-1;}
    }
    if(primo[meio]==z){
        return meio;
    }
    if(primo[meio]<z){
        return bb(meio+1,fim,z);
    }
    if(primo[meio]>z){
        return bb(in,meio,z);
    }
}

int main(){
    freopen("1.txt","w",stdout);
    freopen("12.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f=0;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=1000000;i++){
        if(a[i]==false){
            for(int j=i+i;j<=1000000;j=j+i){
                a[j]=true;
            }
            primo.push_back(i);
            int m=i;
            int n=0;
            while(m>0){
                n=n+m%10;
                m=m/10;
            }
            if(a[n]==false)
            Vet[f]=1;
            else{
            Vet[f]=0;
            }
            f++;
        }
    }
    build();
    Vet[f]=0;
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        int w,x;
        cin>>w>>x;
        int k=bb(0,primo.size()-1,w);
        int l=bb(0,primo.size()-1,x);
        if(w!=primo[k])
        k++;
        cout<<query(k,l)<<endl;
    }
}
