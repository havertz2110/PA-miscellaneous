//openssl x509 -in certificate.crt -outform PEM -out certificate.pem
//openssl x509 -in certificate.crt -outform PEM -out certificate.der
#include "cryptopp/cryptlib.h"
#include "cryptopp/x509cert.h"
#include "cryptopp/secblock.h"
#include "cryptopp/filters.h"
#include "cryptopp/rsa.h"
#include "cryptopp/sha.h"
#include "cryptopp/hex.h"
#include "cryptopp/pem.h"
#include "cryptopp/files.h"

#include <iostream>

#include "keyFile.h"
using namespace CryptoPP;


using namespace std;

string certFile;

int main(int argc, char* argv[]){
    if(argc == 1){
        cout << "Please enter the certificate file name as .crt file" << endl;
        cin >> certFile;
    }else{
        certFile = string(argv[1]);
    }
    X509Certificate cert;
    loadCert(certFile, cert);
    cert.Print(cout);
    RandomNumberGenerator rng;
    if(cert.Validate(rng , 1) == false){
        cout << "\n--------\n It is invalid" << endl;
        return 0;
    }else{
        cout << "\n--------\nCertificate is valid" << endl;
    }
}