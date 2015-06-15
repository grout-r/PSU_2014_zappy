#!/usr/bin/python2

import sys, getopt, socket

def usage():
    print 'usage: {} [-n equip name][-p port][-h server IP]'.format(sys.argv[0])
    sys.exit(2)

def getArgs(argv):
    client = ['', '', '']
    try:
        opts, args = getopt.getopt(argv, 'n:p:h:')
    except getopt.GetoptError:
        usage()
    for opt, arg in opts:
        if opt == '-n':
            client[0] = arg
        elif opt == '-p':
            client[1] = arg
        elif opt == '-h':
            client[2] = arg
        else:
            usage()
    if not client[0] or not client[1] or not client[2]:
        usage()
    return client

def connect(info):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        sock.connect((info[2], int(info[1])))
    except socket.error:
        print "Can't connect to server {} and port {}".format(info[2], info[1])
        sys.exit(2)
    return sock
