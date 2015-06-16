#!/usr/bin/python2

import sys

from src.init import connect
from src.init import getArgs
from src.tantorian import Tantorian
from src.IA import IA

def main(argv):
    client = getArgs(argv)
    sock = connect(client)
    player = Tantorian(client, sock)
    if not player.introduce():
        return
    IA(player)

if __name__ == "__main__":
    main(sys.argv[1:])
