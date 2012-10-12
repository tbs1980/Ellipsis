EIGEN_INC_DIR=/home/sree/Library/eigen/eigen-eigen-43d9075b23ef
BOOST_INC_DIR=/home/sree/Library/boost/boost_1_51_0

COMPILER=gnu

#Linear Algebra Backend
ADDITIONAL_CXXFLAGS=-I$(EIGEN_INC_DIR) -DUSE_EIGEN_LINEAR_ALGEBRA
#ADDITIONAL_CXXFLAGS=-I$(BOOST_INC_DIR) -DUSE_BOOST_LINEAR_ALGEBRA

include Makefile.$(COMPILER)

TestCppEllipsis.exe:TestCppEllipsis.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)
TestCppEllipsis.o:TestCppEllipsis.cpp
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm *.o *.exe *.txt

