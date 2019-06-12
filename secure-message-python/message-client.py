#! /usr/bin/python3
import Crypto
from Crypto.PublicKey import RSA
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = "127.0.0.1"
port = 5555
s.connect((host,port))

def ts(str):
    s.send(encrypted.encode())
    data = ''
    data = s.recv(1024).decode()
    print(data)

pubkey = s.recv(1024)
print(pubkey)

key = RSA.importKey(pubkey)
print(key)

r=''
while r!='!':
    r = input('Enter your message (! to quit): ')
    r = int(r)
    print(r)
    encrypt = key.encrypt(r, 32)
    encrypted = str(encrypt[0])
    print(encrypted)
    ts(encrypted)

s.close ()
