#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include "DenseMatrix.hpp"
#include "SparseMatrix.hpp"
#include "FredholmMatrix.hpp"
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_linalg.h>
#include <fstream>
using namespace std;
int main(){
    int N=100;
    fstream f("matriceB100.txt");
    fstream g("logb_bk100.txt");
    /*f<<"#TAILLE"<<endl;
    f<<N<<" "<<N<<endl;
    f<<"#DONNEES"<<endl;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            f<<exp(-(i-j)*(i-j)/N*N)<<" ";
        }
    }*/
    DenseMatrix B(N,N);
    B.Load("matriceB100.txt");
    cout<<B<<endl;
    
    
    DenseMatrix diff(N,N);
    DenseMatrix C(N,N);
    FredholmMatrix D(N);
    
    for (int k=1;k<N;k++){
        B.Load("matriceB100.txt");

    D.SVD(B,k,N);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            C(i,j)=D(i,j);
            
        }
        
    }
      /* cout<<C<<endl;
        cout<<B<<endl;
        cout<<diff<<endl;
     */
    
    diff=B-C;
    
    g<<abs(log(k))<<"\t"<<log(abs(FrobeniusNorm(diff)))<<endl;
    //cout<<log(FrobeniusNorm(diff))<<endl;
    }
    
}

