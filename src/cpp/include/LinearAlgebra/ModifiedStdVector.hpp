/* 
 * File:   ModifiedStdVector.hpp
 * Author: Sreekumar Balan
 * Email: tbs1980@gmail.com
 *
 * Created on 13 September 2012
 */

#ifndef MODIFIEDSTDVECTOR_HPP
#define	MODIFIEDSTDVECTOR_HPP

#include<vector>
#include<cstring>

namespace Ellipsis{
	
	template<class T, class Allocator = std::allocator<T> >
	class LinAlgVector :public std::vector<T,Allocator>
	{
	public:
		typedef typename std::vector<T,Allocator>::reference reference;
		typedef typename std::vector<T,Allocator>::const_reference   const_reference;
		
		LinAlgVector()
		{
		}
		
		LinAlgVector(size_t n, const T& v= T(), const Allocator& a= Allocator() )
			:std::vector<T,Allocator>(n,v,a)
		{
		}
		~LinAlgVector()
		{
		}
	
		reference operator()(size_t __n)
		{
			return *(this->_M_impl._M_start + __n);
		}
	
		const_reference operator()(size_t __n) const
		{
			return *(this->_M_impl._M_start + __n);
		}
		
	};
}


#endif	/* MODIFIEDSTDVECTOR_HPP */

