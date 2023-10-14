#include <bits/stdc++.h>
#include <iomanip>

int main(){
    
    /*出力、入力ファイルの場所*/
    std::string input_dir = "";
    std::string output_dir = "../data/";

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
    return 0;

}