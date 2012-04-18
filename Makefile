all:	
	g++ -Wall -pedantic server.cpp utilities.cpp -o server
	g++ -Wall -pedantic client.cpp utilities.cpp -o client 
	
test:	
	g++ -Wall -pedantic test.cpp -o testing
	
clean:
	-rm testing
	-rm proxy
	-rm client
