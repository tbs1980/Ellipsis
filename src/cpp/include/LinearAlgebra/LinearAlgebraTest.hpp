/* 
 * File:   LinearAlgebraTest.hpp
 * Author: Sreekumar Balan
 * Email: tbs1980@gmail.com
 *
 * Created on 13 September 2012
 */
#ifndef LINEAR_ALGEBRA_TEST_HPP
#define LINEAR_ALGEBRA_TEST_HPP

#include<LinearAlgebra/LinearAlgebraBase.hpp>

namespace Ellipsis{ namespace UnitTests{

	bool TestVectorAllocation()
	{
		const unsigned ndim=1000000;
		LinearAlgebraBase<float>::realVectorType sx(ndim);
		LinearAlgebraBase<float>::complexVectorType sz(ndim);

		LinearAlgebraBase<double>::realVectorType dx(ndim);
		LinearAlgebraBase<double>::complexVectorType dz(ndim);
		
		return true;
	}

	bool TestVectorAlgebraLevelZero()
	{
		typedef LinearAlgebraBase<float> singlePrecisionLAType;
		
		const unsigned ndim=1000000;
		singlePrecisionLAType::realVectorType sx(ndim);
		singlePrecisionLAType::complexVectorType sz(ndim);
		
		if(singlePrecisionLAType::Rows(sx) != ndim)
			return false;
		if(singlePrecisionLAType::Rows(sz) != ndim)
			return false;
		
		return true;
	}

	bool TestVectorElementAccess()
	{
		const unsigned ndim=1000000;

		LinearAlgebraBase<double>::realVectorType dx(ndim);
		LinearAlgebraBase<double>::complexVectorType dz(ndim);
		
		for(unsigned i=0;i<ndim;++i)
		{
			dx(i)=(double)i;
			dz(i)=std::complex<double>((double)i,(double)i);
		}
		
		for(unsigned i=0;i<ndim;++i)
		{
			if(dx(i) != (double) i || dz(i).real() != (double) i || dz(i).imag() != (double) i)
				return false;
		}
		
		return true;
	}

}//namespace UclCl
}//namespace UnitTests

#endif//LINEAR_ALGEBRA_TEST_HPP

