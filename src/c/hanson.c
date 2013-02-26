/* 
 * File:   hanson.c
 * Author: Sreekumar Balan
 * Email: st452@mrao.cam.ac.uk
 *
 * Created on 30 September 2012
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>

#include"hanson.h"

void write_csv_file(FILE* outfile,unsigned long num_dims,double* vect)
{
	unsigned long i;
	for(i=0;i<num_dims-1;++i)
	{
		fprintf(outfile,"%.8e,",vect[i]);
	}
	fprintf(outfile,"%.8e\n",vect[num_dims-1]);

}

void read_csv_file(FILE* infile,unsigned long num_rows,
	unsigned long num_cols,double* matrix)
{
	unsigned long i,j;
	
	for(i=0;i<num_rows;++i)
	{
		for(j=0;j<num_cols-1;++j)
		{
			fscanf(infile,"%le,",&matrix[i*num_cols+j]);
		}
		fscanf(infile,"%le\n",&matrix[i*num_cols+num_cols-1]);
	}
}


void init_hanson_diag_data(hanson_data* diag_data,unsigned long num_dims,
	double tol_min,double tol_max)
{
	unsigned long i;
	diag_data->num_dims=num_dims;
	diag_data->num_ents=0;
	diag_data->keep_sampling=1;
	diag_data->tol_min=tol_min;
	diag_data->tol_max=tol_max;
	diag_data->sum_x3dpsi=(double*)malloc(num_dims*sizeof(double));
	diag_data->sum_x2dpsi=(double*)malloc(num_dims*sizeof(double));
	diag_data->sum_x2dpsi=(double*)malloc(num_dims*sizeof(double));
	diag_data->sum_xdpsi=(double*)malloc(num_dims*sizeof(double));
	diag_data->sum_dpsi=(double*)malloc(num_dims*sizeof(double));
	diag_data->sum_x=(double*)malloc(num_dims*sizeof(double));
	diag_data->sum_x2=(double*)malloc(num_dims*sizeof(double));
	diag_data->hanson=(double*)malloc(num_dims*sizeof(double));
	diag_data->start_point=(double*)malloc(num_dims*sizeof(double));
	
	for(i=0;i<num_dims;++i)
	{
		diag_data->sum_x3dpsi[i]=0;
		diag_data->sum_x2dpsi[i]=0;
		diag_data->sum_x2dpsi[i]=0;
		diag_data->sum_xdpsi[i]=0;
		diag_data->sum_dpsi[i]=0;
		diag_data->sum_x[i]=0;
		diag_data->sum_x2[i]=0;
		diag_data->hanson[i]=0;
		diag_data->start_point[i]=0;
	}
}

void free_hanson_diag_data(hanson_data* diag_data)
{
	free(diag_data->sum_x3dpsi);
	free(diag_data->sum_x2dpsi);
	free(diag_data->sum_xdpsi);
	free(diag_data->sum_dpsi);
	free(diag_data->sum_x);
	free(diag_data->sum_x2);
	free(diag_data->hanson);
	free(diag_data->start_point);
}

void push_state(hanson_data* diag_data,unsigned long num_dims,
	double* x, double* g)
{
	unsigned long i;
	double xi,gi,E_x,E_x2,E_x3dpsi,E_x2dpsi,E_xdpsi,E_dpsi,var1,var2;
	
	assert(num_dims==diag_data->num_dims);
	
	/* increase the number of samples by 1 */
	++(diag_data->num_ents);
	
	diag_data->keep_sampling=0;
	
	/* calculate the hanson statistic */
	for(i=0;i<num_dims;++i)
	{
		xi=x[i];
		gi=g[i];
		
		/* set the start point */
		diag_data->start_point[i]=xi;
		
		/* accumulate */
		diag_data->sum_x[i]+=xi;
		diag_data->sum_x2[i]+=xi*xi;
		diag_data->sum_dpsi[i]+=gi;
		diag_data->sum_xdpsi[i]+=xi*gi;
		diag_data->sum_x2dpsi[i]+=xi*xi*gi;
		diag_data->sum_x3dpsi[i]+=xi*xi*xi*gi;
		
		/* check for convergence */
		E_x=diag_data->sum_x[i]/(double)diag_data->num_ents;
		E_x2=diag_data->sum_x2[i]/(double)diag_data->num_ents;
		E_dpsi=diag_data->sum_dpsi[i]/(double)diag_data->num_ents;
		E_xdpsi=diag_data->sum_xdpsi[i]/(double)diag_data->num_ents;
		E_x2dpsi=diag_data->sum_x2dpsi[i]/(double)diag_data->num_ents;
		E_x3dpsi=diag_data->sum_x3dpsi[i]/(double)diag_data->num_ents;
		
		/* calculate the two different version of the variance */
		var1=E_x2-E_x*E_x;
		var2=(E_x3dpsi-3.*E_x*E_x2dpsi+3.*E_x*E_x*E_xdpsi-
			E_x*E_x*E_x*E_dpsi)/3.;
		/* calculate Hanson's statistic */
		diag_data->hanson[i]=var1/var2;
		
		/* if converged no more sampling required */
		if(diag_data->hanson[i] < diag_data->tol_min || 
			diag_data->hanson[i] > diag_data->tol_max)
		{
			diag_data->keep_sampling=1;
		}	
	}	
}

void write_diag_data_to_file(hanson_data* diag_data,const char* file_name)
{
	unsigned long i;
	double* num_samples;
	double* mean;
	double* std_dvn;
	FILE *outfile;
	outfile=fopen(file_name,"w");
	
	/* assign memory */
	num_samples=(double*)malloc(diag_data->num_dims*sizeof(double));
	mean=(double*)malloc(diag_data->num_dims*sizeof(double));
	std_dvn=(double*)malloc(diag_data->num_dims*sizeof(double));
	
	/* calculate the mean and standard deviation */
	for(i=0;i<diag_data->num_dims;++i)
	{
		num_samples[i]=(double)diag_data->num_ents;
		mean[i]=diag_data->sum_x[i]/num_samples[i];
		std_dvn[i]=sqrt(diag_data->sum_x2[i]/num_samples[i]-mean[i]*mean[i]);
	}
	
	/* write the data */
	write_csv_file(outfile,diag_data->num_dims,diag_data->start_point);
	write_csv_file(outfile,diag_data->num_dims,diag_data->sum_x);
	write_csv_file(outfile,diag_data->num_dims,diag_data->sum_x2);
	write_csv_file(outfile,diag_data->num_dims,diag_data->sum_x3dpsi);
	write_csv_file(outfile,diag_data->num_dims,diag_data->sum_x2dpsi);
	write_csv_file(outfile,diag_data->num_dims,diag_data->sum_xdpsi);
	write_csv_file(outfile,diag_data->num_dims,diag_data->sum_dpsi);
	write_csv_file(outfile,diag_data->num_dims,num_samples);
	write_csv_file(outfile,diag_data->num_dims,diag_data->hanson);
	write_csv_file(outfile,diag_data->num_dims,mean);
	write_csv_file(outfile,diag_data->num_dims,std_dvn);
	
	/* free memory */
	free(num_samples);
	free(mean);
	free(std_dvn);
	fclose(outfile);
}

int read_diag_data_from_file(hanson_data* diag_data,const char* file_name)
{
	unsigned long i,result;
	FILE *infile;
	double* mat;
	const unsigned long nrows=12;
	const unsigned long ncols=diag_data->num_dims;
	double E_x,E_x2,E_x3dpsi,E_x2dpsi,E_xdpsi,E_dpsi,var1,var2;

	mat=(double*)malloc(nrows*ncols*sizeof(double));
	
	result=1;
	infile=fopen(file_name,"r");
	if(infile != NULL )
	{
		diag_data->keep_sampling=0;
		/* read the diagnostic file */
		read_csv_file(infile,nrows,ncols,mat);
		for(i=0;i<ncols;++i)
		{
			/* gather info for calculating Hanson */
			diag_data->start_point[i]=mat[0*ncols+i];
			diag_data->sum_x[i]=mat[1*ncols+i];
			diag_data->sum_x2[i]=mat[2*ncols+i];
			diag_data->sum_x3dpsi[i]=mat[3*ncols+i];
			diag_data->sum_x2dpsi[i]=mat[4*ncols+i];
			diag_data->sum_xdpsi[i]=mat[5*ncols+i];
			diag_data->sum_dpsi[i]=mat[6*ncols+i];
			diag_data->num_ents=(unsigned long)mat[7*ncols+i];
			diag_data->hanson[i]=mat[8*ncols+i];
			
			/* if converged no more sampling required */
			if(diag_data->hanson[i] < diag_data->tol_min || 
				diag_data->hanson[i] > diag_data->tol_max)
			{
				diag_data->keep_sampling=1;
			}			
		}
	}
	else
	{
		result=0;
	}
	free(mat);
	fclose(infile);
	return result;
}
