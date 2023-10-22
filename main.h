#ifndef _H_main_
#define _H_main_

#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>
constexpr double MU0 {4.0 * M_PI * 1.0e-7};
constexpr double C0  {3.0 * 1.0e+8};
constexpr double EPS {1 / (C0 * C0 * MU0)};
constexpr double Ne_max {1.0e+12};
constexpr double m {9.109*1.0e-31};
constexpr double Q {-1.602*1.0e-19};
constexpr double Omega {std::sqrt(Q*Q*Ne_max/m/EPS)};

constexpr double Dx {250.0};
constexpr double Dx_0 {500.0};
constexpr double Rx {6.0e+5};
constexpr int Nt {30000};
constexpr int Nx {int(Rx / Dx_0)};
constexpr int L {8};
constexpr double d {L * Dx};

/*電子密度を求める刻み幅 65km, 65.5km, 66.0km ...*/
constexpr double step {0.5};
constexpr int end_point {600};

constexpr double Dt0 {Dx_0 / C0};//Dx_0 = 500
constexpr double sigma {7 * Dt0};
constexpr double t0 {4 * sigma};

constexpr double xi {1  / std::sqrt(1 + Omega * Omega * Dx * Dx  / 4  / C0 / C0)};
constexpr double Dt {Dx / C0 * xi  * 0.9999};
constexpr double R {1.0e-6};
constexpr double M {3.5};
constexpr double sigma_max {- (M + 1) * C0 * std::log( R ) / (2 * L * Dx)};
constexpr int Nx_src {int(50e+3 / Dx)};//波源
constexpr int Nx_plz {int(65e+3 / Dx)};//プラズマ領域の左端
constexpr int x_obs {int(70e+3 / Dx)};//観測点[km]



void cal_Ne(std::string output_dir, double *Ne);
void cal_NU(double *NU);
void cal_Hy(double *Hy,double *sigma_xh,double *Ez);
void cal_Ez(double *ez_old, double *ez, double *Jez, double *Ez, double *sigma_x, double *Hy, double Jz,double *NU);
void cal_Jz(double *Jez,double *NU,double *Ez,double *Omega);
void cal_sigma(double *a,double *b);
void two_input(std::string filename, double *a, double *b);


#endif