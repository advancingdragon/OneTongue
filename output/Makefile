calculator:
	node ../Runner.js > OutputCalculator.c
	gcc -g -c OutputCalculator.c
	gcc -g -c ../support.c
	gcc -g -o calculator OutputCalculator.o support.o

clean:
	rm calculator
	rm *.o
	rm OutputCalculator.c
