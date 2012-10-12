/* 
 * File:   inverse_gamma.c
 * Author: Sreekumar Balan
 * Email: st452@mrao.cam.ac.uk
 *
 * Created on 03 October 2012
 */

#include<math.h>
#include"gamma_func.h"
#include"inverse_gamma.h"


void inverse_gamma_neg_log_post(unsigned long num_dims,double* x,double* v,double* g)
{
	unsigned long i;
	const double gamma_alpha=gamma(ig_alpha);
	*v=0;
	for(i=0;i<num_dims;++i)
	{
		if(x[i]>0)
		{
			*v+=-ig_alpha*log(ig_beta)+log(gamma_alpha)+
				(ig_alpha+1)*log(x[i])+ig_beta/x[i];
			g[i]=(ig_alpha+1)/x[i]-ig_beta/(x[i]*x[i]);
		}
		else
		{
			*v=HUGE_VAL;
			break;
		}
	}
	
}
