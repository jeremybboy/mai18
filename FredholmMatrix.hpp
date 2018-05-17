#include <iostream>
#include "SparseMatrix.hpp"
#include "DenseMatrix.hpp"
#include <vector>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_linalg.h>
class FredholmMatrix{
    public:
    
    int size;
    SparseMatrix diag;
    vector<double> sigma;
    vector<vector<double>> lsv;
    vector<vector<double>> rsv;
    
public:
    
    FredholmMatrix(int n0);
    FredholmMatrix(const FredholmMatrix &M);
    FredholmMatrix& operator=(const FredholmMatrix &M);
    
    //Accesseurs
    int getSize();
    SparseMatrix getDiag();
    vector<double> getSigma();
    vector<vector<double>> getLsv();
    vector<vector<double>> getRsv();
    
    //Fonctions Insert
    void Insert(int j,int k,double val);
    void Insert( double s,const vector<double> &u,const vector<double> &v);
    
    //Opérateur d'accès
    double operator()(int j,int k)const;
    
    //Affichage
    friend ostream& operator<<(ostream& os,const FredholmMatrix& M);
    
    //choix de fonction de forme vector<double> car on n'est pas parvenu à le faire avec le void, comme pour solve !!
    //  avec Void, probleme car la valeur du vecteur n'était pas modifiée. 
    friend vector<double> MVProd(const FredholmMatrix& A, const vector<double>& x);
    friend vector<double>  MVProdT(const FredholmMatrix& A, const vector<double>& x);

    friend double FrobeniusNorm(FredholmMatrix m);
  
    void SVD(DenseMatrix& B, const int& r,int N);
    void CrossApprox(const char *filename,DenseMatrix  &R, const int& r);

};

gsl_vector * VectorConverter(const vector<double> & V);
vector<double> VectorConverter(const gsl_vector *v);
gsl_matrix * MatriceConverter(const DenseMatrix &M,int N);
DenseMatrix * MatriceConverter(const gsl_matrix &m,int N);
double norme_B_Bk(DenseMatrix &B,int N,int k);
void Affiche_vector(const vector<double>& V);
void Affiche_vector_gsl(const gsl_vector *v);

vector<double> Solve(vector<double> b, const FredholmMatrix& A);

