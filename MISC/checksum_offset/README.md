# Solution

---

## Step 1 — Don’t overthink the checksum

You’re given two files:

- `data.bin`
- `checksum.txt`

At first, it looks like a normal checksum challenge.  
But notice something weird:

The checksum is never used to *verify* anything. That’s your hint.

---

## Step 2 — Calculate the checksum anyway

Follow the steps in `checksum.txt`.

When you do it correctly, you get:

```
0x9f
```

Convert it to decimal:

```
0x9f = 159
```

Keep this number. It matters.

---

## Step 3 — What does 159 actually mean?

The instructions say something like:

> “The remainder contains the meaningful content”

That doesn’t mean *decrypt everything*.

Instead, think of the file like this:

- Most of it is junk
- Only **some bytes matter**
- The checksum tells you **which ones**

---

## Step 4 — Read the file using the checksum

Use `159` as a step size.

That means:

- Take 1 byte
- Skip 158 bytes
- Take the next byte
- Repeat

Now the file starts making sense.

---

## Step 5 — Extract the flag (script way)

```python
data = open("data.bin", "rb").read()
stride = 159

flag = bytes(
    data[i] for i in range(stride - 1, len(data), stride)
)

print(flag.decode())
```

This prints the flag.

---

## Step 6 — No-script way (manual)

If you don’t want to script:

- Open the file in a hex editor
- Jump to byte `0x9f`
- Write down that byte
- Jump another `0x9f` bytes
- Repeat

Eventually, readable text appears.

---

## Flag

```
flag{offsets_are_powerful}
```
