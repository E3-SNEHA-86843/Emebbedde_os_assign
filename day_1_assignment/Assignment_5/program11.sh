#!/bin/bash

echo "enter basic salary"
read basicsalary 


DA=`echo "scale=2;0.4 * $basicsalary" | bc` 
echo "da : $DA-----"


HRA=`echo "scale=2; 0.2 * $basicsalary" | bc`
echo "hra : $HRA"

deduction=`echo "scale=2; $DA + $HRA" | bc`
echo "ded = $deduction"

gross=`expr $basicsalary - $deduction`
echo "sal = $grosssalary"




