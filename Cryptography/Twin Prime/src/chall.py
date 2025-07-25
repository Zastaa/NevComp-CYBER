from Crypto.Util.number import *

FLAG = b"FLAG{FAKE_FLAG}"

p = getPrime(512)

n = p * p
e = 65537

m = bytes_to_long(FLAG)
c = pow(m, e, n)

print(f"c = {c}")
print(f"e = {e}")
print(f"n = {n}")