all:	
	g++ -Wall -pedantic proxy.cpp -o proxy 
	
test:	
	g++ -Wall -pedantic test.cpp -o testing
	
clean:
	-rm testing
	-rm proxy
