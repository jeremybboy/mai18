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
// Constructeurs

FredholmMatrix::FredholmMatrix(int n0){
   
    size=n0;
    diag=SparseMatrix(n0);
    //sigma.resize(n0);
    //lsv=vector<vector<double>>(n0);
    //rsv=vector<vector<double>>(n0);
    
    
}
FredholmMatrix::FredholmMatrix(const FredholmMatrix &M){
    size=M.size;
    diag=M.diag;
    sigma=M.sigma;
    lsv=M.lsv;
    rsv=M.rsv;
}

/*FredholmMatrix  FredholmMatrix::transpose(const FredholmMatrix &M){
    FredholmMatrix M2(M.getSize());
    
    
    M2.lsv=M.rsv;
    M2.rsv=M.lsv;
    return M2;
    
}*/
FredholmMatrix& FredholmMatrix::operator=(const FredholmMatrix &M){
    FredholmMatrix P(M);
    return P;
}


// Accesseurs
int FredholmMatrix::getSize(){return size;}
SparseMatrix FredholmMatrix::getDiag(){return diag;}
vector<double> FredholmMatrix::getSigma(){return sigma;}
vector<vector<double>> FredholmMatrix::getLsv(){return lsv;}
vector<vector<double>> FredholmMatrix::getRsv(){return rsv;}


// Insérer un élément dans la partie creuse de la décomposition

void FredholmMatrix::Insert(int j,int k,double val){
    diag.Insert(j,k,val);

}

// Insérer un élément dans la partie matrice de rang faible
void FredholmMatrix::Insert( double s,const vector<double> &u,const vector<double> &v){
    
    sigma.push_back(s);
    lsv.push_back(u);
    rsv.push_back(v);
}

// Opérateur d'accès à l'élément (i,j) de la matrice
double FredholmMatrix::operator()(int j,int k)const{
    double sum=0.;
    for (int i=0;i<sigma.size();i++){
        sum=sum+sigma[i]*lsv[i][j]*rsv[i][k];
        
    }
   
    //return  diag(j,k)+sum;
    return sum;

}


// Opérateur d'affichage
ostream& operator<<(ostream& f,const FredholmMatrix& M){
    for (int i=0;i<M.size;i++){
        for (int j=0;j<M.size;j++){
            f<<M(i,j)<<"\t";
        }
        f<<endl;
    }
    return f;
}

// Fonction qui effectue le produit Ax
vector<double> MVProd(const FredholmMatrix& A, const vector<double>& x){
    vector<double> b;
    for (int i = 0;i<x.size();i++){
        b.push_back(0.);
        for (int j = 0;j<x.size();j++){

            //b[i]=b[i]+x[i]*A.sigma[j]*A.lsv[j][i]*A.rsv[j][i];
            b[i]=b[i]+x[i]*A(i,j);
    }
        //b[i]=b[i]+A.diag.MVProd1(x)[i];
    }
    return b;
    

}
// Fonction qui effectue le produit Atx
vector<double>  MVProdT(const FredholmMatrix& A, const vector<double>& x){
    vector<double> b;
   

    for (int j = 0;j<x.size();j++){
        b.push_back(0.);
        for (int i = 0;i<x.size();i++){
            
            //b[j]=b[j]+x[i]*A.sigma[i]*A.lsv[i][j]*A.rsv[i][j];
            b[j]=b[j]+x[j]*A(j,i);
        }
        //b[j]=b[j]+A.diag.MVProd1(x)[j];
    }
    return b;

    
    
    
}
// Fonction qui retourne la norme de Frobenius de la matrice
double FrobeniusNorm(FredholmMatrix m){
    double norme=0.;
    for (int i=0;i<m.getSize();i++){
        for (int j=0;j<m.getSize();j++){

        norme=norme+m(i,j)*m(i,j);
        }
    }
    return sqrt(norme);
}


// Passer de gsl à vector et réciproquement
gsl_vector * VectorConverter(const vector<double> & V){
    gsl_vector * v = gsl_vector_alloc (V.size());
    
    for (int i = 0; i < V.size(); i++)
    {
        gsl_vector_set (v, i, V[i]);
    }
    return v;
}
vector<double> VectorConverter(const gsl_vector *v){
    vector<double> V;
    for (int i = 0; i <v->size ; i++)
    {
        V.push_back(gsl_vector_get(v, i));
    }
    return V;
}

gsl_matrix * MatriceConverter(const DenseMatrix &M,int N){
    gsl_matrix * m= gsl_matrix_alloc(N,N);
    for (int i = 0; i <N ; i++)
    {
        for (int j = 0; j <N ; j++)
        {
            gsl_matrix_set (m, i, j, M(i,j));
}
    }
    return m;
}
DenseMatrix MatriceConverter(const gsl_matrix *m,int N){
    DenseMatrix M(N,N);
    for (int i = 0; i <N ; i++)
    {
        for (int j = 0; j <N ; j++)
        {
            M(i,j)=gsl_matrix_get (m, i, j);
        }
    }
    return M;
}

//Fonction qui effectue la SVD sur la matrice B et qui stock les vecteurs singuliers et les valeurs singulières dans une matrice de Fredholm de matrice de contribution nulle
void FredholmMatrix::SVD(DenseMatrix& B, const int& r,int N){
    
    // les éléments gsl qui vont intervenir dans la SVD
    gsl_matrix * b=MatriceConverter(B,N);
    gsl_matrix * V=gsl_matrix_alloc(N,N);
    gsl_vector * S=gsl_vector_alloc(N);
    gsl_vector * work=gsl_vector_alloc(N);
    
    
    //SVD
    gsl_linalg_SV_decomp(b, V, S, work);
    //Après ça on a la svd ou b correspond à U donc les vecteurs lsv , S aux sigmas, V aux rsv
    // NB: work est un workspace donc on ne l'utilise pas
    gsl_vector * u=gsl_vector_alloc(N);
    gsl_vector * v=gsl_vector_alloc(N);
    vector<double> R(N,0.);
    double s;
    
    //On clear les vecteurs de notre matrice de Fredholm au cas où
    sigma.clear();
    lsv.clear();
    rsv.clear();
    
    for (int i=0;i<r;i++){
        gsl_matrix_get_col(u,b,i);
        
        gsl_matrix_get_col(v,V,i);
        
        s=gsl_vector_get(S,i);
        
        
        /////////////////////UTILE POUR LES TESTS///////////////////////////
        //cout<<"valeur singuliere numero"<<i<<endl;                     ///
        //cout<<s<<endl;                                                 ///
        //cout<<endl;                                                    ///
        //Affiche_vector(VectorConverter(u));                            ///
        //cout<<endl;                                                    ///
        //Affiche_vector(VectorConverter(v));                            ///
        /////////////////////////////////////////////////////////////////////
        
        
        Insert(s,VectorConverter(u),VectorConverter(v));
        u=gsl_vector_alloc(N);
        v=gsl_vector_alloc(N);
    }
   
    
    diag=SparseMatrix(N);
    
    
}


vector<double> Solve(vector<double> b, const FredholmMatrix& A){
    vector<double> pk;
    vector<double> x;
    x.resize(b.size(),0.);
    vector<double> vk;

    vector<double> c;
    vector<double> av;
    double alphak;
    for (int i=0;i<100;i++){
        
        c=MVProd(A,x);
        pk=difference(c,b);
        vk=MVProdT(A,pk);
        av=MVProd(A,vk);
        alphak=norme_2(vk)/norme_2(av);
        x=difference(x,mult(alphak,vk));
}
    return x;
}
//Afficher un vector
void Affiche_vector(const vector<double>& V){
    
    
    for (int i=0;i<V.size();i++){
        
        cout<<V[i]<<endl;
    }
    cout<<endl;
    
    
}

void Affiche_vector_gsl(const gsl_vector *v){
    
    
    
    for (int i = 0; i <v->size ; i++){
        
        cout <<gsl_vector_get(v, i)<<endl;
    }
    cout<<endl;
    
}
