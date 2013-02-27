BUILD=intel
include ./config/Makefile.$(BUILD)

vpath %.c src
vpath %.h src
vpath %.c examples
vpath %.h examples
vpath %.f90 examples

AR = ar r

all:lib test_c_ellipsis.exe 

#Guided-Hamiltonian-Sampler
lib:libghs.a
libghs.a:guided_hmc.o mt19937.o hanson.o
	$(AR) $@ $^
	mkdir -p lib
	mkdir -p include
	mv libghs.a lib
	cp src/guided_hmc.h include
	
#test the subroutines 
test:lib test_c_ellipsis.exe
	./test_c_ellipsis.exe
test_c_ellipsis.exe:test_c_ellipsis.o test_hanson.o  test_mt19937.o test_kinetic_energy.o guided_hmc.o mt19937.o hanson.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

#example programs in C and F90
examples:eg_gauss_c.exe eg_gauss_f.exe

#C examples
#N-dimensional uncorrelated gaussian distribution
eg_gauss_c.exe:eg_gauss_c.o
	$(CC) -L./lib $(LDFLAGS) -o $@ $^ $(LIBS) -lghs
eg_gauss_c.o:eg_gauss_c.c
	$(CC) -I./include $(CFLAGS) -c $<

eg_gauss_f.exe:eg_gauss_f.o
	$(FC) -L./lib $(LDFLAGS) -o $@ $^ $(LIBS) -lghs
eg_gauss_f.o:eg_gauss_f.f90
	$(FC) $(FFLAGS) -c $<
	
#F90 examples

#general rules
%.o:%.c
	$(CC) $(CFLAGS) -c $<
	
#clean up
clean:
	rm -r *.o *.mod *genmod.f90 *.exe *.txt lib include
	
