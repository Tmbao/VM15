./gen_test
for i in {1..20}
do
	./sol_nam <tests/$i.in >tests/$i.out
done
