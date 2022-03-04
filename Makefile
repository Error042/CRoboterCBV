all:schritte.o schritte
	schritte.o:schritte.c
		cc -c schritte.c
	schitte:schritte.o
		cc -o schritt schritt.o
