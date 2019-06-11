import Crypto
from Crypto.PublicKey import RSA
from Crypto import Random
import socket


#Generate Public And Private Keys
random_generator = Random.new().read

#bits need to be at least 1024
key = RSA.generate(4096, random_generator)


serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = "127.0.0.1"
port = 5555
print (host)
print (port)
serversocket.bind((host, port))

data=''
while data!='!':
    serversocket.listen(5)
    print ('server started and listening')
    (clientsocket, address) = serversocket.accept()
    print ("connection found!")
    data = clientsocket.recv(1024).decode()
    print (data)
    r='Recieved!'
    clientsocket.send(r.encode())
