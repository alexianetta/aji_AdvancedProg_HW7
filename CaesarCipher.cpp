#include "CaesarCipher.h"

const string CaesarCipher::CIPHER_NAME = "Caesar";

CaesarCipher::CaesarCipher(int shift) : Cipher(CIPHER_NAME), shift(shift){}

bool CaesarCipher::encode(string decodedMsg) {
  /*TODO: write your code*/
 for (int i =0; i < decodedMsg.length(); i++){
  if(isValidCharacter(decodedMsg[i]) && (decodedMsg[i] != ' ')){
      decodedMsg [i] = decodedMsg[i] - (65 - shift);
    
    if(decodedMsg[i] > 25){
      decodedMsg[i] = decodedMsg[i] -26;
    }
     else if(decodedMsg[i] < 0) {
    decodedMsg[i] = decodedMsg[i] + 26;
     }
     }
   else{
    return false;
  }
  
  decodedMsg[i] = decodedMsg[i] + 65;
  //encoded[i] = decodedMsg[i];
  }
  this-> encoded = decodedMsg;
return true;
}

bool CaesarCipher::decode(string encodedMsg) {
  /*TODO: write your code*/

 for(int i =0; i < encodedMsg.length(); i++){
  if(isValidCharacter(encodedMsg[i]) && (encodedMsg [i] != ' ')){
      encodedMsg [i] = encodedMsg[i] - (65 + shift);
    
    if(encodedMsg[i] > 25){
      encodedMsg[i] = encodedMsg[i] -26;
    }
    else if(encodedMsg[i] < 0) {
    encodedMsg[i] = encodedMsg[i] + 26;
  }
  }
  else{
    return false;
  }
  encodedMsg[i] = encodedMsg[i] + 65;
 // decoded[i] = encodedMsg[i];
  }
    this-> decoded = encodedMsg;

return true;
}

bool CaesarCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
