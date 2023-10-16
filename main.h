#include <bits/stdc++.h>

/*電子密度を求める刻み幅 65km, 65.5km, 66.0km ...*/
double step = 0.5;
int end_point = 600;

double Dt0 = Dx_0 / C0;//Dx_0 = 500
double sigma = 7 * Dt0;
double t0 = 4 * sigma;

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