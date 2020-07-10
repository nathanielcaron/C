#########################################
# Created by Nathaniel Caron
##########################################

# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -Wall -Wextra -std=c99 -g

# Help command
help:
	@printf "available command:\n"
	@printf "	make help               (this command)\n"
	@printf "	make sentiment1			(to build the C program from question 1)\n"
	@printf "	make sentiment2			(to build the C program from question 2)\n"
	@printf "	make clean				(to delete the executable and object files)\n"


# link our .o files to make an executable (Q1)
sentiment1: mainq1.o getWordStats.o
	$(COMPILER) $(C_FLAGS) -o sentiment1 mainq1.o getWordStats.o

# compile the `mainq1.c` file
mainq1.o: mainq1.c
	$(COMPILER) $(C_FLAGS) -c mainq1.c

# link our .o files to make an executable (Q2)
sentiment2: mainq2.o getWordStats.o
	$(COMPILER) $(C_FLAGS) -o sentiment2 mainq2.o getWordStats.o

# compile the `mainq2.c` file
mainq2.o: mainq2.c
	$(COMPILER) $(C_FLAGS) -c mainq2.c

# compile the `getWordStats.c` file
getWordStats.o: getWordStats.c
	$(COMPILER) $(C_FLAGS) -c getWordStats.c

#Delete executable and object files
clean:
	rm -f *.o sentiment1 sentiment2