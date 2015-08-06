./gen_test
for i in {0..21}
do
	./sol_nam <tests/$i.in >tests/$i.out
done
