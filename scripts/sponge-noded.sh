#! /bin/sh

### BEGIN INIT INFO
# Provides:          sponge-noded
# Required-Start:    $all
# Required-Stop:     $all
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: starts the sponge-noded server
# Description:       starts sponge-noded using start-stop-daemon
### END INIT INFO

PATH=/opt/sponge/sbin:/sbin:/bin:/usr/sbin:/usr/bin
DAEMON=/opt/sponge/sbin/noded
NAME=sponge-noded
DESC=sponge-noded

test -x $DAEMON || exit 0

# Include sponge-noded defaults if available
if [ -f /etc/default/sponge-noded] ; then
        . /etc/default/sponge-noded
fi

set -e

case "$1" in
  start)
        echo -n "Starting $DESC: "
        start-stop-daemon --start --quiet --pidfile /opt/sponge/logs/$NAME.pid \
                --exec $DAEMON -- $DAEMON_OPTS
        echo "$NAME."
        ;;
  stop)
        echo -n "Stopping $DESC: "
        start-stop-daemon --stop --quiet --pidfile /opt/sponge/logs/$NAME.pid \
                --exec $DAEMON
        echo "$NAME."
        ;;
  restart|force-reload)
        echo -n "Restarting $DESC: "
        start-stop-daemon --stop --quiet --pidfile \
                /opt/sponge/logs/$NAME.pid --exec $DAEMON
        sleep 1
        start-stop-daemon --start --quiet --pidfile \
                /opt/sponge/logs/$NAME.pid --exec $DAEMON -- $DAEMON_OPTS
        echo "$NAME."
        ;;
  reload)
          echo -n "Reloading $DESC configuration: "
          start-stop-daemon --stop --signal HUP --quiet --pidfile     /opt/sponge/logs/$NAME.pid \
              --exec $DAEMON
          echo "$NAME."
          ;;
      *)
            N=/etc/init.d/$NAME
            echo "Usage: $N {start|stop|restart|reload|force-reload}" >&2
            exit 1
            ;;
    esac

    exit 0
