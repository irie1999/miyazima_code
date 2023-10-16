
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
std::string output = "realDx_dat/";

#include "main.h"

int main(void){

    std::string output_dir = "../../data/";
    double *Ne = new double[end_point * step];
    cal_Ne(output_dir, Ne);
   
    double *Omega = new double [Nx];
    for(int i = 0; i < Nx;i++){ 
        Omega[i] = std::sqrt(Q * Q * Ne[i] / m / EPS);
    }
    //安定条件
    double xi = 1  / std::sqrt(1 + Omega[600] * Omega[600] * Dx * Dx  / 4  / C0 / C0) ;
    double Dt = Dx / C0 * xi  * 0.9999;


    /**********************************************/
    double *NU = new double [Nx];
    double *Ez = new double [Nx + 1];
    double *Hy = new double [Nx];
    double *ez = new double [Nx + 1];
    double *ez_old =  new double [Nx + 1];
    double *Jez= new double [Nx];
    double *sigma_x = new double[Nx];
    double *sigma_xh = new double[Nx];
    
    /************************************************/
    
    //  double Dt0 = Dx_0 / C0;
    //  double sigma = 7 * Dt0;
    //  double t0 = 4 * sigma;
    

    /******************************************************************************************/
    std::ofstream ofs_exi("60km.dat",std::ios::out);
    //時間

    cal_sigma(sigma_x, sigma_xh);



    for(int n = 1;n <= Nt;n++ ){
        if ( n%10 == 0 ){
        std::cout << n << " / " << Nt << std::endl;
        }
        
        double t = (n - 0.5) * Dt;
        //double Jz = (t - t0) / sigma * std::exp(-(t - t0)*(t - t0)/ 2 / sigma / sigma);

        double Jz = std::exp(-(t - t0)*(t - t0)/ 2 / sigma / sigma);
        
        //Ez.cppに関数化
        /***************/
        cal_NU(NU);
        cal_Jz(Jez);
        cal_Hy(Hy);    
        /***************/
        
        /* for(int i = 0;i < Nx;i++){
        Hy[i] = Hy[i] + Dt/MU0/Dx * (Ez[i + 1] - Ez[i]);
        */
        
        //位置Xでの電場の時間変化
        /*
        std::ofstream ofs_exi("exi.dat",std::ios::app);
        ofs_exi << n << " " <<Ez[X] << std::endl;

        ofs_exi.close();        
        */
        /****************************************************************************************************/
        
        ofs_exi << n * Dt * 1000 << " " <<Ez[X] << std::endl;


        if(n % 100 == 0){
        
            std::ofstream ofs_ez( output + "ez_" + std::to_string(n) + ".dat");
            for(int i = 0; i <= Nx; i++){
            
                //ofs_ez << i * Dx << " " << Jez[i] << std::endl;
                ofs_ez << i * Dx / 1000 << " " << Ez[i] << std::endl;

            }  
            ofs_ez.close();
        }
        
    }
    std::cout << Nx_src << " " << Nx_plz << " " << x_obs << std::endl; 
    ofs_exi.close();          
    return 0;
}




