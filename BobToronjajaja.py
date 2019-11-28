# Description of this example is provided in NTRU.md

from ntru import *

#Bob
print "Bob generara sus parametros usados para su clave publica"
print "N=7,p=29 and q=491531"
Bob=Ntru(7,29,491531)
f=[1,1,-1,0,-1,1]
g=[-1,0,1,1,0,0,-1]
d=2
print "f(x) = ",f
print "g(x) = ",g
print "d = ",d
Bob.genPublicKey(f,g,2)
pub_key=Bob.getPublicKey()
print "Clave Publica Generada por Bob: ",pub_key
print "-------------------------------------------------"
#Alice
Alice=Ntru(7,29,491531)
Alice.setPublicKey(pub_key)
msg=[1,0,1,0,1,1,1]
print "Mensaje Original de Alice   : ",msg
ranPol=[-1,-1,1,1]
print "Polinomio Aleatorio de Alice  : ",ranPol
encrypt_msg=Alice.encrypt(msg,ranPol)
print "Mensaje CIfrado         : ", encrypt_msg
print "-------------------------------------------------"
#BOB
print "Bob decifra el mensaje que le fue enviado"
print "Mensaje Decifrado        : ", Bob.decrypt(encrypt_msg)

