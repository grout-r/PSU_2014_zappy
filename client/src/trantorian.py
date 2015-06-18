#!/usr/bin/python2

import sys

class Trantorian:
    """AI class for zappy project"""

    def __init__(self, client, sock):
        self.__client = client
        self.__sock = sock
        self.__alive = True
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
        print resp,
        self.__sock.send("{0}\n".format(self.__client[0]))
        resp = self.__sock.recv(4096)
        if not resp:
            return False
        print resp,
        try:
            nb = int(resp)
        except ValueError:
            return False
        if nb < 1:
            return False
        resp = self.__sock.recv(4096)
        if not resp:
            return False
        print resp,
        return True

    def isAlive(self):
        return self.__alive

    def __getServMsg(self):
        resp = self.__sock.recv(4096)
        if not resp:
            sys.exit(1)
        for i in resp.strip('\n').split('\n'):
            print "J'ajoute \"{0}\" a la stack de message".format(i)
            if i == "mort":
                self.__alive = False
                sys.exit(0)
            self.__msgStack.append(i)
        print self.__msgStack

    def flush(self):
        self.__invent = []
        self.__vision = []

    def broadcast(self, msg):
        self.__sock.send("broadcast {0}\n".format(msg))

    ### Inventory functions

    def __inventory(self):
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
            print "Ajoute gauche"
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
        print self.__path

    def moveWithPath(self):
        for i in self.__path:
            self.move(i)
        self.__path = []
