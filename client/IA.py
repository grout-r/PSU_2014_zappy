#!/usr/bin/python2

import sys
import socket
import init
import time
from tantorian import Tantorian

def IA(player):
    while player.isAlive():
        player.flush()
        if not player.haveEnough("phiras", 3):
            print "Recherche de phiras"
            player.search("phiras")
        else:
            print "Recherche de sibur"
            player.search("sibur")

def main(argv):
    client = init.getArgs(argv)
    sock = init.connect(client)
    player = Tantorian(client, sock)
    if not player.introduce():
        return
    IA(player)

if __name__ == "__main__":
    main(sys.argv[1:])
