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
    cout<<A<<endl;
    
    
    // On va tester la fonction Insert et l'affichage (donc en + l'accesseur (i,j)
    
    vector<double> u={1,1,1,1,1};
    vector<double> v={1,2,3,4,5};
    int sigma=1;
    A.Insert(sigma,u,v);
    cout<<A<<endl;
    cout<<endl;
    A.Insert(sigma,u,v);
    cout<<A<<endl;
    A.Insert(sigma,v,v);
    A.Insert(3,v,u);
    cout<<A.sigma.size()<<endl;

    cout<<A.lsv.size()<<endl;
    cout<<A.rsv.size()<<endl;
    
    vector<double> x={1.3,1.6,8.2,9,3.7};
    cout<<"Notre matrice A"<<endl;
    cout<<A<<endl;
    cout<<"Notre vecteur x"<<endl;
    Affiche_vector(x);

    cout<<"Produit Ax:b"<<endl;
    
    vector<double> b=MVProd(A,x);
    Affiche_vector(b);
    
    cout<<"Résolution de Ax=b"<<endl;
    Affiche_vector(Solve(b,A));

}
