# Substitution cipher

Projet réalisé dans le cadre du CS50x d’Harvard.

## Utilisation

Usage: ./substitution key (the 26 letters of the alphabet, randomized, no duplicates)

- **Plaintext** : enter the text you want to encrypt
- **ciphertext** : your text encrypted with the key you gave

```
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ
```

Note : Preserves the case and other symbols

```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  Hello, world
ciphertext: Jrssb, ybwsp
```