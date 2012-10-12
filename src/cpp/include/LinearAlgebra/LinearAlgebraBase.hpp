/* 
 * File:   LinearAlgebraBase.hpp
 * Author: sree
 * Email: tbs1980@gmail.com
 *
 * Created on 13 September 2012
 */

#ifndef LINEARALGEBRABASE_HPP
#define	LINEARALGEBRABASE_HPP

#ifdef USE_EIGEN_LINEAR_ALGEBRA
#include <Eigen/Dense>
#else
#ifdef USE_UBLAS_LINEAR_ALGEBRA
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#else
#include<LinearAlgebra/ModifiedStdVector.hpp>
#include<complex>
#endif //USE_UBLAS_LINEAR_ALGEBRA
#endif //USE_EIGEN_LINEAR_ALGEBRA

namespace Ellipsis{
	
#ifdef USE_EIGEN_LINEAR_ALGEBRA

	template<typename T>
	class LinearAlgebraBase
	{
	public:
		typedef T realType;
		typedef std::complex<realType> complexType;
		
		//define real and complex vector types
		typedef Eigen::Matrix<realType,Eigen::Dynamic,1> realVectorType;
		typedef Eigen::Matrix<complexType,Eigen::Dynamic,1> complexVectorType;

		typedef Eigen::Matrix<realType,Eigen::Dynamic,Eigen::Dynamic> realMatrixType;
		typedef Eigen::Matrix<complexType,Eigen::Dynamic,Eigen::Dynamic> complexMatrixType;
		
		//size of vectors
		template<typename argType>
		static size_t Rows(Eigen::Matrix<argType,Eigen::Dynamic,1> const& v)
		{
			return v.size();
		}
	};

#else
#ifdef USE_UBLAS_LINEAR_ALGEBRA

	template<typename T>
	class LinearAlgebraBase
	{
	public:
		typedef T realType;
		typedef std::complex<realType> complexType;
		
		//define real and complex vector types
		typedef boost::numeric::ublas::vector<realType> realVectorType;
		typedef boost::numeric::ublas::vector<complexType> complexVectorType;

		typedef boost::numeric::ublas::matrix<realType> realMatrixType;
		typedef boost::numeric::ublas::matrix<complexType> complexMatrixType;
		
		//size of vectors
		template<typename argType>
		static size_t Rows(boost::numeric::ublas::vector<argType> const& v)
		{
			return v.size();
		}

	};

#else
	template<typename T>
	class LinearAlgebraBase
	{
	public:
		typedef T realType;
		typedef std::complex<realType> complexType;
		
		//define real and complex vector types
		typedef LinAlgVector<realType> realVectorType;
		typedef LinAlgVector<complexType> complexVectorType;
		
		//size of vectors
		template<typename argType>
		static size_t Rows(LinAlgVector<argType> const& v)
		{
			return v.size();
		}
		
	};
#endif //USE_UBLAS_LINEAR_ALGEBRA
#endif //USE_EIGEN_LINEAR_ALGEBRA

	
	
}



#endif	/* LINEARALGEBRABASE_HPP */

