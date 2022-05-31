#include <bits/stdc++.h>

using namespace std;
int z;
bool b[10][10];
int a[10][10];
int ff(int i,int j,int l,int m){
	if(i+1<z-l and b[i+1][j]!=true){
		if(i+1==l or j==z-l-1 or j==l or i+1==z-l-1){
		b[i+1][j]=true;
		return ff(i+1,j,l,m+a[i+1][j]);}
	}
	if(j+1<z-l and b[i][j+1]!=true){
		if(i==l or j+1==z-l-1 or j+1==l or i==z-l-1){
		b[i][j+1]=true;
		return ff(i,j+1,l,m+a[i][j+1]);}
	}
	if(i-1>=0+l and b[i-1][j]!=true){
		if(i-1==l or j==z-l-1 or j==l or i-1==z-l-1){
		b[i-1][j]=true;
		return ff(i-1,j,l,m+a[i-1][j]);}
	}
	if(j-1>=0+l and b[i][j-1]!=true){
		if(i==l or j-1==z-l-1 or j-1==l or i==z-l-1){
		b[i][j-1]=true;
		return ff(i,j-1,l,m+a[i][j-1]);}
	}
	return m;
}

int main(){
	freopen("12.txt","w",stdout);
	cin>>z;
	int i=1;
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
		cout<<"Case "<<i<<": ";
		if(z%2!=0){
			b[0][0]=true;
			cout<<ff(0,0,0,a[0][0]);
			for(int i=1;i<=z/2;i++){
			b[i][i]=true;
			cout<<" "<<ff(i,i,i,a[i][i]);}
		}
		else{
			b[0][0]=true;
			cout<<ff(0,0,0,a[0][0]);
			for(int i=1;i<z/2;i++){
			b[i][i]=true;
			cout<<" "<<ff(i,i,i,a[i][i]);}
		}
		cout<<endl;
		i++;
		cin>>z;
	}
}
