all:	
	g++ -Wall -pedantic proxy.cpp utilities.cpp -o proxy
	g++ -Wall -pedantic client.cpp utilities.cpp -o client 
	
test:	
	g++ -Wall -pedantic test.cpp -o testing
	
clean:
	-rm testing
	-rm proxy
	-rm client
