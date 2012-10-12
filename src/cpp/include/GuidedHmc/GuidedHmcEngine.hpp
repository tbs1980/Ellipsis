/* 
 * File:   GuidedHmcEngine.hpp
 * Author: Sreekumar Balan
 * Email: st452@mrao.cam.ac.uk
 *
 * Created on 25 September 2012
 */

#ifndef GUIDED_HMC_ENGINE_HPP
#define GUIDED_HMC_ENGINE_HPP

#include<string>
#include<LinearAlgebra/LinearAlgebraBase.hpp>

namespace Ellipsis{


	template<typename realType,class negLogPostType>
	class GuidedHmc
	{
	public:
		typedef typename LinearAlgebraBase<realType>::realVectorType realVectorType;
		
		static void GhsEngine(unsigned long num_dim,realVectorType & start_point,realType dim_scale_fact,unsigned max_steps,
			realVectorType const& step_sizes,std::string chroot,unsigned long seed,bool resume,unsigned feed_back_interval,negLogPostType & neg_log_post)
		{
		}
		
		static void Leapfrog(unsigned long num_dim,realVectorType & x,realVectorType & g,realVectorType & p, unsigned num_steps,realType scalefact,realVectorType epsilon,realType& log_ratio,negLogPostType & neg_log_post)
		{
		}
		
		static void KineticEnergy(realVectorType & p, realType ke,unsigned long num_dim)
		{
		}		
	};

	

}

#endif
