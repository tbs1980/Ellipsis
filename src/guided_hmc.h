/* 
 * File:   guided_hmc.h
 * Author: Sreekumar Balan
 * Email: st452@mrao.cam.ac.uk
 *
 * Created on 26 September 2012
 */
 
#ifndef ELLIPSIS_GUIDED_HMC_H
#define ELLIPSIS_GUIDED_HMC_H
 
#ifdef __cplusplus
extern "C" {
#endif

 
void run_guided_hmc(int num_dim,double* start_point,
	double dim_scale_fact,int max_steps,double* step_sizes,
	char* file_prefix,int seed,int resume,int feedback_int,
	void (*neg_logpost)(int*,double*,double*,double*),
	void (*write_extract)(int*,double*,double*,double*) );
	
void leapfrog(int num_dim,double* x,double *g,double *p,
	int num_steps,double epsilon,double* sigma,double *log_ratio,
	void (*neg_logpost)(int*,double*,double*,double*));

void kinetic_energy(int num_dim,double* p,double* ke);
 
#ifdef __cplusplus
}
#endif

 
#endif/* ELLIPSIS_GUIDED_HMC_H */

