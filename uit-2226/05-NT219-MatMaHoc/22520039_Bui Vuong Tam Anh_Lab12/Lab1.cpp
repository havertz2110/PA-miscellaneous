#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cerr;
using std::endl;
using std::wcin;

using std::wcout;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::wstring;

/* Convert string*/
#include <locale>
using std::wstring_convert;
#include <codecvt>
using std::codecvt_utf8;

#include <cstdlib>
using std::exit;

#include <cryptopp/files.h>
using CryptoPP::BufferedTransformation;
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/cryptlib.h"
using CryptoPP::byte;
using CryptoPP::Exception;

#include "cryptopp/hex.h"
using CryptoPP::HexDecoder;
using CryptoPP::HexEncoder;

#include "cryptopp/filters.h"
using CryptoPP::Redirector;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "cryptopp/aes.h"
using CryptoPP::AES;
#include <cryptopp/modes.h>
#include "cryptopp/ccm.h"
using namespace CryptoPP;
#include <cryptopp/gcm.h>
#include <cryptopp/xts.h>
#include "assert.h"

/* Set _setmode()*/
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#else
#endif

using namespace CryptoPP;

string wstring_to_string(const wstring &str);
wstring string_to_wstring(const string &str);

void hex_to_byte(string& input)
{
    string decoded;

    StringSource(input, true, 
		new HexDecoder(
			new StringSink(decoded)
		) // HexEncoder
	); // StringSource
    

    input = decoded;
   
}

int main(int argc, char *argv[]){
#ifdef __linux__
	setlocale(LC_ALL, "");
#elif _WIN32
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
#else
#endif
    AutoSeededRandomPool prng;
    SecByteBlock key(AES::MAX_KEYLENGTH);
    CryptoPP::byte iv[AES::BLOCKSIZE];

string cipher, encoded, recovered;
int enc_or_dec;
wcout << "How would you like to do it:\n"
                     << "1. encrypt;\n"
                     << "2. decrypt;\n"
                     << "Please enter your number:";
wcin >> enc_or_dec;
wcin.ignore();
wstring wplain;
string plain;
		
switch( enc_or_dec){
	case 1:{ // encryption here
		// enter plaintext
		wcout << "How do you want to input plaintext:\n"
			<< "1. input from screen\n"
			<< "2. input from file (using file name)\n"
			<< "Please enter your number?\n";
		int input_mode;
		wcin >> input_mode;
		wcin.ignore();
		switch (input_mode){
			case 1:{
				wcout << "Hehe give me what you want to hide from people sight:  ";
				wcin.ignore();
				getline(wcin, wplain);
				wcin.ignore();
				plain = wstring_to_string(wplain);
				break;
			}
			case 2:{
				wstring wfile_path;
				wcout << L"Enter your plaintext file name please: ";
				wcin.ignore();
				getline(wcin, wfile_path);

				string file_path = wstring_to_string(wfile_path);
				string text;

				ifstream MyReadFile(file_path);

				if (!MyReadFile.is_open()) {
					wcout << "Huhu there is something weird in the file, i can not open it :( " << endl;
					exit(1);
					
				} else {
					if (getline(MyReadFile, text)) {
						plain = text;
						wcout << L"Here is what in the file, make sure check it: " << string_to_wstring(plain) << endl;
					} else {
						wcout << L"Check the file again :( there is sth not gud :(" << endl;
						exit(1);
					}
					MyReadFile.close();
				}

				break;
			}
		}
	// choose input mode for key and iv
	wcout << "How would you like to input key and iv:\n"
                  << "1. randomly chosen by using CryptoPP::AutoSeededRandomPool\n"
                  << "2. input from screen\n"
                  << "3. input from file \n"
                  << "Please enter your number?\n";
	int key_iv_input_mode;
	wcin >> key_iv_input_mode;
	wcin.ignore();
	switch (key_iv_input_mode){
		case 1:{ // random key_iv here
			AutoSeededRandomPool prng;
			prng.GenerateBlock(key, sizeof(key));
			prng.GenerateBlock(iv, sizeof(iv));
			break;
		}
		case 2:{ 
			wcout << "Please input your secret key in hex: ";
            wstring wkey_input;
            wcin >> wkey_input;
            wcin.ignore();
            std::string key_input = wstring_to_string(wkey_input);
            hex_to_byte(key_input);
            key = SecByteBlock(reinterpret_cast<const CryptoPP::byte*>(&key_input[0]), key_input.size());
          
		    wcout << "Please input your iv in hex: ";
            wstring wiv_input;
            wcin >> wiv_input;
            wcin.ignore();
            string iv_input = wstring_to_string(wiv_input);
            string iv_str;
            StringSource(iv_input, true, 
                    new HexDecoder(
                        new StringSink(iv_str)
                    ) // HexDecoder
                ); // StringSource

            memcpy(iv, iv_str.c_str(), sizeof(iv)); 
			
            break;
		}
		case 3:{ // reading key from file
			string temp_key, temp_iv;
			wstring wfile_path;
			string file_path;
			string text;
			wcout << L"Enter your secret key and iv file name please: ";
			wcin.ignore();
			getline(wcin, wfile_path);

			file_path = wstring_to_string(wfile_path);

			ifstream MyReadFile(file_path);

			wcout << L"Here is what in the file, make sure to check it:" << endl;
			int counter = 0;
			while (getline(MyReadFile, text)) {
				wcout << string_to_wstring(text) << endl;

				if (counter == 0) {
					temp_key = text;
				} else if (counter == 1) {
					temp_iv = text;
					break;
				}
				counter++;
			}
			MyReadFile.close();
			
			string key_hex = temp_key;
			string iv_hex = temp_iv;

			string key_str;
			StringSource(key_hex, true, 
				new HexDecoder(
					new StringSink(key_str)
				) // HexDecoder
			); // StringSource
			memcpy(key, key_str.c_str(), sizeof(key));

			string iv_str;
			StringSource(iv_hex, true, 
				new HexDecoder(
					new StringSink(iv_str)
				) // HexDecoder
			); // StringSource
			memcpy(iv, iv_str.c_str(), sizeof(iv));

			break;
			}
		default:
			break;
		}
		int enc_mode;// choose encryption mode
		wcout << "How would you like to do it:\n"
                     << "1. ECB;\n"
                     << "2. CBC;\n"
                     << "3. OFB;\n"
                     << "4. CFB;\n"
                     << "5. CTR;\n"
                     << "6. XTS;\n"
                     << "7. CCM;\n"
                     << "8. GCM;\n"
                     << "Please enter your number:";
        wcin >> enc_mode;
        wcin.ignore();
		string encoded;
		// PROCESSING
		switch (enc_mode){
				case 1:{	
					wcout << "ECB  " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;										
					try{
						ECB_Mode<AES>::Encryption e;
						e.SetKey(the_key, sizeof(the_key));
						StringSource s1(plain, true,
										new StreamTransformationFilter(e,
																	new StringSink(cipher)) // StreamTransformationFilter
						);
						ECB_Mode<AES>::Decryption d;
						d.SetKey(the_key, sizeof(the_key));
						StringSource s2(cipher, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 2:{
					wcout << "CBC " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					try{
						CBC_Mode<AES>::Encryption e;
						e.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s1(plain, true,
										new StreamTransformationFilter(e,
																	new StringSink(cipher)) // StreamTransformationFilter
						);
						CBC_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s2(cipher, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 3:{
					wcout << "OFB " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					try{
						OFB_Mode<AES>::Encryption e;
						e.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s1(plain, true,
										new StreamTransformationFilter(e,
																	new StringSink(cipher)) // StreamTransformationFilter
						);
						OFB_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s2(cipher, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 4:{
					wcout << "CFB " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					try{
						CFB_Mode<AES>::Encryption e;

						e.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s1(plain, true,
										new StreamTransformationFilter(e,
																	new StringSink(cipher)) // StreamTransformationFilter
						);
						CFB_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s2(cipher, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 5:{
					wcout << "CTR " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					try{
						CTR_Mode<AES>::Encryption e;
						e.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s1(plain, true,
										new StreamTransformationFilter(e,
																	new StringSink(cipher)) // StreamTransformationFilter
						);																	   // StringSource
						CTR_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s2(cipher, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 6:{
					wcout << "XTS " << endl;
					XTS<AES>::Encryption e;
					CryptoPP::byte the_key[e.DefaultKeyLength()];
					std::copy(key + 0, key + e.DefaultKeyLength(), the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;								
					try{
						e.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s1(plain, true,
										new StreamTransformationFilter(e,
																	new StringSink(cipher), StreamTransformationFilter::NO_PADDING) // StreamTransformationFilter
						);
						XTS<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s2(cipher, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered), StreamTransformationFilter::NO_PADDING) // StreamTransformationFilter
						);																												  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 7:{
					wcout << "CCM " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					
					byte ccm_iv[13];
					std::copy(iv, iv + 13, ccm_iv);
					const int TAG_SIZE = 12;	// const tag_size

					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					try{
						CCM<AES, TAG_SIZE>::Encryption e;
						e.SetKeyWithIV(the_key, sizeof(the_key), ccm_iv, sizeof(ccm_iv));
						e.SpecifyDataLengths(0, plain.size(), 0);
						StringSource s1(plain, true,
										new AuthenticatedEncryptionFilter(e,
																		new StringSink(cipher)) // StreamTransformationFilter
						);
						CCM<AES, TAG_SIZE>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), ccm_iv, sizeof(ccm_iv));
						d.SpecifyDataLengths(0, cipher.size() - TAG_SIZE, 0);
						StringSource s2(cipher, true,
										new AuthenticatedDecryptionFilter(d,
																		new StringSink(recovered)) // StreamTransformationFilter
						);																			 // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 8:{
					wcout << "GCM " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					try{
						GCM<AES>::Encryption e;
						e.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s1(plain, true,
										new AuthenticatedEncryptionFilter(e,
																		new StringSink(cipher)) // StreamTransformationFilter
						);
						GCM<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s2(cipher, true,
										new AuthenticatedDecryptionFilter(d,
																		new StringSink(recovered)) // StreamTransformationFilter
						);																			 // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				default:{
					break;
				}
				}
			encoded.clear();
			StringSource(cipher, true,
				new HexEncoder(
					new StringSink(encoded)		
				) // HexEncoder
			); // StringSource
			wcout << "cipher text: " << string_to_wstring(encoded) << endl;
			wcout << "Recovered text: " << string_to_wstring(recovered) << endl;
			
			std::ofstream MyWriteFile("ciphertext.txt");

			if (MyWriteFile.is_open()) {
				MyWriteFile << encoded; // Ghi dữ liệu từ chuỗi encoded vào tệp
				MyWriteFile.close();
				wcout << L"cipher text written to ciphertext.txt" << endl;
			} 
			return 0;
	}
	case 2:{ // decryption here
		// enter ciphertext
		wstring wcipher;
		
		wcout << "how do you want to input cipher:\n"
			<< "1. input from screen\n"
			<< "2. input from file\n"
			<< "Please enter your number?\n";
		int input_mode;
		wcin >> input_mode;
		wcin.ignore();
		switch (input_mode){
			case 1:{
				wcout << "Hehe give me your cipher:  ";

				getline(wcin, wcipher);

				cipher = wstring_to_string(wcipher);
				break;
			}
			case 2:{
				wstring wcipher_file_path;
				wcout << L"Enter your cipher text file name: ";
				wcin.ignore();
				getline(wcin, wcipher_file_path);

				string cipher_file_path = wstring_to_string(wcipher_file_path);
				string text;

				ifstream MyReadFile(cipher_file_path);

				if (!MyReadFile.is_open()) {
					wcout << "Huhu there is something sus in the file, I can not open it :( " << endl;
				} else {
					if (getline(MyReadFile, text)) {
						cipher = text;
						wcout << L"Here is what in the file: " << string_to_wstring(cipher) << endl;
					} else {
						wcout << L"Check the file again :( there is something not good :(" << endl;
						exit(1);
					}
					MyReadFile.close();
				}
				break;
			}
		}
// choose input mode for key and iv
	wcout << "How would you like to input key and iv:\n"
                  << "1. randomly chosen by using CryptoPP::AutoSeededRandomPool;\n"
                  << "2. input from screen;\n"
                  << "3. input from file \n"
                  << "Please enter your number?\n";
	int key_iv_input_mode;
	wcin >> key_iv_input_mode;
	wcin.ignore();
	switch (key_iv_input_mode){
		case 1:{ // random key_iv here
			AutoSeededRandomPool prng;
			prng.GenerateBlock(key, sizeof(key));
			prng.GenerateBlock(iv, sizeof(iv));
			break;
		}
		case 2:{ 
			wcout << "Please input your secret key in hex: ";
            wstring wkey_input;
            wcin >> wkey_input;
            wcin.ignore();
            std::string key_input = wstring_to_string(wkey_input);
            hex_to_byte(key_input);
            key = SecByteBlock(reinterpret_cast<const CryptoPP::byte*>(&key_input[0]), key_input.size());
          
		    wcout << "Please input your iv in hex: ";
            wstring wiv_input;
            wcin >> wiv_input;
            wcin.ignore();
            string iv_input = wstring_to_string(wiv_input);
            string iv_str;
            StringSource(iv_input, true, 
                    new HexDecoder(
                        new StringSink(iv_str)
                    ) // HexDecoder
                ); // StringSource

            memcpy(iv, iv_str.c_str(), sizeof(iv)); 
            break;
		}
		case 3:{ // reading key from file
			string temp_key, temp_iv;
			wstring wfile_path;
			string file_path;
			string text;
			wcout << L"Show me the path for your key and iv file: ";
			wcin.ignore();
			getline(wcin, wfile_path);

			file_path = wstring_to_string(wfile_path);

			ifstream MyReadFile(file_path);

			wcout << L"This is what in your file, make sure to check it:" << endl;
			int counter = 0;
			while (getline(MyReadFile, text)) {
				wcout << string_to_wstring(text) << endl;

				if (counter == 0) {
					temp_key = text;
				} else if (counter == 1) {
					temp_iv = text;
					break;
				}
				counter++;
			}
			MyReadFile.close();
			
			string key_hex = temp_key;
			string iv_hex = temp_iv;

			string key_str;
			StringSource(key_hex, true, 
				new HexDecoder(
					new StringSink(key_str)
				) // HexDecoder
			); // StringSource
			memcpy(key, key_str.c_str(), sizeof(key)); 

			string iv_str;
			StringSource(iv_hex, true, 
				new HexDecoder(
					new StringSink(iv_str)
				) // HexDecoder
			); // StringSource
			memcpy(iv, iv_str.c_str(), sizeof(iv)); 

			break;
			}
		default:
			break;
		}
		int dec_mode;
		wcout << "How would you like to do it:\n"
                     << "1. ECB;\n"
                     << "2. CBC;\n"
                     << "3. OFB;\n"
                     << "4. CFB;\n"
                     << "5. CTR;\n"
                     << "6. XTS;\n"
                     << "7. CCM;\n"
                     << "8. GCM;\n"
                     << "Please enter your number:";
        wcin >> dec_mode;
        wcin.ignore();
		// PROCESSING
		switch (dec_mode){
				case 1:{	
					wcout << "ECB  " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;									
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);				
					try{
						ECB_Mode<AES>::Decryption d;
						d.SetKey(the_key, sizeof(the_key));
						StringSource s2(cipher_str, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 2:{
					wcout << "CBC  " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);				
					try{
						CBC_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s2(cipher_str, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 3:{
					wcout << "OFB  " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);

					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	

					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);				
					try{
						OFB_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s2(cipher_str, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 4:{
					wcout << "CFB " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);

					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
											
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);				
					try{
						CFB_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s2(cipher_str, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 5:{
					wcout << "CTR " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);

					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);				
					try{
						CTR_Mode<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s2(cipher_str, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered)) // StreamTransformationFilter
						);																		  // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 6:{
					wcout << "XTS " << endl;
					XTS<AES>::Encryption e;
					CryptoPP::byte the_key[e.DefaultKeyLength()];
					std::copy(key + 0, key + e.DefaultKeyLength(), the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);	
					try{
						XTS<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv);
						StringSource s2(cipher_str, true,
										new StreamTransformationFilter(d,
																	new StringSink(recovered), StreamTransformationFilter::NO_PADDING) // StreamTransformationFilter
						);	
					}
					catch( const CryptoPP::Exception& ex ){
						std::cerr << ex.what() << std::endl;
						exit(1);
					}
					break;
				}
				case 7:{
					wcout << "CCM " << endl;
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					
					byte ccm_iv[13]; // Khởi tạo IV với độ dài 13 byte
					std::copy(iv, iv + 13, ccm_iv);
					
					
					// const tag_size
					const int TAG_SIZE = 12;
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);
					try{
						CCM<AES, TAG_SIZE>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), ccm_iv, sizeof(ccm_iv));
						d.SpecifyDataLengths(0, cipher_str.size() - TAG_SIZE, 0);
						StringSource s2(cipher_str, true,
										new AuthenticatedDecryptionFilter(d,
																		new StringSink(recovered)) // StreamTransformationFilter
						);																			 // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					break;
				}
				case 8:{
					wcout << "GCM " << endl;
					
					CryptoPP::byte the_key[AES::DEFAULT_KEYLENGTH];
					std::copy(key + 0, key + AES::DEFAULT_KEYLENGTH, the_key);
					// Pretty print key and iv
					encoded.clear();
					StringSource(the_key, sizeof(the_key), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);			  // StringSource		
					wcout << "key: " << string_to_wstring(encoded) << endl;				
					encoded.clear();
					StringSource(iv, sizeof(iv), true,
								new HexEncoder(
									new StringSink(encoded)) // HexEncoder
					);		  // StringSource
					wcout << "iv: " << string_to_wstring(encoded) << endl;	
					
					string cipher_str;
					StringSource(cipher, true,
								new HexDecoder(
									new StringSink(cipher_str)) // HexEncoder
					);
					try{
						GCM<AES>::Decryption d;
						d.SetKeyWithIV(the_key, sizeof(the_key), iv, sizeof(iv));
						StringSource s2(cipher_str, true,
										new AuthenticatedDecryptionFilter(d,
																		new StringSink(recovered)) // StreamTransformationFilter
						);																			 // StringSource
					}
					catch (const CryptoPP::Exception &e){
						cerr << e.what() << endl;
						exit(1);
					}
					
					break;
				}
				default:{
					break;
				}
				}
			wcout << "Recovered text: " << string_to_wstring(recovered) << endl;
			return 0;
	}
	default:
		break;
	}
}

string wstring_to_string(const wstring &str){
	wstring_convert<codecvt_utf8<wchar_t>> tostring;
	return tostring.to_bytes(str);
}

wstring string_to_wstring(const string &str){
	wstring_convert<codecvt_utf8<wchar_t>> towstring;
	return towstring.from_bytes(str);
}