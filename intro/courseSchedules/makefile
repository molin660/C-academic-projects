courses: courses.o courses_main.o
	gcc -Wall -std=c99 courses.o courses_main.o -lm -o courses
courses.o: courses.c givenA1.h
	gcc -Wall -std=c99 -c courses.c
courses_main.o: courses_main.c givenA1.h
	gcc -Wall -std=c99 -c courses_main.c
clean:
	rm *.o courses
