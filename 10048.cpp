#include <bits/stdc++.h>
using namespace std;
int b[106];
int acha(int n){
	if(n!=b[n]){
		return acha(b[n]);
	}
	return n;
}
vector<pair<int,int>>v[106];
int ve[106];
void dfs(int a,int f,int t){
	for(int i=0;i<v[a].size();i++){
		if(ve[v[a][i].first]==-1){
			if(t<v[a][i].second){
				t=v[a][i].second;
			}
			if(t<ve[v[a][i].first]){
				t=ve[v[a][i].first];
			}
			ve[v[a][i].first]=t;
			dfs(v[a][i].first,f,t);
		}
	}
}

int main(){
	freopen("12.txt","w",stdout);
	int x,y,z;
	cin>>x>>y>>z;
	int zz=0;
	while(x!=0 or y!=0 or z!=0){
		zz++;
		if(zz>1){
			cout<<endl;
		}
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>>a;
		for(int i=0;i<x+5;i++){
			v[i].clear();
			b[i]=i;
		}
		for(int i=0;i<y;i++){
			int c,d,e;
			cin>>c>>d>>e;
			a.push(make_pair(e,make_pair(c,d)));
		}
		while(!a.empty()){
			int c=acha(a.top().second.first);
			int d=acha(a.top().second.second);
			if(c!=d){
				b[c]=d;
				v[a.top().second.first].push_back(make_pair(a.top().second.second,a.top().first));
				v[a.top().second.second].push_back(make_pair(a.top().second.first,a.top().first));
			}
			a.pop();
		}
		cout<<"Case #"<<zz<<endl;
		for(int j=0;j<z;j++){
			int aa,bb;
			for(int h=0;h<106;h++){
				ve[h]=-1;
			}
			cin>>aa>>bb;
			dfs(aa,bb,-1);
			if(ve[bb]!=-1)
			cout<<ve[bb]<<endl;
			else{
				cout<<"no path"<<endl;
			}
		}
		cin>>x>>y>>z;
	}
}
