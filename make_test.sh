#!/bin/bash

chmod 777 generator.dms

if [ $1 == 1 ]
then
	map="flow-one"
elif [ $1 == 2 ]
then
	map="flow-ten"
elif [ $1 == 3 ]
then
	map="flow-thousand"
elif [ $1 == 4 ]
then
	map="big"
elif [ $1 == 5 ]
then
	map="big-superposition"
else
	echo "use param:"
	echo "for flow_one - 1"
	echo "for flow_ten - 2"
	echo "for flow_thousand - 3"
	echo "for big - 4"
	echo "for big_superposition - 5"
	exit
fi

echo "map: $map"
./generator.dms --$map > $map
time your=$(./lem-in < $map | grep "L" | wc -l | awk '{ gsub (" ", "", $0); print}')
required=$(cat $map | grep "#Here is the number of lines required:" |
head -1 | awk '{ gsub ("#Here is the number of lines required: ", "", $0); print}')

if (("$your" <= "$required"))
then
  rm $map
	echo "✅  your result = $your | required result = $required"
else
  rm $map
	echo "⭕️  your result = $your | required result = $required | difference = $(($your - $required))"
fi
