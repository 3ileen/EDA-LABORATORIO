// created by eileen

#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

//generar numeros aleatorios:
float num_rand(){
    return ((float) rand()/RAND_MAX);
}

// crear puntos de 0 a 1 de  n-dimensiones
template<int D>
struct Point{

    float* coordenadas;
    int dim=D;


    Point(){
        coordenadas = new float[dim];
        for (int i = 0; i < dim; ++i) {
            coordenadas[i] = num_rand();
//            cout<<coordenadas[i]<<endl;
        }

    }
    void print(){
        cout<<endl;
        for (int i = 0; i < dim; ++i) {
            cout<<coordenadas[i]<<",";
        }
        cout<<endl;
    }
};


 //heuristic euclidian distance
 template<int D>
 float heuristic(Point<D> A,Point<D> B) {
     float res=0;
     for(int i=0;i<A.dim;i++){
         res+=pow(A.coordenadas[i]-B.coordenadas[i],2);
     }
     res=sqrt(res);
//     cout<<"\nrespeusta:"<<res;
     return res;
}

int main()
{

    srand( (unsigned)time( NULL ) );

    int n=100;
    const int dim=1000000;

    Point<dim> puntos[n];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
//            cout<<"["<<i<<"-"<<j<<"]\t"<<heuristic(puntos[i],puntos[j])<<endl;
            cout<<heuristic(puntos[i],puntos[j])<<",";
        }
    }
    return 0;

}