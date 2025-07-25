from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad, pad

with open("kucing_encrypted", "rb") as f:
    data = f.read()
    iv = data[:16]
    key = data[-16:]
    enc = data[16:-16]

cipher = AES.new(key, AES.MODE_CBC, iv)
plaintext = unpad(cipher.decrypt(enc), AES.block_size)


with open("recovered.png", "wb") as f:
    f.write(plaintext)