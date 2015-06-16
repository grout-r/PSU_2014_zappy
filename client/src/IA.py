#!/usr/bin/python2

from tantorian import Tantorian

def IA(player):
    while player.isAlive():
        player.flush()
        if player.haveEnough("phiras", 3):
            print "Y a assez de phiras dans mon sac"
        player.take("sibur")
