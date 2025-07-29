#ifndef __KEYFILE_H__
#define __KEYFILE_H__

#include "cryptopp/rsa.h"
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSA;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
// phai xai sha256

#include "cryptopp/sha.h"
using CryptoPP::SHA1;
using CryptoPP::SHA256;

#include "cryptopp/filters.h"
using CryptoPP::PK_DecryptorFilter;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/cryptlib.h"
using CryptoPP::BufferedTransformation;
using CryptoPP::DecodingResult;
using CryptoPP::Exception;

#include <string>
using std::string;

#include <exception>
using std::exception;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;

#include "cryptopp/pem.h"
using CryptoPP::PEM_Load;
using CryptoPP::PEM_Save;

#include "cryptopp/x509cert.h"
using CryptoPP::X509Certificate;

#include <assert.h>

void loadCertUtil(const string& filename, BufferedTransformation& bt)
{
    FileSource file(filename.c_str(), true /*pumpAll*/);
    file.TransferTo(bt);
    bt.MessageEnd();
}

void loadCert(const string& filename, X509Certificate& cert)
{
    if (filename.find(".pem") != string::npos)
    {
        string str;
        FileSource file(filename.c_str(), true /*pumpAll*/);
        PEM_Load(file, cert);
        return;
    }
    else
    {
        ByteQueue queue;
        loadCertUtil(filename, queue);
        cert.BERDecode(queue);
    }
}

#endif