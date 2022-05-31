#include <bits/stdc++.h>

using namespace std;
int z;
bool b[10][10];
int a[10][10];
int ff(int i,int j,int l,int m){
	cout<<i<<" "<<j<<" "<<l<<" "<<m<<endl;
	if(i+1<z-l and b[i+1][j]!=true){
		b[i+1][j]=true;
		return ff(i+1,j,l,m+a[i+1][j]);
	}
	if(j+1<z-l and b[i][j+1]!=true){
		b[i][j+1]=true;
		return ff(i,j+1,l,m+a[i][j+1]);
	}
	if(i-1>=0+l and b[i-1][j]!=true){
		b[i-1][j]=true;
		return ff(i-1,j,l,m+a[i-1][j]);
	}
	if(j-1>=0+l and a[i][j-1]!=true){
		a[i][j-1]=true;
		return ff(i,j-1,l,m+a[i][j-1]);
	}
	return l;
}

int main(){
	//freopen("12.txt","w",stdout);
	cin>>z;
	while(z!=0){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				b[i][j]=true;
			}
		}
		for(int i=0;i<z;i++){
			for(int j=0;j<z;j++){
				cin>>a[i][j];
				b[i][j]=false;
			}
		}
		for(int i=0;i<z/2;i++){
			b[i][i]=true;
			cout<<ff(i,i,i,a[i][i])<<endl;
		}
		cin>>z;
	}
}
