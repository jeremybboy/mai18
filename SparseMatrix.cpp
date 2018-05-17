#include <iostream>
#include "SparseMatrix.hpp"
#include "DenseMatrix.hpp"
#include <vector>
#include<math.h>

using namespace std;
//constructeur par défaut
SparseMatrix::SparseMatrix(){
    n=0;
    row.resize(0,0.);
    col.resize(0,0.);
    val.resize(0,0.);

}
//constructeur matrice identité taille N
SparseMatrix::SparseMatrix( int N){
    n=N;
    val.resize(n,1);
    for (int i=0;i<n;i++){
        row.push_back(i);
        col.push_back(i);
    }
    row.push_back(n);
    
}
//constructeur
SparseMatrix::SparseMatrix(int N,const vector<int> &R,const vector<int> &C,const vector<double> &V){
    n=N;
        row=R;
        col=C;
        val=V;
    }
    

//constructeur par recopie
SparseMatrix::SparseMatrix(const SparseMatrix &M){
    n=M.n;
    for (int i=0;i<n;i++){
        row[i]=M.row[i];
        col[i]=M.col[i];
        val[i]=M.val[i];
    }
    
}
//un accesseur à l’élément (i, j) utilisant operator()
// const donc ne permet pas de la modififier

double SparseMatrix::operator () ( int i, int j) const{
    for(int k=row[i];k<row[i+1];k++){
        if (j==col[k]){return val[j];
        }
        
    }
    return 0;
}

//une méthode d’affichage
ostream& operator <<(ostream& f, const SparseMatrix & M ){
    DenseMatrix P(M.n,M.n);
  
    for (int i=0;i<M.row.size()-1;i++){
        for (int k=M.row[i];k<M.row[i+1];k++){
            P(i,M.col[k])=M.val[k];
        }
        
    }
    f<<P;
    return f;
}
//une méthode qui renvoie la taille de la matrice
int SparseMatrix::size(){
    return n;
}

//des accesseurs pour accéder à l’élément i des tableaux val, col et row
int SparseMatrix::getcol(int i){
    return col[i];
}
int SparseMatrix::getrow(int i){
    return row[i];
}
double SparseMatrix::getval(int i){
    return val[i];
}

vector<double> SparseMatrix::MVProd(const vector<double> &V)const{
    vector<double> R;
    R.resize(n,0.);
    for (int i=0;i<n;i++){
        //première boucle sur les lignes, puis 2e sur les colonnes cf TP3
        for(int k=row[i];k<row[i+1];k++){
            int j=col[k];
            R[i]=R[i]+val[k]*V[j];
            
        }
}
    return R;
}

void SparseMatrix::Insert(int j, int k,double valeur){
    SparseMatrix m=*this;
    if(m(j,k) ==0)
    {
        val.insert ( val.begin() +row[k] ,valeur );

        for (int i=j+2; i<row.size();i++){
            row[i]++;
        }
        
        col.insert ( col.begin() + row[j] , k );
    }
    else
    {   for(int l=row[j];l<row[j+1];l++){
        if (k==col[l]){ val[k]=valeur;
        }
        
    }
        
    }
   
        
    
}
// Retourne la norme de Frobenius
double SparseMatrix::FrobeniusNorm(){
    double norme=0;
    for (int i=0;i<val.size();i++){
        norme=norme+val[i]*val[i];
    }
    return sqrt(norme);
}


