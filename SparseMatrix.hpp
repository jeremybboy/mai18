#ifndef SparseMatrix_hpp
#define SparseMatrix_hpp
#include <iostream>
#include <vector>
using namespace std;
class SparseMatrix{
    
private:
    
    int n;
    vector<int> row;
    vector<int> col;
    vector<double> val;
    
public:
    SparseMatrix();
    SparseMatrix( int N);
    SparseMatrix(int N,const vector<int> &R,const vector<int> &C,const vector<double> &V);
    SparseMatrix(const SparseMatrix &M);
    friend ostream& operator <<(ostream& f, const SparseMatrix & M );
    int size();

    double operator () ( int i, int j) const;
    //double & operator () ( int i, int j);

    int getcol(int i);
    int getrow(int i);
    double getval(int i);
    vector<double>  MVProd(const vector<double> &V)const;
    void Insert(int j, int k, double val);
    double FrobeniusNorm();
};

#endif /*SparseMatrix_hpp*/


