#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="test-parsing"
TEST_ADDER="test-adder"
TEST_DIJKSTRA="test-parse-dikstra"
TEST_VISUAL="test-visual-dfs"

echo "Testing Dijkstra"
cd parse-dijstra/
./$TEST_DIJKSTRA
cd ..

echo "Testing Visual"
cd visual-dfs/
./$TEST_VISUAL
cd ..
