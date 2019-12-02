#include "pch.h"
void pso::Initialize_vel_position(particle *elementswarm, pso *PSO)
{
	int i, j;
	cout << "�����Ա��������ޣ�";
	cin >> x_low[0]>>x_low[1];
	cout << endl<<"�����Ա��������ޣ�";
	cin >> x_high[0] >> x_high[1];
	extern RandomNumber r;       //����ȫ�������
	(*PSO).x_best.resize(D_particle);
	(*PSO).p_best.resize(N_particle);
	for (i = 0; i < N_particle; i++)
	{
		elementswarm[i].x_i.resize(D_particle);
		elementswarm[i].v_i.resize(D_particle);
		elementswarm[i].y_i.resize(D_particle);
		for (j = 0; j < D_particle; j++)
		{
			elementswarm[i].x_i[j] = r.decimal((*PSO).x_low[j], (*PSO).x_high[j]);    //�����ʼ��λ��
			elementswarm[i].v_i[j] = r.decimal((*PSO).x_low[j] / 10, (*PSO).x_high[j] / 10);    //�����ʼ���ٶ�
		}
	}
}