#!/usr/bin/python2

from trantorian import Trantorian

def IA(player):
    while player.isAlive():
        player.flush()
        # if player.haveEnough("phiras", 3):
        #     print "Y a assez de phiras dans mon sac"
        index = player.search("nourriture")
        if index != -1:
            player.foundPathToItem(index)
            print "Fini de chercher le chemin"
            player.moveWithPath()
            print "Fini de bouger"
            player.take("nourriture")
