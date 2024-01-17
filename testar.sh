for i in $( seq 1 4 ) ; do
	./myht < testes/teste${i}.in > aux
	diff aux testesOut/teste${i}.out	
done
rm aux;