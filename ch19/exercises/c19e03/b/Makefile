queueclient: queueclient.o queue2.o
	gcc -o queueclient queueclient.o queue2.o

queueclient.o: queueclient.c queue.h
	gcc -c queueclient.c

queue2.o: queue2.c queue.h
	gcc -c queue2.c
	
