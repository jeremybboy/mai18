#include <iostream>
#include "SparseMatrix.hpp"
#include "DenseMatrix.hpp"
#include "FredholmMatrix.hpp"
#include <vector>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <math.h>
#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_linalg.h>
#include <stdio.h>
using namespace std;

// En commentaires quelques affichages qui peuvent permettre de mieux comprendre l'algo

void FredholmMatrix::CrossApprox(const char *filename,DenseMatrix  &R, const int& r){
    
    int N=R.getSize();
    DenseMatrix B(N,N);
    B.Load(filename);
    
    int j_=0;
    int k_=0;
    vector<double> up(N);
    vector<double> vp(N);
    
    double sp;
    
    for (int p=1;p<r;p++){
        
        //cout<<"itération numero : "<<p<<endl;
        //cout<<B<<endl;
        j_=B.argmax_col(k_);
        //cout<<"j*:";
        //cout<<j_<<endl;
        k_=B.argmax_row(j_);
        //cout<<"k*:";
        //cout<<k_;

         //cout<<"R(j;k):";
        //cout<<B(j_,k_)<<endl;
        sp=1./B(j_,k_);
        //cout<<k_<<endl;
        up=B.get_col(k_);
        
        //cout<<"up:";
        
        //Affiche_vector(up);
        vp=B.get_row(j_);
        
        //cout<<"vp:";
        
        //Affiche_vector(vp);
       
        
        
        //cout<<"sp="<<sp<<endl;
        Insert(sp,up,vp);
        
        
       
        B.difference(sp,up,vp);
        up.clear();
        vp.clear();
    }
    
}
