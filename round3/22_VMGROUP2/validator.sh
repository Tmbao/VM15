for i in {0..59}
do
	echo validator test$i
	./validator <tests/$i.in
done
