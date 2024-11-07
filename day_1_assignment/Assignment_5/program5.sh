#!/bin/bash
echo "Enter three values :  "
read n1 n2 n3
 
if [ $n1 -gt  $n2 -a  $n1 -gt $n3 ]
then
	echo -e -n "n1 is greater than n2 and n3\n"
elif [ $n2 -gt $n1 -a  $n2 -gt $n3 ]
then
	echo -e -n "n2 is greater than n1 and n3\n"
else
	echo -e -n "n3 is greater than n1 and n2\n"
fi
