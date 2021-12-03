CXX=clang++
CXX_FLAGS=-std=c++20 -stdlib=libc++ -g -O0 -Wall -Wextra -Werror -Iincludes/

# Executable names:
EXE = airports
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o point.o dijkstra.o graph-parse.o print-graph.o graph.o  

# Use the cs225 makefile template:
include cs225/make/cs225.mk
