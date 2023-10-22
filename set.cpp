#include <cmath>
#include "main.h"

    //double *NU = new double [Nx];
    //double *Ez = new double [Nx + 1];
    //double *Hy = new double [Nx];
    //double *ez = new double [Nx + 1];
    //double *ez_old =  new double [Nx + 1];
    //double *Jez= new double [Nx];
    //double *sigma_x = new double[Nx];
    //double *sigma_xh = new double[Nx];

void cal_sigma(double *sigma_x,double *sigma_xh){
    for(int i = 1 ; i < Nx; i++){
        if(i < L){
        sigma_x[i] = sigma_max * std::pow( double( L - i ) * Dx / d ,M);
        }
        else if( i > int(Nx - L) ){
        sigma_x[i] = sigma_max * std::pow( double( i - Nx + L) * Dx / d,M);   
        }
        else{
        sigma_x[i] = 0.0;
        }
    }
    
    for(int i = 1 ; i < Nx; i++){
        if(i < int(L)){
        sigma_xh[i] = sigma_max * std::pow( double( L - i  - 0.5) * Dx / d ,M);
        }
        else if( i >= int(Nx - L) ){
        sigma_xh[i] = sigma_max * std::pow( double( i + 0.5 - Nx + L) * Dx / d,M);                              
        }
        else{
        sigma_xh[i] = 0.0;
        }
    }
}