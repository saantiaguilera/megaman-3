.PHONY: all clean
all: client server editor

client:
	cd client && make
	mv client/client mclient

server:
	cd server && make
	mv server/server mserver

editor:
	cd editor && make
	mv editor/editor meditor

clean:
	cd client && make clean
	cd server && make clean
	cd editor && make clean
