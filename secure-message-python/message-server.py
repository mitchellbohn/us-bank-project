import Crypto
from Crypto.PublicKey import RSA
from Crypto import Random
import socket


#Generate Public And Private Keys
random_generator = Random.new().read

#bits need to be at least 1024
key = RSA.generate(4096, random_generator)
pubkey = key.publickey().exportKey('PEM')

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = "127.0.0.1"
port = 5555
serversocket.bind((host, port))

serversocket.listen(5)
print ('server started and listening')
(clientsocket, address) = serversocket.accept()
print ("connection found!")
clientsocket.send(pubkey)


while True:
    data = clientsocket.recv(4096).decode()
    if data=='!':
        break
    print(data)
    data = int(data)
    decrypted = key.decrypt(data)
    print (decrypted)
    r='Recieved!'
    clientsocket.send(r.encode())
clientsocket.close()
