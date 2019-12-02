#include "pch.h"
#include <iostream>
RandomNumber r;       //随机数
int main()
{
	int i, j;
	clock_t startTime, endTime; //定义程序开始运行时间和结束时间
	startTime = clock();  //计时开始

	cout << "开始！，请输入要测试的函数：1、Sphere 2、SchwdfelP22 3、Rosenbrock 4、Griewanks （退出请按 0）" << endl;
	int option;
	cin >> option;
	do {
		particle *elementswarm = new particle[N_particle]; //定义基本粒子群
		pso PSO;  
		PSO.Initialize_vel_position(elementswarm, &PSO);
		//计算粒子群适应度，初始化个体极值和全局极值
		PSO.Initialize_fit_extremum(elementswarm, &PSO, option);
		//进入主要循环，按照公式依次迭代，直到满足精度要求
		ofstream out("output.txt");

		for (int k = 0; k <= M_particle; k++)
		{
			PSO.w_particle = w_max - k * (w_max - w_min) / M_particle;  //更新权重
			for (j = 0; j < N_particle; j++)
			{
				PSO.r1 = r.decimal(0, 1.0), PSO.r2 = r.decimal(0, 1.0);    //r1、r2产生随机数
				for (i = 0; i < D_particle; i++)
				{
					elementswarm[j].v_i[i] = PSO.w_particle * elementswarm[j].v_i[i] + c1_particle * PSO.r1*(elementswarm[j].y_i[i] - elementswarm[j].x_i[i]) + c2_particle * PSO.r2*(PSO.x_best[i] - elementswarm[j].x_i[i]);  //更新位置
					elementswarm[j].x_i[i] = elementswarm[j].x_i[i] + elementswarm[j].v_i[i];   //更新速度
				//速度和位置越界处理，取边界值
					if (elementswarm[j].x_i[i]< PSO.x_low[i] || elementswarm[j].x_i[i] >PSO.x_high[i])
						elementswarm[j].x_i[i] = PSO.x_high[i];
				}
				if (fit_function(elementswarm[j].x_i, option) < PSO.p_best[j])   //个体选优
				{
					PSO.p_best[j] = fit_function(elementswarm[j].x_i, option);
					for (i = 0; i < D_particle; i++)
					{
						elementswarm[j].y_i[i] = elementswarm[j].x_i[i];
					}
				}
				if (PSO.p_best[j] < fit_function(PSO.x_best, option))        //全局选优
				{
					for (i = 0; i < D_particle; i++)
					{
						PSO.x_best[i] = elementswarm[j].y_i[i];
					}
				}
			}
			int m = k + 1;
			PSO.g_best = fit_function(PSO.x_best, option);
			out << m << fixed << setw(20) << setprecision(10) << PSO.g_best << endl;
		}

		cout <<"最优变量：";
		for (int ii = 0; ii < D_particle; ii++)
		{
		
			cout << "x" << ii << "="  <<scientific<<setprecision(10) << PSO.x_best[ii] << endl;//输出最优变量
		}
	
		cout << "最优值=" << scientific<< setprecision(10) << PSO.g_best << endl;
		endTime = clock();//计时结束
		double s = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		cout << "用时：" << s << endl;
		cout << "请继续！请选择测试函数：1、Sphere 2、SchwdfelP22 3、Rosenbrock 4、Griewanks （退出请按 0）" << endl;
		scanf("%d", &option);
	} while (option != 0);
	getchar();
	return 0;
}
