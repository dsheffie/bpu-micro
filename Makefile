OBJ = main.o history.o
CC = clang
CFLAGS = -O2
DEP = $(OBJ:.o=.d)
EXE = bpu

.PHONY : all clean

all: $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(EXE)

%.o: %.cc
	$(CC) -MMD $(CFLAGS) -c $< 


-include $(DEP)

clean:
	rm -rf $(EXE) $(OBJ) $(DEP)
