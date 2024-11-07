#!/bin/bash

# find leap year

echo -e -n "enter a year: $year"
read year

if [ `expr $year % 4` -eq 0 -a `expr $year % 100` -ne 0 -o `expr $year % 400` -eq 0 ]
then
	echo -e -n "Its a leap year:) $year"
else
	echo -e -n "Not a leap year:( $year"
fi
