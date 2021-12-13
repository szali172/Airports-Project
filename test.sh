#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="test-parsing"
TEST_ADDER="test-adder"
TEST_DIJKSTRA="test-parse-dijkstra"
TEST_VISUAL="test-visual-dfs"

echo "Testing Dijkstra"
cd parse-dijkstra/
./$TEST_DIJKSTRA
cd ..

echo "Testing Visual"
cd visual-dfs/
./$TEST_VISUAL
cd ..
