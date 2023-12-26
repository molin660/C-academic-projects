bin/proFile: mainA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireAll.o fireOne.o helperA3.o
	gcc -Wall -std=c99 mainA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireAll.o fireOne.o helperA3.o -o bin/proFile
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -c src/recruitEmployee.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookOnId.c
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookOnFullName.c
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -c src/countEmployees.c
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/sortEmployeesId.c
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/fireAll.c
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/fireOne.c
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/helperA3.c
clean:
	rm *.o bin/proFile
