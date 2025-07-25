from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad, pad
from Crypto.Random import get_random_bytes


with open("Kucing.png", "rb") as f:
    data = f.read()

key = get_random_bytes(16)
iv = get_random_bytes(16)

cipher = AES.new(key, AES.MODE_CBC, iv)
ciphertext = cipher.encrypt(pad(data, AES.block_size))

with open("kucing_encrypted", "wb") as f:
    f.write(iv + ciphertext + key)