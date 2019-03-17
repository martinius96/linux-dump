Build origo program
-----

    $ gcc hashchain.c -o hashchain -lcrypto
    
Build moj program
-----

    $ gcc main.c -o main -lcrypto
Run
---

### Create hash chain:

    $ ./hashchain create 256 10 "a"
 
### Verify
    $ ./hashchain verify sha256 gjZmdTdMNnijpZd0hhkxJSK9/IywQIQ2H5N2BiWC6w0= 5o/+3BTbOTebzIJGTI0bZPorFatbV1zu070qBSx3Z0k=
    VYSTUP: success

# POTREBUJEM V MAIN.C UROBIT TOTO:
* Pouzivatel zada algoritmus (sha1, alebo sha256, alebo sha512)
* Dlzku (napr: 10)
* Server vygeneruje dlzku 10 
* Pouzivatel vygeneruje dlzku 9
* Cez verify sa overi hash pouzivatela a servera
* Access
