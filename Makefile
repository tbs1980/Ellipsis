BUILD=intel
include ./config/Makefile.$(BUILD)

vpath %.c src
vpath %.h src

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
	
#test subroutines 
test:lib test_c_ellipsis.exe
	./test_c_ellipsis.exe
test_c_ellipsis.exe:test_c_ellipsis.o test_hanson.o  test_mt19937.o test_kinetic_energy.o guided_hmc.o mt19937.o hanson.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

#general rules
%.o:%.c
	$(CC) $(CFLAGS) -c $<
	
#clean up
clean:
	rm -r *.o *.mod *genmod.f90 *.exe *.txt lib include
	
