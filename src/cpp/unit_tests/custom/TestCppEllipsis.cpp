/* 
 * File:   TestCppEllipsis.cpp
 * Author: Sreekumar Balan
 * Email: tbs1980@gmail.com
 *
 * Created on 13 September 2012
 */

#include<iostream>
#include<limits>

#include<LinearAlgebra/LinearAlgebraTest.hpp>

static void PrintDiagnostic(bool result,std::string nameOfTheTest);


int main(void)
{
	using namespace Ellipsis::UnitTests;
	
	//Linear algebra
	PrintDiagnostic(TestVectorAllocation(),"Linear Algebra Allocation");
	PrintDiagnostic(TestVectorAlgebraLevelZero(),"Linear Algebra Level Zero");
	PrintDiagnostic(TestVectorElementAccess(),"Linear Access vector elements");
	
	return 0;
}

static void PrintDiagnostic(bool result,std::string nameOfTheTest)
{
	std::cout<<"Test: "<<nameOfTheTest;
	if(result)
	{
		std::cout<<"... Passed!"<<std::endl;
	}
	else
	{
		std::cout<<"... Failed!"<<std::endl;
	}
}

