all: main.o measuring.o walkingBack.o malloc2dCharArray.o free2dCharArray.o schritte
	main.o: main.c
		cc -c main.c
	measuring.o: measuring.c
		cc -c measuring.c
	walkingBack.o: walkingBack.c
		cc -c walkingBack.c
	malloc2dCharArray.o: malloc2dCharArray.c
		cc -c malloc2dCharArray.c
	free2dCharArray.o: free2dCharArray.c
		cc -c free2dCharArray.c
	schitte: main.o measuring.o walkingBack.o malloc2dCharArray.o free2dCharArray.o
		cc -o schritte main.o measuring.o walkingBack.o malloc2dCharArray.o free2dCharArray.o
