        
void cal_Ez(){
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
    return 0;
}

void cal_Jz(){
    for(int i = Nx_plz;i < Nx;i++){
        Jez[i] = 2 * Dt / (2 + NU[i] * Dt ) * (1/Dt - NU[i] / 2) * Jez[i] + 2 * Dt / (2 + NU[i] * Dt) * (EPS * Omega[i] * Omega[i] * Ez[i]);
    }
    return 0;
}

void cal_Hy(){
    for(int i = 0;i < Nx;i++){
        Hy[i] = (1 / Dt - sigma_xh[i] / 2) / (1 / Dt + sigma_xh[i] / 2 ) * Hy[i] 
        + 1/(1 / Dt + sigma_xh[i] / 2 ) / MU0 / Dx * (Ez[i + 1] - Ez[i]);
    }
    return 0;
}

void cal_NU(){
    for(int i = 0;i<Nx;i++){
            NU[i] = 4.303 * 10e+11 * std::exp(-0.16 * i * Dx / 1000);
    }
    return 0;
}