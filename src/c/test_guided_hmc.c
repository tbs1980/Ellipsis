/* 
 * File:   test_guided_hmc.c
 * Author: Sreekumar Balan
 * Email: st452@mrao.cam.ac.uk
 *
 * Created on 30 September 2012
 */
 
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include"guided_hmc.h"
#include"gauss.h"
#include"test_guided_hmc.h"
#include"inverse_gamma.h"

FILE* test_gauss_outfile;

void write_gauss_ghs_extract(unsigned long ndim,double* x,double* val,double* g)
{
	unsigned long i;
	if(test_gauss_outfile != NULL)
	{
		for(i=0;i<ndim-1;++i)
		{
			fprintf(test_gauss_outfile,"%e,",x[i]);
		}
		fprintf(test_gauss_outfile,"%e\n",x[ndim-1]);
	}
	else
	{
		printf("\nERROR IN WRITING GHS EXTRACT!\n");
	}
}


int test_kinetic_energy()
{
	const unsigned long ndim=100000;
	double * mtm;
	unsigned long i;
	double kin_eng,kin_eng_test;
	
	mtm=(double*)malloc(ndim*sizeof(double));
	
	kin_eng=0;
	for(i=0;i<ndim;++i)
	{
		mtm[i]=1.;
		kin_eng+=mtm[i]*mtm[i];
	}
	kin_eng*=0.5;
	
	kinetic_energy(ndim,mtm,&kin_eng_test);
	
	if(kin_eng != kin_eng_test)
	{
		free(mtm);
		return 0;
	}
	else
	{
		free(mtm);
		return 1;
	}
	
}

int test_guided_hmc()
{

	const unsigned long ndim=100;
	double* st;
	double* stp_sz;
	void (*nlp)(unsigned long,double*,double*,double*);
	void (*wrt_ext)(unsigned long,double*,double*,double*);
	double scl_fct;
	char* fl_pfx;
	unsigned long seed;
	unsigned fb_int;
	unsigned max_stp;
	int resume;
	const char* ext_file_name="gauss.extract.txt";
	unsigned long i;
	
	fl_pfx="gauss";
	
	st=(double*)malloc(ndim*sizeof(double));
	stp_sz=(double*)malloc(ndim*sizeof(double));
	
	for(i=0;i<ndim;++i)
	{
		st[i]=0.;
		stp_sz[i]=1;
	}
	
	
	nlp=&gauss_neg_log_post;
	wrt_ext=&write_gauss_ghs_extract;
	
	test_gauss_outfile=fopen(ext_file_name,"w");
	
	scl_fct=1.;
	fb_int=1000;
	max_stp=10;
	resume=1;
	seed=1234;
	
	run_guided_hmc(ndim,st,scl_fct,max_stp,stp_sz,fl_pfx,seed,resume,fb_int,nlp,wrt_ext);
		
	fclose(test_gauss_outfile);
	free(st);
	free(stp_sz);
	return 1;
}

int test_guided_hmc_inv_gamma()
{

	const unsigned long ndim=100;
	double* st;
	double* stp_sz;
	void (*nlp)(unsigned long,double*,double*,double*);
	void (*wrt_ext)(unsigned long,double*,double*,double*);
	double scl_fct;
	char* fl_pfx;
	unsigned long seed;
	unsigned fb_int;
	unsigned max_stp;
	int resume;
	const char* ext_file_name="inv_gamma.extract.txt";
	unsigned long i;
	
	
	fl_pfx="inv_gamma";
	
	st=(double*)malloc(ndim*sizeof(double));
	stp_sz=(double*)malloc(ndim*sizeof(double));
	
	for(i=0;i<ndim;++i)
	{
		st[i]=ig_beta/(ig_alpha-1);
		stp_sz[i]=ig_beta/( (ig_alpha-1)*sqrt(ig_alpha-2));
	}
	
	
	nlp=&inverse_gamma_neg_log_post;
	wrt_ext=&write_gauss_ghs_extract;
	
	test_gauss_outfile=fopen(ext_file_name,"w");
	
	scl_fct=1.;
	fb_int=500;
	max_stp=10;
	resume=1;
	seed=1234;
	
	run_guided_hmc(ndim,st,scl_fct,max_stp,stp_sz,fl_pfx,seed,resume,fb_int,nlp,wrt_ext);
		
	fclose(test_gauss_outfile);
	free(st);
	free(stp_sz);
	return 1;
}
