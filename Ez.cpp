#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include "main.h"
#include <iomanip> 

void cal_Ez(double *ez_old,double *ez,double *Jez,double *Ez, double *sigma_x, double *Hy, double Jz,double *NU){
    //位置
    //pml左端
    for(int i = 1; i <= L;i++){
        ez_old[i] = ez[i];
        ez[i] = (1 / Dt - sigma_x[i] / 2) / (1 / Dt + sigma_x[i] / 2 ) * ez[i] 
        + 1 / (1 / Dt + sigma_x[i] / 2)  / EPS / Dx * ( Hy[i] - Hy[i - 1] );
        Ez[i] =Ez[i] + ez[i] - ez_old[i] - Dt / EPS * Jez[i];
    }    
    //pml右端
    for(int i = Nx - L; i < Nx;i++){
        ez_old[i] = ez[i];
        ez[i] = (1 / Dt - sigma_x[i] / 2) / (1 / Dt + sigma_x[i] / 2 ) * ez[i] 
        + 1 / (1 / Dt + sigma_x[i] / 2)  / EPS / Dx * ( Hy[i] - Hy[i - 1] );
        Ez[i] =Ez[i] + ez[i] - ez_old[i] - Dt / EPS * Jez[i];
    }      
    
    for(int i = L + 1;i < Nx - L;i++){
        if(i != Nx_src){
            Ez[i] = Ez[i] + Dt / EPS / Dx * (Hy[i] - Hy[i-1]) - Dt /EPS * Jez[i];
        }else{
            Ez[i] = Ez[i] + Dt / EPS / Dx * (Hy[i] - Hy[i-1]) - Dt / EPS * Jz;
        }      
    }
}

void cal_NU(double *NU){
    for(int i = 0;i<Nx;i++){
            NU[i] = 4.303 * 10e+11 * std::exp(-0.16 * i * Dx / 1000);
    }

}

void cal_Jz(double *Jez,double *NU,double *Ez,double *Omega){
    for(int i = Nx_plz;i < Nx;i++){
        Jez[i] = 2 * Dt / (2 + NU[i] * Dt ) * (1/Dt - NU[i] / 2) * Jez[i] + 2 * Dt / (2 + NU[i] * Dt) * (EPS * Omega[i] * Omega[i] * Ez[i]);
    }
}

void cal_Hy(double *Hy,double *sigma_xh,double *Ez){
    for(int i = 0;i < Nx;i++){
        Hy[i] = (1 / Dt - sigma_xh[i] / 2) / (1 / Dt + sigma_xh[i] / 2 ) * Hy[i] 
        + 1/(1 / Dt + sigma_xh[i] / 2 ) / MU0 / Dx * (Ez[i + 1] - Ez[i]);
    }

}

