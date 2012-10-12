#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"gauss.h"
#include"test_gauss.h"

int test_unit_gauss()
{
	const unsigned long num_dim=100;
	double* x;
	double* g;
	unsigned long i;
	double val,val_test;
	int result=1;

	x=(double*)malloc(num_dim*sizeof(double));
	g=(double*)malloc(num_dim*sizeof(double));
	
	srand(12345);
	
	val_test=0;
	for(i=0;i<num_dim;++i)
	{
		x[i]=(double)rand()/(double)RAND_MAX;
		g[i]=0;
		val_test+=x[i]*x[i];
	}
	val_test*=0.5;
	
	gauss_neg_log_post(num_dim,x,&val,g);
	
	for(i=0;i<num_dim;++i)
	{
		if(val != val_test || g[i] != x[i])
		{
			result=0;
			break;
		}
	}
	
	free(x);
	free(g);
	return result;
}
