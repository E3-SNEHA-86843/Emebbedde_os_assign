#!/bin/bash
echo "Enter number: "
read num

i=1

function factorial ( $num )
{
	num=`expr $num \* $i`
	echo "$num"
	i=`expr $i + 1` 
}
factorial
