# Executable names:
EXE = airports
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o graph.o

# Generated files
CLEAN_RM = \
						*.o *.d tests/*.o tests/*.d cs225/*.d cs225/*.o \
						cs225/lodepng/*.o cs225/lodepng/*.d \
						cs225/catch/*.o cs225/catch/*.d

# Use the cs225 makefile template:
include cs225/make/cs225.mk


# MP-specific targets
GRAPH_OBJS = test-dijkstra.o test-print.o test-parse.o graph.o
GRAPH_OBJS += graph.o

testdsets: $(GRAPH_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@
