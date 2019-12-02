#include "pch.h"
void pso::Initialize_fit_extremum(particle *elementswarm, pso *PSO,int c)
{
	int i, j;
	for (j = 0; j < N_particle; j++)
	{
		(*PSO).p_best[j] = fit_function(elementswarm[j].x_i,c);  //�ȼ���������ӵ���Ӧ��
		for (i = 0; i < D_particle; i++)
		{
			elementswarm[j].y_i[i] = elementswarm[j].x_i[i];
		}
	}
	for (i = 0; i < D_particle; i++)
	{
		(*PSO).x_best[i] = elementswarm[N_particle - 1].x_i[i];
	}
	(*PSO).g_best = fit_function((*PSO).x_best,c);
	for (j = 0; j < N_particle - 1; j++)
	{
		if (fit_function(elementswarm[j].x_i,c) < (*PSO).g_best)
		{
			for (i = 0; i < D_particle; i++)
			{
				(*PSO).x_best[i] = elementswarm[j].x_i[i];   //��������ֵ��Ӧ���Ż�����
			}(*PSO).g_best = fit_function(elementswarm[j].x_i,c);
		}                   //�ҵ�ȫ�����ű���
	}
}