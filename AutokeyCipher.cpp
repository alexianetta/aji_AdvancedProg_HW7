#include "AutokeyCipher.h"

const string AutokeyCipher::CIPHER_NAME = "Autokey";

AutokeyCipher::AutokeyCipher(string primer) : Cipher(CIPHER_NAME), primer(primer) {}

bool AutokeyCipher::encode(string decodedMsg) {

string key = primer + decodedMsg;
for(int i = 0; i < decodedMsg.length(); i++){
  if(isValidCharacter(decodedMsg[i]) && (decodedMsg[i] != ' ')){
    encoded[i] = (key[i] + decodedMsg[i]) % 26;
    encoded[i] = encoded[i] + 65;
  }
  else{
    return false;
  }

}
    this-> encoded = decodedMsg;
return true;
}

bool AutokeyCipher::decode(string encodedMsg) {
  /*TODO: write your code*/
  string key = primer;
for( int i = 0; i < encodedMsg.length(); i++){
  if(isValidCharacter(encodedMsg[i]) && (encodedMsg[i] != ' ')){
    encoded[i] = (encodedMsg[i] - key[i]) % 26;
    encoded[i] = encoded[i] + 65;
    if(encodedMsg[i] < 65){
      encodedMsg[i] = encodedMsg[i] + 26;

    }
  }
  else{
    return false;
  }
  
  decoded = decoded + encodedMsg[i];
  key = key + encodedMsg[i];
}
  
    this-> decoded = encodedMsg;
return true;
}

bool AutokeyCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
