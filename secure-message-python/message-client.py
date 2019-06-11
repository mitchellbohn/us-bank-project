#! /usr/bin/python3
import Crypto
from Crypto.PublicKey import RSA
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = "127.0.0.1"
port = 5555
s.connect((host,port))

def ts(str):
   s.send(r.encode())
   data = ''
   data = s.recv(1024).decode()
   print (data)


r=''
while r!='!':
   r = input('Enter your message (! to quit): ')
   ts(r)

s.close ()
