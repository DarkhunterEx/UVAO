#include <bits/stdc++.h>

using namespace std;
vector<int>b[25];
map<int,char>tabela;
map<int,char>::iterator it;
map<char,int>rtabela;
map<char,int>::iterator rit;
map<char,int>::iterator rit1;
set<string>resposta;
set<string>::iterator ita;
void p(vector<int>r,string s,int in,vector<bool>v){
    if(in==r.size()){
        resposta.insert(s);
        return;
    }
    queue<int>a;
    for(int i=0;i<r.size();i++){
        if(r[i]==0 and !v[i]){
            string ss=s;
            it=tabela.find(i);
            ss=ss+it->second;
            v[i]=true;
            for(int j=0;j<b[i].size();j++){
                r[b[i][j]]--;
            }
            p(r,ss,in+1,v);
            v[i]=false;
            for(int j=0;j<b[i].size();j++){
                r[b[i][j]]++;
            }
        }
    }
}

int main(){
    freopen("12.txt","r",stdin);
    freopen("1.txt","w",stdout);
    string w;
    int atual=0;
    while(getline(cin,w)){
        if(atual==1)
        cout<<endl;
        atual=1;
        for(int i=0;i<25;i++){
            b[i].clear();
        }
        tabela.clear();
        rtabela.clear();
        resposta.clear();
        for(int i=0;i<w.size();i++){
            if(w[i]!=' '){
                tabela.insert(make_pair(tabela.size(),w[i]));
                rtabela.insert(make_pair(w[i],rtabela.size()));
                //cout<<rtabela.size()-1<<" "<<w[i]<<endl;
            }
        }
        vector<int>r;
        vector<bool>v;
        for(int i=0;i<tabela.size();i++){
            r.push_back(0);
            v.push_back(false);
        }
        string g;
        getline(cin,g);
        int t=0;
        char pri;
        char se;
        for(int i=0;i<g.size();i++){
            if(g[i]!=' '){
                t++;
                if(t==2){
                    t=0;
                    se=g[i];
                    rit=rtabela.find(pri);
                    rit1=rtabela.find(se);
                    //cout<<rit->second<<" "<<rit1->second<<endl;
                    b[rit->second].push_back(rit1->second);
                    r[rit1->second]++;
                }
                else{
                    pri=g[i];
                }
            }
        }
        p(r,"",0,v);
        for(ita=resposta.begin();ita!=resposta.end();ita++)
            cout<<*ita<<endl;
    }
}
