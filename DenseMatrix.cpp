// CLASSE DENSEMATRIX: modélise les matrice pleines
#include <iostream>
#include "DenseMatrix.hpp"
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

//CONSTRUCTEURS
DenseMatrix::DenseMatrix(){
    nc=0;
    nr=0;
    Values.resize(0,0.);
    
}
DenseMatrix::DenseMatrix(const int &Nr,const int &Nc){
    nr=Nr;
    nc=Nc;
    Values.resize(Nc*Nr,0.);
}
DenseMatrix::DenseMatrix(const DenseMatrix & M){
    
    for (int i=0;i<M.Values.size();i++){
        Values.push_back(M.Values[i]);
    }
}
//Accesseurs
int DenseMatrix::getSize()const{ return nc;}
int DenseMatrix::getSize(){ return nc;}
vector<double> DenseMatrix::getValues(){ return Values;}

//Affichage
ostream& operator <<(ostream& f, const DenseMatrix & M ){
    for (int i=0;i<M.nr;i++){
        for (int j=0;j<M.nc;j++){
            //f<<M.Values[i+j*M.nc]<<"\t";
            f<<M(i,j)<<"\t";
        }
        f<<endl;
    }
    return f;
}

//Opérateurs d'accès
double & DenseMatrix::operator () (int i, int j){
    return Values[i+j*nr];
}
double DenseMatrix::operator () ( int i, int j) const{
    return Values[i+j*nr];
}

//Opérateurs
DenseMatrix &DenseMatrix::operator=(const DenseMatrix &M){
    for (int i=0;i<M.nr;i++){
        for (int j=0;j<M.nc;j++){
            Values[i+j*M.nc]=M(i,j);
}
    }
    return *this;
}
DenseMatrix DenseMatrix::operator+( const DenseMatrix &M){
    DenseMatrix P(nr,nc);
    
    for(int i=0;i<nr*nc;i++){
        P.Values[i]=Values[i]+M.Values[i];}
    return P;
}
DenseMatrix DenseMatrix::operator-( const DenseMatrix &M){
    DenseMatrix P(nr,nc);
    
    for(int i=0;i<nr*nc;i++){
        P.Values[i]=Values[i]-M.Values[i];}
    return P;
}
DenseMatrix DenseMatrix::operator*( const double &a)const{
    DenseMatrix P(nr,nc);
    
    for(int i=0;i<nr*nc;i++){
        P.Values[i]=a*Values[i];}
    return P;
}

// Constructeur qui construit une matrice avec un fichier.txt
void DenseMatrix::Load(const char *filename){
    
    ifstream f(filename);
    string ligne;
    getline(f,ligne);
    f>>nr;
    f>>nc;
    Values.resize(nr*nc,0.);
    f>>ligne;
    for (int i=0;i<nr*nc;i++){
        f>>Values[i];
        
    }
   
}
//Fonction qui retourne la norme de Frobenius
double FrobeniusNorm(DenseMatrix & m){
    double norme=0;
    for (int i=0;i<m.getValues().size();i++){
        
        norme=norme+m.getValues()[i]*m.getValues()[i];
    }
 return sqrt(norme);
}

DenseMatrix DenseMatrix::MatriceB(int N){
    DenseMatrix B(N,N);
    for (int j=0;j<N;j++){
        for (int k=0;k<N;k++){
            B(j,k)=exp(-(j-k)*(j-k)/N*N);
    }
}
    return B;
}
/*
vector<vector<double>> logB_Bk(int N){
    
    for (int k=0;k<N;k++){
        DenseMatrix Bk(N,N);
        for (int j=0;j<N;j++){
            Bk(j,k)
        }
    }
}
*/


//Fonction membre de la classe DenseMatrix qui retourne une DenseMatrix - le produit de suvT
void DenseMatrix::difference(double s,vector<double> u,vector<double> v){
    for (int i=0;i<nr;i++){
        for (int j=0;j<nc;j++){

        Values[i+j*nr]=Values[i+j*nr]-s*u[i]*v[j];
        }
    }
    
}
//Fonction qui retourne la colonne k
vector<double> DenseMatrix::get_col(int k){
    vector<double> V;
    for (int i=0;i<nr;i++){
        //V[i]=Values[i+k*nr];
        V.push_back(Values[i+k*nr]);
}
    return V;
    
}
//Fonction qui retourne la ligne i
vector<double> DenseMatrix::get_row(int i){
    vector<double> V;

    for (int j=0;j<nc;j++){
        //V[j]=Values[i+j*nr];
        V.push_back(Values[i+j*nr]);
    }
    return V;
    
}

vector<double> difference(const vector<double> &v1,const vector<double> &v2){
    vector<double> V;
    for (int i=0;i<v1.size();i++){
        V.push_back(v1[i]-v2[i]);
        
    }
    return V;
}

double norme_2(const vector<double> &v){
    double norme=0.;
    for (int i=0;i<v.size();i++){
        norme =norme +v[i]*v[i];
}
    return norme;
}

vector<double> mult(double alpha,const vector<double> &v){
    vector<double> V;
    for (int i=0;i<v.size();i++){
        V.push_back(alpha*v[i]);
        
    }
    return V;
}
DenseMatrix difference(const DenseMatrix & M,double s,vector<double> u,vector<double> v){
   
        DenseMatrix R(M.getSize(),M.getSize());
        for (int i=0;i<M.getSize();i++){
            for (int j=0;j<M.getSize();j++){
                
                R(i,j)=M(i,j)-s*u[i]*v[j];
            }
        }
        return R;
    }

int DenseMatrix::argmax_col(int k){
    double max=0.;
    int arg=0;
    
    for (int i=0;i<=nr;i++){
        if(abs(Values[i+k*nr])>=max){
            max=Values[i+k*nr];
            arg=i;
        }
        
    }
    return arg;
}
int DenseMatrix::argmax_row(int j){
    double max=0.;
    int arg=0;
  
    for (int k=0;k<=nr;k++){
        if(abs(Values[j+k*nr])>=max){
            max=Values[j+k*nr];
            arg=k;
        }
        
    }
    return arg;
}
