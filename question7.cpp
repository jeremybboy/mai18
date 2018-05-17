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
    int N=10;
    DenseMatrix B(N,N);
    B.Load("matriceB10.txt");
    DenseMatrix E(N,N);
    E.Load("matriceB10.txt");
    //B.Load("matrice_diag.txt");
    fstream g("logb_bktilde.txt");
    //cout<<B<<endl;
    
    /*vector<double> v;
    vector<double> vp;
     
    v.resize(5,1.);
    DenseMatrix C(N,N);
    C=B.difference(1,v,v);
    cout<<C<<endl;
    vp=C.get_col(2);
    Affiche_vector(vp);
    cout<<C.argmax_col(3)<<endl;
    DenseMatrix E=difference(C,C.argmax_col(3),v,v);
    cout<<E;*/
    
   
    DenseMatrix diff(N,N);
    DenseMatrix C(N,N);
    FredholmMatrix D(N);
    cout<<FrobeniusNorm(B)<<endl;
    D.CrossApprox("matriceB100.txt",B,5);
    cout<<D<<endl;
    cout<<FrobeniusNorm(D)<<endl;
    Affiche_vector(D.getSigma());
    D.CrossApprox("matriceB100.txt",B,7);
    cout<<D<<endl;
    
    cout<<FrobeniusNorm(D)<<endl;
    Affiche_vector(D.getSigma());

    /*for (int k=2;k<N;k++){
        
        B.Load("matriceB100.txt");
        FredholmMatrix D(N);

        D.CrossApprox("matriceB100.txt",B,k);
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                C(i,j)=D(i,j);
                
            }
            
        }
        
        
         diff=E-C;
        cout<<FrobeniusNorm(diff)<<endl;
         g<<abs(log(k))<<"\t"<<log(abs(FrobeniusNorm(diff)))<<endl;
         cout<<log(FrobeniusNorm(diff))<<endl;
         }*/
}

