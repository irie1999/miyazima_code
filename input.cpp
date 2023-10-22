#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>


void one_input(std::string filename, double *a){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	//double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        a[i] = atof(p);
	}
	
}

void two_input(std::string filename, double *a, double *b){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	//double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        a[i] = atof(p);
		p = strtok(NULL," ");
        b[i] = atof(p);
	}
	
}


void two_input_string(std::string filename, std::string *a, std::string *b){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	//double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        a[i] = p;
		p = strtok(NULL," ");
        b[i] = p;
	}
	
}


void three_input(std::string filename, double *a, double *b, double *c){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	//double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        a[i] = atof(p);
		p = strtok(NULL," ");
        b[i] = atof(p);
        p = strtok(NULL, "\n");
        c[i] = atof(p);
		
	}
}

void special_three_input(std::string filename, double *a, double *b, std::string *c){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	//double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        a[i] = atof(p);
		p = strtok(NULL," ");
        b[i] = atof(p);
        p = strtok(NULL, "\n");
        c[i] = p;
		
	}
}



void Si_tm_input(std::string filename, double **S, int time){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        ggg[i] = atof(p);
        p = strtok(NULL, "\n");
        S[time][i] = atof(p);
		
	}
}

void Ei_tm_input(std::string filename, double *Ei_tm){
	/*ファイル読み込み*/
	std::ifstream ifs;  // ファイル読み取り用ストリーム  
	ifs.open(filename);	// ファイルオープン

	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
		std::cout << filename << " ";
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[801];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える
	char *p;
	double *ggg = new double [900]; /*テスト用*/

	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	for(int i=0 ; i<linenum ; i++){
		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
        p = strtok(buf," ");
        ggg[i] = atof(p);
        p = strtok(NULL, "\n");
        Ei_tm[i] = atof(p);
		
	}
}





// void two_input(std::string *S, Agent *agent, std::string filename){
// 	//void two_input( *S, Agent *agent, std::string filename){
// 	/*ファイル読み込み*/
// 	std::ifstream ifs;  // ファイル読み取り用ストリーム  
// 	ifs.open(filename);	// ファイルオープン

// 	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
// 		std::cerr << "ファイルを開けません\n";
// 		exit(1);
// 	}

// 	char buf[801];	// データ一時保管用配列

// 	int linenum = 0; // データの行数を数える
// 	char *p;
// 	//std::string *a;
// 	//double *ggg = new double [900]; /*テスト用*/

// 	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
// 		linenum++;	// 行数をカウントしている
// 	}

// 	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

// 	ifs.clear(); // ファイル末尾に到達というフラグをクリア
// 	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

// 	for(int i=0 ; i<linenum ; i++){
// 		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
//         p = strtok(buf," ");
//         //S[i] = atof(p);
// 		S[i] = p;
//         //p = strtok(NULL, "\n");
//         //agent[i].score = atof(p);
		
// 	}
	
// }

// void one_input(std::string *S, std::string filename){
// 	//void two_input( *S, Agent *agent, std::string filename){
// 	/*ファイル読み込み*/
// 	std::ifstream ifs;  // ファイル読み取り用ストリーム  
// 	ifs.open(filename);	// ファイルオープン

// 	if(ifs.fail()){	// ファイルオープンに失敗したらそこで終了
// 		std::cerr << "ファイルを開けません\n";
// 		exit(1);
// 	}

// 	char buf[801];	// データ一時保管用配列

// 	int linenum = 0; // データの行数を数える
// 	char *p;
// 	//std::string *a;
// 	double *ggg = new double [900]; /*テスト用*/

// 	while(ifs.getline(buf,sizeof(buf))){	// ファイルから1行ずつ読み込む
// 		linenum++;	// 行数をカウントしている
// 	}

// 	//std::cerr << "読み込んだ行数 = " << linenum << "\n";

// 	ifs.clear(); // ファイル末尾に到達というフラグをクリア
// 	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

// 	for(int i=0 ; i<linenum ; i++){
// 		ifs.getline(buf,sizeof(buf));	// 一行読み込んで…
//         p = strtok(buf," ");
//         //S[i] = atof(p);
// 		S[i] = p;
//         p = strtok(NULL, "\n");
//         ggg[i] = atof(p);
		
// 	}
	
// }
