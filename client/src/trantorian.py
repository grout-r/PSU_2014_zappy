#!/usr/bin/python2

import sys

class Trantorian:
    """AI class for zappy project"""

    levTab = [{"joueur":1,"linemate":1,"deraumere":0,"sibur":0,
               "mendiane":0,"phiras":0,"thystame":0}, 
              {"joueur":2,"linemate":1,"deraumere":1,"sibur":1,
               "mendiane":0,"phiras":0,"thystame":0},
              {"joueur":2,"linemate":2,"deraumere":0,"sibur":1,
               "mendiane":0,"phiras":2,"thystame":0},
              {"joueur":4,"linemate":1,"deraumere":1,"sibur":2,
               "mendiane":0,"phiras":1,"thystame":0},
              {"joueur":4,"linemate":1,"deraumere":2,"sibur":1,
               "mendiane":3,"phiras":0,"thystame":0},
              {"joueur":6,"linemate":1,"deraumere":2,"sibur":3,
               "mendiane":0,"phiras":1,"thystame":0},
              {"joueur":6,"linemate":2,"deraumere":2,"sibur":2,
               "mendiane":2,"phiras":2,"thystame":1}]

    soundTab = {0:"",
                1:"avance",
                2:"avance gauche avance",
                3:"gauche avance",
                4:"gauche avance gauche avance",
                5:"droite droite avance",
                6:"droite avance droite avance",
                7:"droite avance",
                8:"avance droite avance"}

    def __init__(self, client, sock):
        self.__client = client
        self.__sock = sock
        self.__alive = True
        self.__level = 1
        self.__invent = []
        self.__vision = []
        self.__msgStack = []
        self.__path = []

    def __del__(self):
        self.__sock.close()

    def introduce(self):
        """Return true if the client can discuss with the server.
        Return false otherwise"""
        resp = self.__sock.recv(4096)
        if not resp:
            return False
        self.__sock.send("{0}\n".format(self.__client[0]))
        resp = self.__sock.recv(4096)
        if not resp:
            return False
        try:
            nb = int(resp)
        except ValueError:
            return False
        if nb < 1:
            return False
        resp = self.__sock.recv(4096)
        if not resp:
            return False
        return True

    def isAlive(self):
        return self.__alive

    def __getServMsg(self):
        resp = self.__sock.recv(4096)
        if not resp:
            sys.exit(1)
        for i in resp.strip('\n').split('\n'):
            if i == "mort":
                self.__alive = False
                sys.exit(0)
            self.__msgStack.append(i)

    def __broadcast(self, msg):
        isBroad = False
        self.__sock.send("broadcast {0}\n".format(msg))
        while isBroad != True:
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg == "ok" or msg == "ko":
                    isBroad= True
                    self.__msgStack.pop(self.__msgStack.index(msg))

    ### Inventory functions

    def __inventory(self):
        self.__invent = []
        isInventory = False
        self.__sock.send("inventaire\n")
        while isInventory != True :
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg and msg[0] == '{' and msg[-1] == '}':
                    isInventory = True
                    self.__msgStack.pop(self.__msgStack.index(msg))
        for item in msg.strip("{}\n").split(","):
            self.__invent.append(item.strip())

    def haveEnough(self, item, minToHave):
        self.__inventory()
        for i in self.__invent:
            if item in i:
                try:
                    nb = int(i.split()[1])
                except IndexError:
                    return False
                if nb >= minToHave:
                    return True
                else:
                    return False
        return False

    def take(self, item):
        isTaken = False
        self.__sock.send("prend {0}\n".format(item))
        while isTaken != True:
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg == "ok" or msg == "ko":
                    isTaken = True
                    self.__msgStack.pop(self.__msgStack.index(msg))

    def put(self, item):
        isPut = False
        self.__sock.send("pose {0}\n".format(item))
        while isPut != True:
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg == "ok" or msg == "ko":
                    isPut = True
                    self.__msgStack.pop(self.__msgStack.index(msg))

    ### Vision functions
    
    def __see(self):
        self.__vision = []
        isVision = False
        self.__sock.send("voir\n")
        while isVision != True:
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg and msg[0] == '{' and msg[-1] == '}':
                    isVision = True
                    self.__msgStack.pop(self.__msgStack.index(msg))
        for item in msg.strip("{}\n").split(","):
            self.__vision.append(item.strip())

    def search(self, itemToSearch):
        self.__see()
        for i in self.__vision:
            for item in i.split():
                if item == itemToSearch:
                    return self.__vision.index(i)
        return -1

    ## Move functions

    def move(self, direction):
        moved = False
        tab = {"gauche":"gauche", "avance":"avance", "droite":"droite"}
        try:
            self.__sock.send("{0}\n".format(tab[direction]))
            while moved != True:
                self.__getServMsg()
                for msg in self.__msgStack:
                    if msg == "ok":
                        moved = True
                        self.__msgStack.pop(self.__msgStack.index(msg))
        except KeyError:
            pass

    def __checkLeft(self, indexToItem, currentPos, inc):
        if indexToItem >= currentPos - (inc / 2) and indexToItem < currentPos:
            self.__path.append("gauche")
            while currentPos != indexToItem:
                self.__path.append("avance")
                currentPos -= 1
            return True
        return False

    def __checkRight(self, indexToItem, currentPos, inc):
        if indexToItem > currentPos and indexToItem <= currentPos + (inc / 2):
            self.__path.append("droite")
            while currentPos != indexToItem:
                self.__path.append("avance")
                currentPos += 1
            return True
        return False

    def foundPathToItem(self, indexToItem):
        inc = 0
        pos = 0
        found = False
        while found is False:
            if pos == indexToItem:
                found = True
            if self.__checkRight(indexToItem, pos, inc) or self.__checkLeft(indexToItem, pos, inc):
                found = True
            if found != True:
                self.__path.append("avance")
            inc += 2
            pos += inc

    def moveWithPath(self):
        for i in self.__path:
            self.move(i)
        self.__path = []

    ## Msg functions

    def sendIncantMsg(self):
        nPlayer = 0
        self.__see()
        for item in self.__vision[0].split():
            if item == "joueur":
                nPlayer += 1
        if self.levTab[self.__level - 1]["joueur"] - nPlayer > 0:
            self.__broadcast("{0} {1} {2}".format(
                self.__client[0], self.__level + 1, self.levTab[self.__level - 1]["joueur"] - nPlayer))
        else:
            self.incant()

    def readMsg(self):
        for i in self.__msgStack:
            msg = self.__msgStack.pop(self.__msgStack.index(i))
            print msg
            if msg == "elevation en cours":
                levelUp = False
                while levelUp != True :
                    self.__getServMsg()
                    for msg in self.__msgStack:
                        if msg.split(" : ")[0] == "niveau actuel":
                            levelUp = True
                            self.__level = int(msg.split(" : ")[1])
                            self.__msgStack.pop(self.__msgStack.index(msg))
            elif msg.split(",")[1].split()[0] == self.__client[0] and int(msg.split(",")[1].split()[1]) - 1 == self.__level:
                print msg
                for i in self.soundTab[int(msg.split(",")[0].split()[1])].split():
                    print i
                    self.__path.append(i)
                return True
            break
        return False

    ## Incant functions

    def __checkEmptySquare(self):
        self.__see()
        for i in self.__vision[0].split():
            if i != "joueur":
                return False
        return True

    def __emptySquare(self):
        for i in self.__vision[0].split():
            if i != "joueur" and i != "nourriture":
                self.take(i)

    def __putStuffForIncant(self):
        for i in self.levTab[self.__level - 1]:
            if i == "joueur":
                continue
            for nb in range(0, self.levTab[self.__level - 1][i]):
                self.put(i)

    def incant(self):
        if self.__checkEmptySquare() == False:
            self.__emptySquare()
        self.__putStuffForIncant()
        self.__sock.send("incantation\n")
        levelUp = False
        isIncant = False
        while levelUp == False or isIncant == False:
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg == "elevation en cours":
                    isIncant = True
                    self.__msgStack.pop(self.__msgStack.index(msg))
                if msg.split(" : ")[0] == "niveau actuel":
                    levelUp = True
                    self.__level = int(msg.split(" : ")[1])
                    self.__msgStack.pop(self.__msgStack.index(msg))

    def __canLevelUp(self):
        for i in self.levTab[self.__level - 1]:
            if i == "joueur":
                continue
            if self.haveEnough(i, self.levTab[self.__level - 1][i]) == False:
                return False
        return True

    def getStoneForLevel(self):
        if self.__canLevelUp() == False:
            self.__see()
            for i in self.__vision:
                for item in i.split():
                    if item == "joueur" or item == "nourriture":
                        continue
                    if self.haveEnough(item, self.levTab[self.__level - 1][item]) == False:
                        self.foundPathToItem(self.__vision.index(i))
                        self.moveWithPath()
                        self.take(item)
                        break
            self.move("avance")
        else:
            self.sendIncantMsg()
