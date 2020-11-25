all: A4-95026.o food.o restaurant.o customer.o order.o
	g++ A4-95026.o food.o restaurant.o customer.o order.o -o a.out
food.o: food.h food.cpp
	g++ -c food.cpp
customer.o: customer.h customer.cpp
	g++ -c customer.cpp
order.o: order.h order.cpp
	g++ -c order.cpp
restaurant.o:food.h restaurant.h restaurant.cpp
	g++ -c restaurant.cpp 
A4-95026.o: restaurant.h food.h A4-95026.cpp
	g++ -c A4-95026.cpp
clean:
	rm *.o