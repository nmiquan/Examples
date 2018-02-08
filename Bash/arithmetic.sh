#!/bin/bash

echo "Enter $echo 1 + 1 results in"
echo 1 + 1
echo
echo "Enter echo $((1+1)) results in"
echo $((1+1))
echo
echo "Enter echo $[1 + 1] results in"
echo $[1 + 1]
echo
echo "Enter echo $[3/4] results in"
echo $[3/4]
echo
echo "Enter echo 3/4|bc -l results in"
echo 3/4|bc -l
