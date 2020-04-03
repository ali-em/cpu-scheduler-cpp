CC = g++ -std=c++11 
DO_NOT_LINK = -c 
all:Scheduler.out
	
Scheduler.out:main.o cpu.o core.o process.o thread.o tool.o
	$(CC) -o  Scheduler.out main.o cpu.o core.o process.o thread.o tool.o

main.o:main.cpp cpu.h core.h process.h thread.h tool.h
	$(CC) ${DO_NOT_LINK} main.cpp

tool.o:tool.h tool.cpp cpu.h thread.h process.h
	${CC} ${DO_NOT_LINK} tool.cpp

cpu.o:cpu.cpp cpu.h core.h process.h thread.h
	$(CC) ${DO_NOT_LINK} cpu.cpp

core.o:core.cpp core.h thread.h
	$(CC) ${DO_NOT_LINK} core.cpp

process.o:process.cpp process.h thread.h
	$(CC) ${DO_NOT_LINK} process.cpp

thread.o:thread.cpp thread.h
	$(CC) ${DO_NOT_LINK} thread.cpp

clean:
	rm *.o



