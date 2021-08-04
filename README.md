# 103cipher
# {EPITECH} | First year | Math project

Cryptography is a very old science, whose goal is to secure communication, so that only its recipient could read it.

There are a lot of methods to encrypt a message, from the simplest (such as the 2,000-year-old Caesar cipher) to the most complex (such as the World War 2 Enigma code).
they all need both encryption and decryption keys (sometimes identical).

In some cases (such as the Hill cipher), the key is represented by a matrix.

You have to carry out such a matrix-based ciphering software, using the following process to encrypt :

  - Transcript the key into numbers using the ASCII table,
  - Convert the numbered key into a square matrix, the smallest possible size, and filling the lines first,
  - Transcript the clear message into numbers using the ASCII table,
  - Convert the numbered message into a matrix; its number of columns should fit the key matrix size, and its number of lines should be as small as possible.
  - Multiply the 2 matrices, and write the answer linearly to get the encrypted message.
  
The decryption process logically follows from the previous encryption method, using the same key (be careful! You need to inverse the key matrix, which is not always possible).

See the subject for further details !

========================

## 1st semester Maths unit

Grade : A | Mark : 20

| Category                  | Percentage | Tests | Crash ? |
|---------------------------|------------|-------|---------|
| Rigor                     | 100%      | 7/7   | x       |
| Matrix                    | 100%       | 8/8   | x       |
| Encryption                | 100%       | 8/8   | x       |
| Decryption                | 100%      | 6/6   | x       |
| Decryption size > 3 (Bonus) | 100%         | 2/2   | x       |
| Encryption size > 3 (Bonus) | 100%         | 2/2   | x       |
| **End scores**                | **100%**        | **31/31** | **No**      |
