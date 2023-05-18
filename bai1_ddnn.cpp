#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

#define max 100
struct Graph{
	int n;
	int a[max][max];
};

void Input(Graph &G){
	ifstream fi("C:\\Users\\Admin\\Documents\\dai_hoc\\namhai\\CTDL&GTNC_cau_truc_du_lieu_va_giai_thuat_nang_cao\\de_on_tap\\bai1.txt");
	if(fi.is_open()){
		fi>>G.n;
		for(int i=0 ; i<G.n ; i++){
			for(int j=0 ; j<G.n ; j++){
				fi >> G.a[i][j];
			}
		}
		fi.close();
	}
}

void Output(Graph G){
	cout << "So dinh n:" << G.n << endl;
	cout << "Ma tran ke:" << endl;
	for(int i=0 ; i<G.n ; i++){
		for(int j=0; j<G.n ; j++){
			cout << G.a[i][j] << "  ";
		}
		cout << endl;
	}
}

void ddnn(Graph G,int start, int goal){
	int d[max], truoc[max];
	int close[max] = {0};
	for(int v = 0 ; v<G.n ; v++){
		d[v] = G.a[start][v];
		truoc[v] = start;
	}
	d[start] = 0;
	close[start] = 1;
	for(int k=0 ; k<G.n-2 ; k++){
		int d_min= 100;
		int u;
		for(int v=0 ; v<G.n ; v++){
			if(close[v] == 0 && d[v] < d_min){
				u = v;
				d_min = d[v];
			}
		}
		close[u] = 1;
		for(int v=0 ; v<G.n ; v++){
			if(close[v] == 0 && d[v] > d[u] + G.a[u][v]){
				d[v] = d[u] + G.a[u][v];
				truoc[v] = u;
			}
		}
	}
	if(d[goal] == 100){
		cout << "Khong tim thay duong di!";
	}
	else{
		cout << "Do dai duong di:" << d[goal] << endl;
		int u = goal;
		while(u != start){
			cout << u << "<--";
			u = truoc[u];
		}
		cout << start;
	}
}

int main(){
	Graph G;
	Input(G);
	cout<< "Mang vua nhap la:" << endl;
	Output(G);
	int start,goal;
	do{
		cout << "Nhap dinh start:";
		cin >> start;
	}while(start < 0 || start >= G.n);
	do{
		cout << "Nhap dinh goal:";
		cin >> goal;
	}while(goal < 0 || goal >= G.n);
	ddnn(G,start,goal);
}
