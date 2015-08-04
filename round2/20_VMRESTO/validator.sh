for i in {0..20}
do
	echo "Test $i"
	./validator < "tests/$i.in"
done
