./gen_test
for i in {0..59}
do
	echo run test $i
	./sol_nam_random <tests/$i.in >tests/$i.out
done
