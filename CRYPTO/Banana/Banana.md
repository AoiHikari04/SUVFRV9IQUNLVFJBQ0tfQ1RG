# Question


- make sure to include AES-GCM encryption method

# Solution

## Step 1, extract the banana peel

- Given a banana(PDF)
- Extract the banana peel, as mean try to find the hidden file inside the pdf which will give the use new key

## Step 2, use the banana to extract the peel

- .enc file given is a simple sha256 encryption which requires key  to extract
- use the key that you got from the banana before (pdf) and make a script to extract the file using the encryption
- Below is an example code generated using GPT to get the code

```python

from Crypto.Cipher import AES
import base64
import sys
import os

def decrypt_file(enc_filename, key_b64):
    
    # Decode the key
    try:
        key = base64.urlsafe_b64decode(key_b64)
    except Exception as e:
        print(f"Error decoding the key: {e}, make sure it base 64 encoded")
        return

    # READ the encrypted file
    with open(enc_filename, 'rb') as f:
        data = f.read()

    nonce = data[:12]
    tag = data[12:28]
    ciphertext = data[28:]

    try:
        cipher = AES.new(key, AES.MODE_GCM, nonce=nonce)
        plaintext = cipher.decrypt_and_verify(ciphertext, tag)
    except ValueError:
        print("Error: The key is incorrect or the file has been tampered with.")
        return

    # WRITE the decrypted file
    dec_filename = enc_filename.replace('.enc', '.decrypted')
    with open(dec_filename, 'wb') as f:
        f.write(plaintext)

    print(f"✅ File decrypted and saved as: {dec_filename}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python decrypt.py <encrypted_file> <key_b64>")
        sys.exit(1)

    enc_filename = sys.argv[1]
    key_b64 = sys.argv[2]

    if not os.path.exists(enc_filename):
        print(f"Error: File '{enc_filename}' does not exist.")
        sys.exit(1)

    decrypt_file(enc_filename, key_b64)

```


# Step 3, Extracting the flag

The user will then get a long text file, it simple just find the longest string that resembles the based64 string

decode it and then will get the flag

```
IHT{TryHard_But_it_quite_EZ}
```