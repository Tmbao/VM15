for i in {0..21}
do
	echo "Test $i"
	./validator < "tests/$i.in"
done
