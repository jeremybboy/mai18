
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
    
    
    int N;
    vector<int> row;
    vector<int> col;
    vector<double> val;

    N=5;
    row={0,3,5,7,8,10};
    col={0,3,4,2,3,1,2,2,2,3};
    val={3,2,1,5,8,1,2,9,10,4};
    
    Affiche_vector(val);
    //fonction qu'on a volontairement crée pour faciliter
    // cf FredholmMatrix.cpp à la fin
    
    //test de l'affichage
    SparseMatrix A(N,row,col,val);
    cout<<A<<endl;
    
    //test du produit
    vector<double> V={1,1,1,1,1};
    Affiche_vector(A.MVProd(V));
    
   
}

