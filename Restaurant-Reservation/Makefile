a2:	Control.o View.o Restaurant.o Patron.o PatronArray.o Reservation.o RsvArray.o Date.o Time.o
	g++ -o a2 Control.o View.o Restaurant.o Patron.o PatronArray.o Reservation.o RsvArray.o Date.o Time.o

Control.o:	Control.cc Control.h defs.h
	g++ -c Control.cc

View.o:	View.cc View.h
	g++ -c View.cc

Restaurant.o: Restaurant.cc Restaurant.h
	g++ -c Restaurant.cc

Patron.o: Patron.cc Patron.h
	g++ -c Patron.cc

PatronArray.o: PatronArray.cc PatronArray.h
	g++ -c PatronArray.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

RsvArray.o: RsvArray.cc RsvArray.h
	g++ -c RsvArray.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

clean:
	rm -f *.o a2
