#!/bin/bash

echo "Enter filepath: "
read file
for file in *
do
	if [ -f $file ]
	then
		if [ -x $file ]
		then
			ls -l $file
		fi
	fi
done

