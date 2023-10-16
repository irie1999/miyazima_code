#include <bits/stdc++.h>
#include "main.h"


void cal_sigma(/*ここは頑張ってください*/){
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
    return 0;
}