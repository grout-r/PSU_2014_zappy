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
        getFoodToSurvive(player, 5)
        if player.readMsg() == True:
            print "Je vais a l'incant"
            player.moveWithPath()
        else:
            player.getStoneForLevel()
