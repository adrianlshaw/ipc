.PHONY: help all posix dbus clean

CFLAGS ?= -Wall -Wextra -g

help: all
all:
	@echo "make (posix|dbus|clean)"

POSIX := "posix_mq_"
posix:
	cc $(CFLAGS) $(POSIX)server.c -o $(POSIX)server -lrt
	cc $(CFLAGS) $(POSIX)client.c -o $(POSIX)client -lrt

dbus:
	cc $(CFLAGS) dbus-client.c -o dbus-client `pkg-config --cflags --libs glib-2.0 dbus-1` -ldbus-1 -lglib-2.0 -ldbus-glib-1
	cc $(CFLAGS) dbus-server.c -o dbus-server `pkg-config --cflags --libs glib-2.0 dbus-1` -ldbus-1 -lglib-2.0 -ldbus-glib-1

clean:
	rm -f $(POSIX)client $(POSIX)server
	rm -f dbus-client dbus-server
