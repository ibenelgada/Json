#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <map>
#include <vector>
#include <string>


class JsonObject;
class Object;
class Array;
class Real;
class Integer;
class String;

std::ostream& operator<<(std::ostream& os, JsonObject* obj);
std::ostream& operator<<(std::ostream& os, Object& obj);
std::ostream& operator<<(std::ostream& os, Array& obj);
std::ostream& operator<<(std::ostream& os, Real& obj);
std::ostream& operator<<(std::ostream& os, Integer& obj);
std::ostream& operator<<(std::ostream& os, String& obj);


enum JsonType {
  OBJECT,
  ARRAY,
  INTEGER,
  REAL,
  STRING
};

class JsonObject{

public:
  JsonType type;

};

class Object: public JsonObject{

public:
  std::map<std::string, JsonObject*> obj;
  Object();
  friend std::ostream& operator<<(std::ostream& os, Object& obj);
};

class Array: public JsonObject{
public:
  std::vector<JsonObject*> arr;
  Array();
    friend std::ostream& operator<<(std::ostream& os, Array& obj);
};

class Integer: public JsonObject{
public:
  Integer();
  Integer(long long);
  long long val;
    friend std::ostream& operator<<(std::ostream& os, Integer& obj);
};

class Real: public JsonObject{
public:
  Real();
  Real(double);
  double val;
    friend std::ostream& operator<<(std::ostream& os, Real& obj);
};

class String: public JsonObject{

public:
  String();
  String(std::string);
  
  std::string val;
  friend std::ostream& operator<<(std::ostream& os, String& obj);
};


#endif
