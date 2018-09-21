
POSIX := "posix_mq_"
all:
	cc $(POSIX)server.c -o $(POSIX)server -lrt
	cc $(POSIX)client.c -o $(POSIX)client -lrt

clean:
	rm -f $(POSIX)client $(POSIX)server
