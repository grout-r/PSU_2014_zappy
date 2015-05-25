#!/usr/bin/python           

import socket
import sys

if len(sys.argv) != 2:
   print "Need a port"
   sys.exit()

s = socket.socket()
host = "127.0.0.1"
port = int(sys.argv[1])
s.bind((host, port))

print 'host: {} port: {}'.format(host, port)
s.listen(5)
c, addr = s.accept()
c.settimeout(0.5)
print 'Got connection from', addr
while True:
   try:
      print c.recv(4096)
   except timeout:
      c.send(raw_input("response: "))
