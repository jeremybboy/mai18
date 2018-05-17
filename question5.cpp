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

    
    
    DenseMatrix B(N,N);
    //on teste simplement avec une matrice diagonale car on connait bien sa svd
    /*
    fstream f("matrice_diag&.txt");
    
    f<<"#TAILLE"<<endl;
    f<<N<<" "<<N<<endl;
    f<<"#DONNEES"<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                f<<rand()%10<<" ";}
                else {
                    f<<0<<" ";
                }
            }
        }
    */
    B.Load("matrice_diag.txt");
    cout<<"Ma matrice B"<<endl;
    cout<<B<<endl;
    
    FredholmMatrix A(N);

    for (int k=1;k<=N;k++){
        A.SVD(B,k,N);
        cout<<"ma svd au rang k="<<k<<endl;
        cout<<A<<endl;
        cout<<endl;
    }
    
    
    
}
