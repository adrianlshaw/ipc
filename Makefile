.PHONY: help all posixmq posixshmem dbus clean

CFLAGS ?= -Wall -Wextra -g

help: all
all:
	@echo "make (posixmq|posixshmem|dbus|clean)"

POSIX := "posix_mq_"
posixmq:
	cc $(CFLAGS) $(POSIX)server.c -o $(POSIX)server -lrt
	cc $(CFLAGS) $(POSIX)client.c -o $(POSIX)client -lrt

dbus:
	cc $(CFLAGS) dbus-client.c -o dbus-client `pkg-config --cflags --libs glib-2.0 dbus-1` -ldbus-1 -lglib-2.0 -ldbus-glib-1
	cc $(CFLAGS) dbus-server.c -o dbus-server `pkg-config --cflags --libs glib-2.0 dbus-1` -ldbus-1 -lglib-2.0 -ldbus-glib-1

posixshmem:
	cc $(CFLAGS) posix_shmem_reader.c -o posix_shmem_reader
	cc $(CFLAGS) posix_shmem_writer.c -o posix_shmem_writer

clean:
	rm -f $(POSIX)client $(POSIX)server
	rm -f posix_shmem_reader posix_shmem_writer
	rm -f dbus-client dbus-server
