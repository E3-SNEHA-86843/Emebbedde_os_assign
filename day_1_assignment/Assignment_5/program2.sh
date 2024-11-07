#!/bin/bash

echo -e -n "1.date\n2.cal\n3.ls\n4.pwd\n5.Exit\n"

echo -e -n "Enter your choice: "
read choice

case $choice in
	1|date) date ;;
	2|cal) cal ;;
	3|ls) ls ;;
	4|pwd) pwd ;;
	5|exit)exit ;;
esac
