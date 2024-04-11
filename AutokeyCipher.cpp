#include "AutokeyCipher.h"

const string AutokeyCipher::CIPHER_NAME = "Autokey";

AutokeyCipher::AutokeyCipher(string primer) : Cipher(CIPHER_NAME), primer(primer) {}

bool AutokeyCipher::encode(string decodedMsg) {

string key = primer + message;
for(i = 0; i < decodedMsg.length(); i++){
  if(isValidCharacter(decodedMsg[i] && decodedMsg != ' ')){
    encoded[i] = (key[i] + decodedMsg[i]) % 26;
    encoded[i] = encoded[i] + 65;
  }
  else{
    return false;
  }

}

return true;
}

bool AutokeyCipher::decode(string encodedMsg) {
  /*TODO: write your code*/
  string key = primer;
for(i = 0; i < decodedMsg.length(); i++){
  if(isValidCharacter(decodedMsg[i] && decodedMsg != ' ')){
    encoded[i] = (decodedMsg[i] - key[i]) % 26;
    encoded[i] = encoded[i] + 65;
    if(encodedMsg < 65){
      encodedMsg[i] = encodedMsg[i] + 26;

    }

  }
  decoded = decoded + encodedMsg[i];
  key = key + encodedMsg[i];
  }
  else{
    return false;
  }

return true;
}

bool AutokeyCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
