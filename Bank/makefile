#makefile for Bank-Simulation Program

main: main.o bank.o name.o account.o depositor.o transaction.o
	g++ -o main main.o bank.o name.o account.o depositor.o transaction.o

main.o: main.cpp
	g++ -c main.cpp

Bank.o: bank.cpp
	g++ -c bank.cpp

Name.o: name.cpp
	g++ -c name.cpp

Account.o: account.cpp
	g++ -c account.cpp

Depositor.o: depositor.cpp
	g++ -c depositor.cpp

Transaction.o: transaction.cpp
	g++ -c transaction.cpp

clean:
	rm ./*.o
