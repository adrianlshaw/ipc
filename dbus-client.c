#include <stdio.h>
#include <string.h>
#include "protocol.h"
#include <dbus/dbus.h>

int main(int argc, char **argv)
{
    DBusError error;
    dbus_error_init(&error);

    DBusConnection *handle = dbus_bus_get(DBUS_BUS_SESSION, &error);

    if (!handle)
    {
        printf("Failed to connect to the D-BUS daemon: %s", error.message);
        dbus_error_free(&error);
        return 1;
    }

    if (argc == 1)
    {
        puts("Usage example: dbus-client -c -c -c -q");
        return 0;
    }

    DBusMessage *msg;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-c"))
        {
            msg = dbus_message_new_signal("/org/share/linux",
                                          "org.share.linux",
                                          "Customize");

            dbus_connection_send(handle, msg, NULL);

            dbus_message_unref(msg);
            
            puts("Sent msg");

        }

        else if (!strcmp(argv[i], "-q"))
        {
            msg = dbus_message_new_signal("/org/share/linux",
                                              "org.share.linux",
                                              "Quit");

            dbus_connection_send(handle, msg, NULL);

            dbus_message_unref(msg);

            puts("Sent msg");
        }
    }

    return 0;
}