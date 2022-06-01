#include <bits/stdc++.h>

using namespace std;

#define Mid (l + ((r - l) >> 1))

vector<int>ci;
vector<int>primo;
bool a[1000035];
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
int nu[60];
int bb1(int in,int fim,int z){
    int meio=(in+fim)/2;
    if(in>=fim){
        return meio-1;
    }
    if(nu[meio]==z){
        return meio;
    }
    if(nu[meio]<z){
        return bb1(meio+1,fim,z);
    }
    if(nu[meio]>z){
        return bb1(in,meio,z);
    }
}

int main(){
    freopen("1.txt","w",stdout);
    freopen("12.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f=0;
    a[0]=true;
    a[1]=true;
    for(int i=2;i<=1000000;i++){
        if(a[i]==false){
            for(int j=i+i;j<=1000000;j=j+i){
                a[j]=true;
            }
            primo.push_back(i);
        }
    }
    int con=0;
    for(int i=0;i<primo.size();i++){
        int j=primo[i];
        int k=j;
        int l=0;
        while(k>0){
            k=k/10;
            l=l+1;
        }
        k=j;
        bool m=true;
        for(int v=l-1;v>=0 and m==true;v--){
            if(primo[bb(0,primo.size(),k)]!=k){
            m=false;
            }
            int h=1;
            for(int i=0;i<l-1;i++){
                h=h*10;
            }
            k=(k%h)*10+(k/h);
        }
        if(m==true){
            nu[con]=j;
            con++;
        }
    }
    int z,w;
    cin>>z;
    while(z!=-1){
        cin>>w;
        int t=bb1(0,55,z);
        int v=bb1(0,55,w);
        cout<<nu[t]<<" "<<nu[v]<<" "<<t<<" "<<v<<endl;
        if(nu[t]==z)
            v=v+1;
        if(v-t>1)
        cout<<v-t<<" Circular Primes."<<endl;
        else if(v-t==1)
            cout<<"1 Circular Prime."<<endl;
        else
        cout<<"No Circular Primes."<<endl;
        cin>>z;
    }
}
