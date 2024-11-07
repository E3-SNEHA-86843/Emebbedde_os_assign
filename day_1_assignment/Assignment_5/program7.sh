#!/bin/bash
echo "Enter number: "
read num

if [ $num -ge 0 ]
then
	echo -e -n "Number is positive+++\n"
else
	echo -e -n "Number is Negetive----\n"
fi
