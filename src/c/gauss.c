#include<stdio.h>
#include"gauss.h"

void gauss_neg_log_post(unsigned long num_dims,double* x,double* v,double* g)
{
	unsigned long i;
	(*v)=0;
	for(i=0;i<num_dims;++i)
	{
		(*v)+=x[i]*x[i];
		g[i]=x[i];
	}
	(*v)*=0.5;
}

