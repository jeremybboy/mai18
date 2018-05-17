#ifndef DenseMatrix_hpp
#define DenseMatrix_hpp
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;
class DenseMatrix{
    
private:
    
    int nc,nr;
    vector<double> Values;
    
public:
    DenseMatrix();
    DenseMatrix(const int &Nr,const int &Nc);
    
    DenseMatrix(const DenseMatrix & M);
    friend ostream& operator <<(ostream& f, const DenseMatrix & M );
    int getSize()const ;
    int getSize();

    vector<double> getValues();
    double & operator () (int i, int j);
    double operator () ( int i, int j) const;
    DenseMatrix &operator=(const DenseMatrix &M);
    DenseMatrix operator+(const DenseMatrix &M);
    DenseMatrix operator-(const DenseMatrix &M);
    DenseMatrix operator*(const double &a)const;
    void Load(const char *filename);
    friend double FrobeniusNorm(DenseMatrix & m);
    DenseMatrix MatriceB(int N);
    
    void difference(double s,vector<double> u,vector<double> v);
    int argmax_col(int k);
    int argmax_row(int j);
    vector<double> get_col(int k);
    vector<double> get_row(int i);
   
    
};
#endif /*DenseMatrix_hpp*/
double norme_2(const vector<double> &v);
vector<double> mult(double alpha,const vector<double> &v);

vector<double> difference(const vector<double> &v1,const vector<double> &v2);
DenseMatrix difference(const DenseMatrix & M,double s,vector<double> u,vector<double> v);

