#include <iostream>
using namespace std;
int a[50]; //vetor a ser ordenado

void merge(int,int,int);

//funcao recursiva que divide o vetor
void merge_sort(int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2; //encontra a metade da lista
		merge_sort(low,mid); //ordena do inicio ate o meio
		merge_sort(mid+1,high); //ordena a segunda metade
		merge(low,mid,high);
	}
}

//funcao que ordena o vetor
void merge(int low,int mid,int high){
	int h,i,j,b[50],k;
	h=low;
	i=low;
	j=mid+1;
	
	while((h<=mid)&&(j<=high)){
		if(a[h]<=a[j]){
			b[i]=a[h];
			h++;
		}
		else{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid){
		for(k=j;k<=high;k++){
			b[i]=a[k];
			i++;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}
	for(k=low;k<=high;k++) a[k]=b[k];
}
int main(){
	int num,i;
	
	cout<<"********************************************************************************"<<endl;
	cout<<"                             PROGRAMA MERGE SORT"<<endl;
	cout<<"********************************************************************************"<<endl;
	cout<<endl<<endl;
	cout<<"INFORME A QUANTIDADE DE ELEMENTOS QUE DESEJA ORDENAR: "<<endl;
	cin>>num;
	cout<<endl;
	cout<<"AGORA, INFORME OS ( "<< num <<" ) NUMEROS (ELEMENTOS):"<<endl;
	for(i=1;i<=num;i++){
		cin>>a[i] ;
	}
	merge_sort(1,num); //passando o primeiro elemento e o ultimo do vetor
	cout<<endl;
	cout<<"A LISTA ORDENADA (USANDO MERGE SORT) SERA :"<<endl;
	cout<<endl<<endl;
	
	for(i=1;i<=num;i++)
	cout<<a[i]<<"	";
	
	cout<<endl<<endl<<endl<<endl;
	return 0;
}
