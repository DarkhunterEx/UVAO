#include <bits/stdc++.h>

using namespace std;
vector<int>num;
vector<int>S;
vector<vector<string>>a;
vector<vector<string>>a_t;
vector<vector<string>>r;
map<string,int>t;
map<string,int>::iterator it;
map<string,int>::iterator it1;
void Kojaru(int u,int pass,int p){
    num[u]=1;
    vector<string>n=(pass==1)?a[u]:a_t[u];
    for(int i=0;i<n.size();i++){
        it=t.find(n[i]);
        if(num[it->second]==-1){
            if(p!=-1){
                cout<<", "<<it->first;
            }
            Kojaru(it->second,pass,p);
        }
    }
    S.push_back(u);
}

int main(){
    S.clear();
    int z,w;
    cin>>z>>w;
    int y=0;
    while(z!=0 or w!=0){
        if(y>0)
        cout<<endl;
        y++;
        t.clear();
        S.clear();
        a.assign(z,vector<string>());
        a_t.assign(z,vector<string>());
        r.assign(z,vector<string>());
        string R[z];
        for(int i=0;i<w;i++){
            string A,B;
            cin>>A>>B;
            it=t.find(A);
            it1=t.find(B);
            if(it==t.end()){
                //cout<<A<<" "<<t.size()<<endl;
                R[t.size()]=A;
                t.insert(make_pair(A,t.size()));
                it=t.find(A);
            }
            if(it1==t.end()){
                R[t.size()]=B;
                //cout<<B<<" "<<t.size()<<endl;
                t.insert(make_pair(B,t.size()));
                it1=t.find(B);
            }
            a[it->second].push_back(it1->first);
            a_t[it1->second].push_back(it->first);
        }
        num.assign(z,-1);
        for(int i=0;i<z;i++){
            if(num[i]==-1)
                Kojaru(i,1,-1);
        }
        int SCC=0;
        num.assign(z,-1);
        cout<<"Calling circles for data set "<<y<<":"<<endl;
        for(int i=z-1;i>=0;i--){
            if(num[S[i]]==-1){
                cout<<R[S[i]];
                Kojaru(S[i],2,SCC++);
                if(R[S[i]]!="")
                cout<<endl;
            }
        }
        for(int i=0;i<z;i++){
            r[i].clear();
            a_t[i].clear();
            a[i].clear();
        }
        cin>>z>>w;
    }
}
