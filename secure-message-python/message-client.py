import Crypto
from Crypto.PublicKey import RSA
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = "127.0.0.1"
port = 5555
s.connect((host,port))

pubkey = s.recv(4096)

key = RSA.importKey(pubkey)

r=''
while r!='!':
    r = input('Enter your message (! to quit): ')
    if r=='!':
        s.send(r.encode())
        break
    a = len(r)
    r = int(r)
    encrypt = key.encrypt(r,a)
    encrypted = str(encrypt[0])
    s.send(encrypted.encode())
    data = s.recv(4096).decode()
    print(data)

s.close ()
