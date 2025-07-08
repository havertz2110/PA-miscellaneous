#include <iostream>
#include <string>
using std::string;
using std::wstring;
using std::cin;
using std::cout;
using std::endl;
#include <string.h>
#include <stdio.h>
using std::wcin;
using std::wcout;
using std::wcerr;
using std::endl;
using std::cout;
using std::cerr;
using std::cin;
#include <cstdlib>
using std::exit;
#include "assert.h"
using std::ifstream;
using std::ofstream;
using std::wifstream;
using std::wofstream;
using std::getline;
using std::ws;
#include <assert.h>
#include <locale>
using std::wstring_convert;
#include <codecvt>
using  std::codecvt_utf8;

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#endif
#include "cryptopp/shake.h" // support for shake
#include <locale>


#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;
using CryptoPP::DecodingResult;


#include "cryptopp/sha3.h"
#include "cryptopp/sha.h"
#include "cryptopp/shake.h"

#include "cryptopp/files.h"
using CryptoPP::FileSink;

#include <exception>
using std::exception;


#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;


using namespace CryptoPP;


wstring string_to_wstring (const std::string& str);
string wstring_to_string (const std::wstring& str);

int main (int argc, char* argv[]){
    #ifdef __linux__
	setlocale(LC_ALL, "");
    #elif _WIN32
        _setmode(_fileno(stdin), _O_U16TEXT);
        _setmode(_fileno(stdout), _O_U16TEXT);
    #else
    #endif
    wstring wmsg;
    string msg;
	wcout << "How do you want to input message:\n"
		  << "1. input from screen\n"
		  << "2. input from file (using file name)\n"
		  << "Please enter your number?\n";
	int input_mode;
	wcin >> input_mode;
	wcin.ignore();
	switch (input_mode){
		case 1:{
			wcout << "Hehe give me what you want to hash:  ";
			wcin.ignore();
			getline(wcin, wmsg);
			wcin.ignore();
			msg = wstring_to_string(wmsg);
			break;
		}
		case 2:{
			wstring wfile_path;
			wcout << L"Enter your message file name please: ";
			wcin.ignore();
			getline(wcin, wfile_path);

			string file_path = wstring_to_string(wfile_path);
			string text;

			ifstream MyReadFile(file_path);

			if (!MyReadFile.is_open()) {
				wcout << "Huhu there is something weird in the file, i can not open it :( " << endl;
				exit(1);	
			} else{
				if (getline(MyReadFile, text)) {
					msg = text;
					wcout << L"Here is what in the file, make sure check it: " << string_to_wstring(msg) << endl;
				} else{
					wcout << L"Check the file again :( there is sth not gud :(" << endl;
					exit(1);
				}
					MyReadFile.close();
			}
			break;
		}
	}

    wcout   << "How do you want to hash your message:\n"
            << "1. SHA224\n"
            << "2. SHA256\n"
            << "3. SHA384\n"
            << "4. SHA512\n"
            << "5. SHA3-224\n"
            << "6. SHA3-256\n"
            << "7. SHA3-384\n"
            << "8. SHA3-512\n"
            << "9. SHAKE128\n"
            << "10. SHAKE256\n"
            << "Please enter your number?\n";
    int hash_type;
    wcin >> hash_type;
    wcin.ignore();

    switch(hash_type){
        case 1:{
            SHA224 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 2:{
            SHA256 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 3:{
            SHA384 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 4:{
            SHA512 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 5:{
            SHA3_224 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 6:{
            SHA3_256 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 7:{
            SHA3_384 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;           
            break;
        }
        case 8:{
            SHA3_512 hash;  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));

            wcout <<string_to_wstring(encoded) <<std::endl;
            break;
        }
        case 9:{
            int digestLength;
            wcout << "Enter your desired digest length for SHAKE128: ";
            wcin >> digestLength;

            SHAKE128 hash(digestLength);  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            digest.resize(digestLength / 2);  // Adjusting the size based on user input

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));
            wcout <<string_to_wstring(encoded) <<std::endl;           
            break;
        }
        case 10:{
           int digestLength;
            wcout << "Enter your desired digest length for SHAKE128: ";
            wcin >> digestLength;

            SHAKE256 hash(digestLength);  
            string algorithmName = hash.AlgorithmName();
            wcout << "Name: " << string_to_wstring(algorithmName) << endl;
            int digestSize = hash.DigestSize();
            wcout << "Digest size: " << digestSize  << endl;
            int blockSize = hash.BlockSize();
            wcout << "Block size: " << blockSize << endl;

            wcout << "Message: " << string_to_wstring(msg) << endl;

            string digest;
            string encoded;
            hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
            digest.resize(hash.DigestSize());
            hash.Final((CryptoPP::byte*)&digest[0]);

            digest.resize(digestLength / 2);  // Adjusting the size based on user input

            wcout << "Digest: ";
            StringSource(digest, true, new HexEncoder(new StringSink(encoded)));
            wcout <<string_to_wstring(encoded) <<std::endl;           
            break;
        }
        default:{
            wcout << L"Invalid hash type, please check again :(" << endl;
            exit(1);
        }
    }

    return 0; 
}
string wstring_to_string(const wstring &str){
	wstring_convert<codecvt_utf8<wchar_t>> tostring;
	return tostring.to_bytes(str);
}

wstring string_to_wstring(const string &str){
	wstring_convert<codecvt_utf8<wchar_t>> towstring;
	return towstring.from_bytes(str);
}