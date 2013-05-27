C++ 			= g++
C++ 			= $(C++)
STDCPP 		= --std=c++0x

ECHO 			= echo

OPTIMIZATION 	= -O2

LDLIBS 				=

WARNINGS 			= -Wall -pedantic

C++FLAGS 			= 	$(OPTIMIZATION) $(STDCPP) $(WARNINGS)

LDFLAGS 			= 	$(OPTIMIZATION) $(STDCPP)

ifeq ($(gdb), 1)
			LDFLAGS 			+= 	-g3
			C++FLAGS 			+= 	-g3

	OPTIMIZATION 			= -O0
endif

.cpp.o:
		@$(ECHO)
		@$(ECHO) "Compiling Source File --" $<
		@$(ECHO) "------------------------"
		$(C++) $(C++FLAGS) -c $<
		@$(ECHO)

all: testboard

testboard: player.h player.cpp testboard.cpp 

clean:
	rm -f testboard *.o core*
