#include "mpi.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>
#define X 80
#define L 10

using namespace std;
int main(int A,char*B[]){  
MPI_Status estado;
int id,p,i,j;
MPI_Init(&A, &B);     
MPI_Comm_size(MPI_COMM_WORLD,&p);  
MPI_Comm_id(MPI_COMM_WORLD,&id);  
int C[X], resp[p],prom[p],sum;
cout<<"id:"<<id<<"de"<<p<< endl;
srand(time(NULL));
for(int i=0;i<X;i++){
C[i]=(rand()/100)%X;	
//cout<<"C["<<i<<"]:"<<C[i]<<endl;
}
sum=0;
for(int j=(id*L);j<(((id+1)*L)-1);j++){
sum=sum+C[j];	
cout<<"C["<<j<<"]:"<<C[j]<<endl;
//cout<<"sum:"<<sum<<endl;
}	  	  
prom[id]=sum/L;	  
MPI_Send(&prom,p ,MPI_INT ,id ,0 ,MPI_COMM_WORLD); 	
MPI_Recv(&resp,p ,MPI_INT ,id ,0 ,MPI_COMM_WORLD ,&estado); 
cout<<"El proceso"<<id<<"y promedio:"<<[id]<<endl; 
MPI_Finalize();
return 0;
}
