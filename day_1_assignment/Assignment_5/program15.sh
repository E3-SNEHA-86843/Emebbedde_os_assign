#!/bin/bash

echo "enter string 1"
read str1
echo "enter string 2"
read str2

echo "$str1 $str2"
str3=$str1$str2

reverse=`echo "$str3" |rev`
echo "$reverse"

