#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"test_guided_hmc.h"
#include"test_mt19937.h"
#include"test_gauss.h"
#include"test_hanson.h"

void print_diagnostic(int val,char* message);

int main(void)
{
	/* test the random number facilities */
	/*
	print_diagnostic(test_random_uni(),"uniform [0,1] random numbers");
	
	print_diagnostic(test_random_norm(),"Normal [0,1] random numbers");
	
	print_diagnostic(test_rand_save_state(),"random number generator save state");
	*/
	
	/* test Gaussian negative log posterior and gradient */
	/*
	print_diagnostic(test_unit_gauss(),"Gaussian negative log posterior");
	*/

	/* test CSV file IO */
	/*print_diagnostic(test_csv_IO(),"csv write and read");*/
	
	/* test Hanson's diagnostic */
	/*print_diagnostic(test_hanson_diag(),"Hanson's diagnostic");*/

	/* test guided hmc subroutines */
	/*print_diagnostic(test_kinetic_energy(),"kinetic_energy");*/
	
	print_diagnostic(test_guided_hmc(),"guided hmc");
	
	/*print_diagnostic(test_guided_hmc_inv_gamma(),"guided hmc with inverse gamma");*/
	
	
	return 0;
}

void print_diagnostic(int val,char* message)
{
	if(val == 0)
	{
		printf("Test: %s failed\n",message);
	}
	else
	{
		printf("Test: %s passed\n",message);
	}
}

