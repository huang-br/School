#!/bin/bash

make linked_paren_checker
if [ -f "linked_paren_checker" ]; then
	echo "output according to linked_paren_checker:"
	for b in `ls paren_test_files/*balanced*`;do
		linked_paren_checker $b
	done
	bct=`for b in \`ls paren_test_files/*balanced*\`;do
		linked_paren_checker $b
	done | grep -v not | wc -l`
	echo $bct of 9 correct.
	echo "output according to linked_paren_checker:"
	for n in `ls paren_test_files/*not*`;do
		linked_paren_checker $n
	done
	nct=`for n in \`ls paren_test_files/*not*\`;do
		linked_paren_checker $n
	done | grep not | wc -l`
	echo $nct of 6 correct.
	echo $(( $nct + $bct )) of 15 correct in total.
else
	echo "linked_paren_checker did not compile."
fi
