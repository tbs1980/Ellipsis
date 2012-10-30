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

 
void run_guided_hmc(unsigned long num_dim,double* start_point,
	double dim_scale_fact,unsigned int max_steps,double* step_sizes,
	char* file_prefix,unsigned long seed,int resume,unsigned feedback_int,
	void (*neg_logpost_and_grad)(unsigned long,double*,double*,double*),
	void (*write_extract)(unsigned long,double*,double*,double*) );

/*void guided_hmc(double(*neg_logpost)(unsigned long,double*,double*,double*),
	void (*write_extract)(unsigned long,double*,double*,double*));*/

void leapfrog(unsigned long num_dim,double* x,double *g,double *p,
	unsigned num_steps,double epsilon,double* sigma,double *log_ratio,
	void (*neg_logpost)(unsigned long,double*,double*,double*));

void kinetic_energy(unsigned long num_dim,double* p,double* ke);
 
#ifdef __cplusplus
}
#endif

 
#endif/* ELLIPSIS_GUIDED_HMC_H */

