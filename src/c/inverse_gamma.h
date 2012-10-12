/* 
 * File:   inverse_gamma.h
 * Author: Sreekumar Balan
 * Email: st452@mrao.cam.ac.uk
 *
 * Created on 03 October 2012
 */

#ifndef ELLIPSIS_INVERSE_GAMMA_H
#define ELLIPSIS_INVERSE_GAMMA_H

#include<stdlib.h>
#include<string.h>

static double ig_alpha=5;
static double ig_beta=5;

void inverse_gamma_neg_log_post(unsigned long num_dims,double* x,double* v,double* g);

#endif/*ELLIPSIS_INVERSE_GAMMA_H*/
