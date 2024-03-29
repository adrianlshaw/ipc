.PHONY: help all posixmq posixshmem dbus shmem clean

CFLAGS ?= -Wall -Wextra -g

all: posixmq posixshmem shmem

POSIX := "posix_mq_"
posixmq:
	cc $(CFLAGS) $(POSIX)server.c -o $(POSIX)server -lrt
	cc $(CFLAGS) $(POSIX)client.c -o $(POSIX)client -lrt

dbus:
	cc $(CFLAGS) dbus-client.c -o dbus-client `pkg-config --cflags --libs glib-2.0 dbus-1` -ldbus-1 -lglib-2.0
	cc $(CFLAGS) dbus-server.c -o dbus-server `pkg-config --cflags --libs glib-2.0 dbus-1` -ldbus-1 -lglib-2.0 -ldbus-glib-1

posixshmem:
	cc $(CFLAGS) posix_shmem_reader.c -o posix_shmem_reader -lrt
	cc $(CFLAGS) posix_shmem_writer.c -o posix_shmem_writer -lrt

clean:
	rm -f $(POSIX)client $(POSIX)server
	rm -f posix_shmem_reader posix_shmem_writer
	rm -f posix_shmem_reader posix_shmem_writer
	rm -f dbus-client dbus-server
