#!/usr/bin/python2

from trantorian import Trantorian

def getFoodToSurvive(player, q):
    player.flush()
    while player.haveEnough("nourriture", q) == False:
        player.flush()
        i = player.search("nourriture")
        if i == -1:
            player.move("avance")
        else:
            player.foundPathToItem(i)
            player.moveWithPath()
            player.take("nourriture")

def IA(player):
    while player.isAlive():
        getFoodToSurvive(player, 5)
