#!/bin/bash
echo "Enter file or directory: "
read file_name

if [ -e $file_name ]
then

	if [ -d $file_name ]
	then
		echo -e -n "File is Directory\n"
	elif [ -f $file_name ]
	then
		echo -e -n "Regular File...\n"

		if [ -x $file_name ]
		then
			echo -e -n "File has exicutable permission..\n"
		fi
	fi
else
	echo -e -n "File not exist...\n"
fi
