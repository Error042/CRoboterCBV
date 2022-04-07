all: main.o measuring.o malloc2dCharArray.o populate2dCharArray.o free2dCharArray.o decideHowToWalkBack.o walkingBack.o schritte
	main.o: main.c
		cc -c main.c
	measuring.o: measuring.c
		cc -c measuring.c
	malloc2dCharArray.o: malloc2dCharArray.c
		cc -c malloc2dCharArray.c
	populate2dCharArray.o: populate2dCharArray.c
		cc -c populate2dCharArray.c
	free2dCharArray.o: free2dCharArray.c
		cc -c free2dCharArray.c
	decideHowToWalkBack.o: decideHowToWalkBack.c
		cc -c decideHowToWalkBack.c
	walkingBack.o: walkingBack.c
		cc -c walkingBack.c
	schitte: main.o measuring.o malloc2dCharArray.o populate2dCharArray.o free2dCharArray.o decideHowToWalkBack.o walkingBack.o
		cc -o schritte main.o measuring.o malloc2dCharArray.o populate2dCharArray.o free2dCharArray.o decideHowToWalkBack.o walkingBack.o
