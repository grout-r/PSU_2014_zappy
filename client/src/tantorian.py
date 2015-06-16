#!/usr/bin/python2

import sys

class Tantorian:
    """AI class for zappy project"""

    def __init__(self, client, sock):
        self.__client = client
        self.__sock = sock
        self.__alive = True
        self.__inventaire = []
        self.__vision = []
        self.__msgStack = []

    def __del__(self):
        self.__sock.close()

    def introduce(self):
        """Return true if the client can discuss with the server.
        Return false otherwise"""
        resp = self.__sock.recv(4096)
        if not resp:
            return False
        print resp,
        self.__sock.send("{0}\n".format(self.getTeam()))
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

    def getTeam(self):
        return self.__client[0]

    def getHunger(self):
        return 0

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
        self.__inventaire = []
        self.__vision = []

    def move(self, direction):
        tab = {"gauche":"gauche", "avance":"avance", "droite":"droite"}
        self.__sock.send("{0}\n".format(tab[direction]))

    def broadcast(self, msg):
        self.__sock.send("broadcast {0}\n".format(msg))

    ### Inventory functions

    def __inventory(self):
        isInventaire = False
        self.__sock.send("inventaire\n")
        while isInventaire != True :
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg and msg[0] == '{' and msg[-1] == '}':
                    isInventaire = True
                    self.__msgStack.pop(self.__msgStack.index(msg))
        for item in msg.strip("{}\n").split(","):
            self.__inventaire.append(item.strip())

    def haveEnough(self, item, minToHave):
        self.__inventory()
        for i in self.__inventaire:
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

    def take(self, item):
        isTaken = False
        self.__sock.send("prend {0}\n".format(item))
        while isTaken != True:
            self.__getServMsg()
            for msg in self.__msgStack:
                if msg == "ok" or msg == "ko":
                    isTaken = True
                    self.__msgStack.pop(self.__msgStack.index(msg))
