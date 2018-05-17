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
    int N=5;
    FredholmMatrix A(N);
    vector<double> u={1,1,1,1,1};
    vector<double> v={1,2,3,4,5};
    int sigma=1;
    A.Insert(sigma,u,v);
    
    cout<<endl;
    A.Insert(sigma,u,v);
    
    A.Insert(sigma,v,v);
    A.Insert(3,v,u);
    
    
    cout<<"Ma matrice A"<<endl;
    cout<<A<<endl;
    cout<<"Sa norme de Frobenius"<<endl;
    cout<<FrobeniusNorm(A)<<endl;
    cout<<endl;

    cout<<"Ma matrice B"<<endl;

    DenseMatrix B(N,N);
    B.Load("matrice.txt");
    cout<<B<<endl;
    cout<<"Sa norme de Frobenius"<<endl;

    cout<<FrobeniusNorm(B)<<endl;
    
}

