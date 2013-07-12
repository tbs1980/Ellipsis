cmake_minimum_required(VERSION 2.6)


if(CMAKE_COMPILER_IS_GNUCC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -std=c89 -pedantic -Wall -Wextra -Wfatal-errors -fPIC")
elseif(CMAKE_COMPILER_IS_INTELCC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -std=c89 -pedantic -Wall -Wextra -Wfatal-errors -fPIC ")
endif(CMAKE_COMPILER_IS_GNUCC)


add_library(ellipsis guided_hmc.c  hanson.c  mt19937.c)

