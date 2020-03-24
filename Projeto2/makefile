mst.out: main.o IO.o Graph_analyser.o
	gcc $^ -o $@

main.o: main.c
	gcc -g -c $<

IO.o: IO.c
	gcc -g -c $<

Graph_analyser.o: Graph_analyser.c
	gcc -g -c $<
