#!/usr/bin/python2

import sys
import socket
import init

def main(argv):
    client = init.getArgs(argv)
    sock = init.connect(client)

    sock.close()

if __name__ == "__main__":
    main(sys.argv[1:])
