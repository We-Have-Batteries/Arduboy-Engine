#ifndef STRING_H
#define STRING_H

// Has not been tested yet
class string{
public:
  string(char* str){
    this->str = str;
    length = sizeof(char)/sizeof(str);
  }

  void operator=(char* str){
    this->str = str;
    length = sizeof(char)/sizeof(str);
  }

  string operator+(string str){
    char* addedStr = new char[length + str.length];
    memcpy(addedStr, this->str, length * sizeof(char*));
    memcpy(addedStr+length, str.str, str.length * sizeof(char*));
    return addedStr;
  }

  void operator+=(string str){
    char* addedStr = new char[length + str.length];
    memcpy(addedStr, this->str, length * sizeof(char*));
    memcpy(addedStr+length, str.str, str.length * sizeof(char*));
    delete[] this->str;
    this->str = addedStr;
    length = length + str.length;
  }
private:
  char* str;
  uint16_t length;
};

#endif