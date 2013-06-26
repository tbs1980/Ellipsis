BUILD=intel
include ../config/Makefile.$(BUILD)

#example programs in C and F90
examples:uncorr_gauss_c.exe uncorr_gauss_f.exe gauss_f.exe

#C examples
#N-dimensional uncorrelated gaussian distribution
uncorr_gauss_c.exe:uncorr_gauss_c.o
	$(CC) -L../lib $(LDFLAGS) -o $@ $^ -lghs $(LIBS) 
uncorr_gauss_c.o:uncorr_gauss_c.c
	$(CC) -I../include $(CFLAGS) -c $<

#F90 examples
uncorr_gauss_f.exe:uncorr_gauss_f.o
	$(FC) -L../lib $(LDFLAGS) -o $@ $^ -lghs $(LIBS) 

gauss_f.exe:lin_alg.o gauss_f_mod.o gauss_f.o
	$(FC) -L../lib $(LDFLAGS) -o $@ $^ -lghs -llapack  $(LIBS) 
	

#general rules
%.o:%.c
	$(CC) $(CFLAGS) -c $<
%.o:%.f90
	$(FC) $(FFLAGS) -c $<

#clean up
clean:
	rm -r *.o *.mod *genmod.f90 *.exe *.txt lib include
	
