// Particle_swarm.cpp : 粒子群算法实现过程。
#ifndef PCH_H
#define PCH_H
#include<stdio.h>
#include <iostream>
# include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include<random>
#include<ctime>
#define c1_particle   2  //c1学习因子1，自我认知
#define c2_particle   1.2 //c2学习因子2，社会认知
#define w_max  0.9 //最大惯性权重因子，影响着全局搜索
#define w_min  0.6 //最小惯性权重因子，局部深度搜索能力
#define M_particle   1000//最大迭代次数，
#define D_particle    2      //搜索空间的维数也叫变量个数
#define N_particle    60 //初始化群体的个体，N很小容易陷入局部优化,N很大优化能力很好，优化的寻优精度和运行时间
//定义粒子的各种性质
using namespace std;
class particle
{
public:
	vector <double>x_i;     //变量值
	vector<double>v_i;      //N个粒子的速度
	vector<double>y_i;    //存储更新的粒子
};
//产生随机小数或整数
class RandomNumber {
public:
	RandomNumber() {
		srand((unsigned)time(NULL));    
	}
	int integer(int begin, int end)
	{
		return rand() % (end - begin + 1) + begin;
	}
	double decimal(double a, double b)
	{
		return double(rand() % 10000) / 10000 * (b - a) + a;
	}
};
class pso
{
public:
	vector<double>p_best;   //个体最优
	double g_best;          //全局最优
	double w_particle;      //权重更新
	vector<double>x_best;   //储存每代最优变量
	vector<double>x_low = { -10,-10 };   //储存变量上限值
	vector<double>x_high = { 10,10 };   //储存变量下限值
	double r1, r2;                  //r1、r2为增加随机搜索性
	void Initialize_vel_position(particle *elementswarm, pso *PSO);//给定初始化粒子群速度和位置 
	void Initialize_fit_extremum(particle *elementswarm, pso *PSO,int c);	//计算粒子群适应度，初始化个体极值和全局极值
	
};
double fit_function(vector<double> x,int a); //目标函数
#endif