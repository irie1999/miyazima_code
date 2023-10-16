//
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
std::string output = "realDx_dat/";


int main(void){

//ヘッダーファイルに書く ~.h
/****************************************************************************************/
    double MU0 = 4.0 * M_PI * 1.0e-7;
    double C0 = 3.0 * 1.0e+8;
    double EPS = 1 / (C0 * C0 * MU0);
    //double Ne = 1.0e+7;
    double m = 9.109*1.0e-31;
    double Q = -1.602*1.0e-19;
    //double Omega = std::sqrt(Q*Q*Ne/m/EPS);

    double Dx = 250.0;
    double Dx_0 = 500.0;
    double Rx = 6.0e+5;
    int Nt =3e+4;
    int Nx = Rx / Dx_0;
    int L = 8;
    double d =  L * Dx;
    //double NU = 0.0;
    //double xi = 1  / std::sqrt(1 + Omega * Omega * Dx * Dx  / 4  / C0 / C0) ;
    //double Dt = Dx / C0 * xi  * 0.9999;
    double R = 1.0e-6;
    double M = 3.5;
    double sigma_max = - (M + 1) * C0 * std::log( R ) / (2 * L * Dx);
    int Nx_src = 50e+3 / Dx;//波源
    int Nx_plz = 65e+3 / Dx;//プラズマ領域の左端
    int x_obs = 70e+3 / Dx;//観測点[km]
    /*****************************************************************************************/

    //ここも関数にする
    /******************************************************************************/
    /*近似する点x 単位はkm*/
    double *point_x = new double[4];
    point_x[0] = 65;
    point_x[1] = 100;
    point_x[2] = 300;
    point_x[3] = 600;
    /*近似する点y*/
    double *point_y = new double[4];
    point_y[0] = 5e5;
    point_y[1] = 1e11;
    point_y[2] = 1e12;
    point_y[3] = 1e11;

    /*電子密度を求める刻み幅 65km, 65.5km, 66.0km ...*/
    double step = 0.5;
    
    /*近似する電子密度のグラフを求める*/
    std::ostringstream dir; //stepの出力する小数点の桁数を1桁にする, 0.50000→0.5
    dir << std::fixed << std::setprecision(1) << step;
    std::ofstream Ne(output_dir + "Ne_" + dir.str() + "km.dat");

    for(int i = 0; i <= 2; i++){ /*3回近似直線を出力*/
    
        /*傾き*/
        double a = (std::log10(point_y[i + 1]) - std::log10(point_y[i])) / (point_x[i + 1] - point_x[i]);
        /*切片*/
        double b = std::log10(point_y[i]) - a * point_x[i];

        for(int j = 0; j <= (point_x[i + 1] - point_x[i]) / step; j++){
            Ne << j * step + point_x[i]  << " " << std::pow(10, a * (j * step + point_x[i]) + b) << std::endl;
        }
    }
    /**************************************************************************************************************/


   
    /************************************************************************************/
    double *Omega = new double [Nx];
    for(int i = 0;i < Nx;i++){ //0にするだけのコードは書かなくて良し
        Omega[i] = 0.0;
    }

    for(int i = 0; i < Nx;i++){ 
        Omega[i] = std::sqrt(Q * Q * Ne[i] / m / EPS);
    }

    //安定条件
    double xi = 1  / std::sqrt(1 + Omega[600] * Omega[600] * Dx * Dx  / 4  / C0 / C0) ;
    double Dt = Dx / C0 * xi  * 0.9999;

    //0にするだけのコードは書かなくてよし
    /***********************************************************************/
    double *NU = new double [Nx];
    for(int i = 0;i < Nx;i++){
        NU[i] = 0.0;
    }
    double *Ez = new double [Nx + 1];
    for(int i = 0;i < Nx + 1;i++){
        Ez[i] = 0.0;
    }
    double *Hy = new double [Nx];
    for(int i = 0;i < Nx;i++){
        Hy[i] = 0.0;
    }

    double *ez = new double [Nx + 1];
    for(int i = 0; i < Nx + 1;i++){
        ez[i] = 0.0;
    }

    double *ez_old =  new double [Nx + 1];
    for(int i = 0; i < Nx + 1;i++){
        ez_old[i] = 0.0;
    }
    
    double *Jez= new double [Nx];
    for(int i = 0;i < Nx;i++){
        Jez[i]= 0.0;
    }
    
    double *sigma_x = new double[Nx];
    for(int i = 0; i < Nx ; i++){
        sigma_x[i] = 0.0;
    }
    
    double *sigma_xh = new double[Nx];
    for(int i = 0; i < Nx ; i++){
        sigma_xh[i] = 0.0;
    }
    /***************************************************************************************************************/
    
    //  double Dt0 = Dx_0 / C0;
    //  double sigma = 7 * Dt0;
    //  double t0 = 4 * sigma;
    
    //こことかは関数にしちゃった方が良い
    /**********************************************************************************/
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
    /******************************************************************************************/
    std::ofstream ofs_exi("60km.dat",std::ios::out);
    //時間

    //ヘッダーファイルに書く
    /***********************************/
    double Dt0 = Dx_0 / C0;//Dx_0 = 500
    double sigma = 7 * Dt0;
    double t0 = 4 * sigma;
    /**************************************/

    for(int n = 1;n <= Nt;n++ ){
        if ( n%10 == 0 ){
        std::cout << n << " / " << Nt << std::endl;
        }
        
        double t = (n - 0.5) * Dt;
        //double Jz = (t - t0) / sigma * std::exp(-(t - t0)*(t - t0)/ 2 / sigma / sigma);

        //電流に関する関数、ezに関する関数、Hyに関する関数を違うファイル名で保存して、呼び出す形にする
        /*************************************************************************/
        double Jz = std::exp(-(t - t0)*(t - t0)/ 2 / sigma / sigma);
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

        for(int i = 0;i<Nx;i++){
        NU[i] =4.303 * 10e+11 * std::exp(-0.16 * i * Dx / 1000);
        }
        
        //プラズマ
        for(int i = Nx_plz;i < Nx;i++){
        Jez[i] = 2 * Dt / (2 + NU[i] * Dt ) * (1/Dt - NU[i] / 2) * Jez[i] + 2 * Dt / (2 + NU[i] * Dt) * (EPS * Omega[i] * Omega[i] * Ez[i]);
        }

        for(int i = 0;i < Nx;i++){
        Hy[i] = (1 / Dt - sigma_xh[i] / 2) / (1 / Dt + sigma_xh[i] / 2 ) * Hy[i] 
        + 1/(1 / Dt + sigma_xh[i] / 2 ) / MU0 / Dx * (Ez[i + 1] - Ez[i]);
        }
        
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




