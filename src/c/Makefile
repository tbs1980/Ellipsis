BUILD=gnu
#BUILD=open64
#BUILD=intel
include Makefile.$(BUILD)

AR = ar r

default:libghs.a test_c_ellipsis.exe

libghs.a:guided_hmc.o mt19937.o hanson.o
	$(AR) $@ $^
	mkdir -p $(BUILD)/lib
	mkdir -p $(BUILD)/include
	mv libghs.a $(BUILD)/lib
	cp guided_hmc.h $(BUILD)/include

test_c_ellipsis.exe:test_c_ellipsis.o guided_hmc.o mt19937.o test_mt19937.o test_guided_hmc.o test_gauss.o gauss.o hanson.o test_hanson.o gamma_func.o inverse_gamma.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)
	mkdir -p $(BUILD)/bin
	mv  test_c_ellipsis.exe $(BUILD)/bin
test_c_ellipsis.o:test_c_ellipsis.c
	$(CC) $(CFLAGS) -c $<
guided_hmc.o:guided_hmc.c
	$(CC) $(CFLAGS) -c $<
mt19937.o:mt19937.c
	$(CC) $(CFLAGS) -c $<
test_mt19937.o:test_mt19937.c
	$(CC) $(CFLAGS) -c $<
test_guided_hmc.o:test_guided_hmc.c
	$(CC) $(CFLAGS) -c $<
test_gauss.o:test_gauss.c
	$(CC) $(CFLAGS) -c $<
gauss.o:gauss.c
	$(CC) $(CFLAGS) -c $<
hanson.o:hanson.c
	$(CC) $(CFLAGS) -c $<
test_hanson.o:test_hanson.c
	$(CC) $(CFLAGS) -c $<
gamma_func.o:gamma_func.c
	$(CC) $(CFLAGS) -c $<
inverse_gamma.o:inverse_gamma.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -r *.o *.exe *.txt *.a $(BUILD) $(BUILD)
