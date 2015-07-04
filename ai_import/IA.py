#!/usr/bin/python2

from trantorian import Trantorian

def getFoodToSurvive(player, q):
    while player.haveEnough("nourriture", q) == False:
        i = player.search("nourriture")
        if i == -1:
            player.move("avance")
        else:
            player.foundPathToItem(i)
            player.moveWithPath()
            player.take("nourriture")

def IA(player):
    while player.isAlive():
        msg = player.readMsg()
        if msg == True:
            player.moveWithPath()
        else:
            getFoodToSurvive(player, 5)
            player.getStoneForLevel()
