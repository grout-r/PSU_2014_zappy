#!/usr/bin/python2

import sys
import socket
import init
import time
from tantorian import Tantorian

def IA(player):
    while player.isAlive():
        player.flush()
        if player.haveEnough("phiras", 3):
            print "Y a assez de phiras dans mon sac"
        player.take("sibur")

def main(argv):
    client = init.getArgs(argv)
    sock = init.connect(client)
    player = Tantorian(client, sock)
    if not player.introduce():
        return
    IA(player)

if __name__ == "__main__":
    main(sys.argv[1:])
