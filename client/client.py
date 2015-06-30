#!/usr/bin/python2

import sys

from src.init import connect
from src.init import getArgs
from src.trantorian import Trantorian
from src.IA import IA

def main(argv):
    client = getArgs(argv)
    sock = connect(client)
    player = Trantorian(client, sock)
    if not player.introduce():
        return
    IA(player)

if __name__ == "__main__":
    main(sys.argv[1:])
