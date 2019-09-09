#!/bin/bash

param=$1

chmod 777 generator.dms

if [ $param == 1 ]
then
	./generator.dms --flow-one > param_1_flow_one
	time ../lem-in < param_1_flow_one | grep "L" | wc -l

elif [ $param == 2 ]
then
	./generator.dms --flow-ten > param_2_flow_ten
	time ../lem-in < param_2_flow_ten | grep "L" | wc -l

elif [ $param == 3 ]
then
	./generator.dms --flow-thousand > param_3_flow_thousand
	time ../lem-in < param_3_flow_thousand | grep "L" | wc -l

elif [ $param == 4 ]
then
	./generator.dms --big > param_4_big
	time ../lem-in < param_4_big | grep "L" | wc -l

elif [ $param == 5 ]
then
	./generator.dms --big-superposition > param_5_big_superposition
	time ../lem-in < param_5_big_superposition | grep "L" | wc -l

else
	echo "use param:"
	echo "for flow_one - 1"
	echo "for flow_ten - 2"
	echo "for flow_thousand - 3"
	echo "for big - 4"
	echo "for big_superposition - 5"
fi
