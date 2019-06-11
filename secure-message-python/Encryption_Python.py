import Crypto
from Crypto.PublicKey import RSA
from Crypto import Random

#Generate Public And Private Keys
random_generator = Random.new().read

#bits need to be at least 1024
key = RSA.generate(4096, random_generator)

publickey = key.publickey()
print(publickey)
print(key)

#Get Message
message = input("Enter Message: \n")

#Get Length of Message
length=len(message)

#Set Arrays to Size of Message
decoded_string = [""] * length
asc = [0] * length
encrypted = [0] * length
decrypted = [0] * length

i = 0

#Convert to ASCII
while (i<length):
    asc[i]=ord(message[i])
    i=i+1

i=0

#Encrypt Message
while(i<length):
    encrypted[i] = publickey.encrypt(asc[i],length)
    i=i+1

print(encrypted)

i=0

#Decrypt Message
while(i<length):
    decrypted[i] = key.decrypt(encrypted[i])
    i=i+1

print(decrypted)

i=0

#Converts Message back
while(i<length):
    decoded_string[i]=chr(asc[i])
    i=i+1

#Puts Character Back Together
decoded_message="".join(decoded_string)

#Prints Decoded Message
print(decoded_message)
