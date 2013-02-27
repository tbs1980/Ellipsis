CC=gcc
FC=gfortran
CC_LANG_FLAGS=-std=c89
CC_WARN_FLAGS=-Wall -Wextra -pedantic -Wfatal-errors
CC_OPT_FLAGS=-O3 -fomit-frame-pointer
CFLAGS=$(CC_LANG_FLAGS) $(CC_WARN_FLAGS) $(CC_OPT_FLAGS)
FFLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3
LIBS=-lm

