all: client server
client: client.cpp
	g++ $^ -o $@
server: server.cpp
	g++ $^ -o $@

.PHONY: clean
clean: client server
	-rm $^