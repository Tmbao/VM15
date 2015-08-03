for i in {1..20}
do
	echo "Test $i"
	./validator < "tests/$i.in"
done
