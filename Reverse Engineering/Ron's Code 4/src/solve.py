def simple_rc4(data: bytes, key: bytes) -> bytes:
    S = list(range(256))
    j = 0
    out = []

    # KSA - Key Scheduling Algorithm
    for i in range(256):
        j = (j + S[i] + key[i % len(key)]) % 256
        S[i], S[j] = S[j], S[i]

    # PRGA - Pseudo-Random Generation Algorithm
    i = j = 0
    for byte in data:
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        K = S[(S[i] + S[j]) % 256]
        out.append(byte ^ K)

    return bytes(out)

with open("flag.enc", "rb") as f:
    enc_data = f.read()

key = b"rc4isthekey"

dec_data = simple_rc4(enc_data, key)

print("Decrypted flag:")
print(dec_data)
