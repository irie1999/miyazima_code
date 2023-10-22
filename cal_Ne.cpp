#include <iomanip>
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

void cal_Ne(std::string output_dir, double *Ne){

    double *point_x = new double[4];
    double *point_y = new double[4];
    /*位置　　配列*/
    /*65~100→65~135,100~300→135~535,300~600→535~1135*/
    point_x[0] = 65;
    point_x[1] = 100;
    point_x[2] = 300;
    point_x[3] = end_point;
    /*近似する点y*/
    point_y[0] = 5e5;
    point_y[1] = 1e11;
    point_y[2] = 1e12;
    point_y[3] = 1e11;

    /*近似する電子密度のグラフを求める*/
    std::ostringstream dir; //stepの出力する小数点の桁数を1桁にする, 0.50000→0.5
    dir << std::fixed << std::setprecision(1) << step;
    std::ofstream Ne_data(output_dir + "Ne_" + dir.str() + "km.dat");
    //double *Ne = new double[point_x[3] * step];


    for(int i = 0; i <= 2; i++){ /*3回近似直線を出力*/
    
        /*傾き*/
        double a = (std::log10(point_y[i + 1]) - std::log10(point_y[i])) / (point_x[i + 1] - point_x[i]);
        /*切片*/
        double b = std::log10(point_y[i]) - a * point_x[i];

        for(int j = 0; j <= (point_x[i + 1] - point_x[i]) / step; j++){
            Ne_data << j * step + point_x[i]  << " " << std::pow(10, a * (j * step + point_x[i]) + b) << std::endl;
            //電子密度の配列に注意！　ここでは[65]から値を格納している。[66]はstep[km]分だけ進んだ電子密度が格納されている
            /**********************************************/
            
        }
    }
}