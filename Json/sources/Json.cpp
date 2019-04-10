
#include "Json.h"


Object::Object(){
  this->type = OBJECT;
}

Array::Array(){
  this->type = ARRAY;
}

Integer::Integer(){
  this->type = INTEGER;
}

Real::Real(){
  this->type = REAL;
}

String::String(){
  this->type = STRING;
}


String::String(std::string s){
  this->type = STRING;
  val = s;
}

Real::Real(double d){
  this->type = REAL;
  val = d;
}

Integer::Integer(long long l){
  this->type = INTEGER;
  val = l;
}

std::ostream& operator<<(std::ostream& os, JsonObject* obj){
  Object* o;
  Array* a;
  Integer* i;
  Real* r;
  String* s;

  switch(obj->type){
    case OBJECT:
      o = (Object*) obj;
      os << *o;
      break;
    case ARRAY:
      a = (Array*) obj;
      os << *a;
      break;
    case INTEGER:
      i = (Integer*) obj;
      os << *i;
      break;
    case REAL:
      r = (Real*) obj;
      os << *r;
      break;
    case STRING:
      s = (String*) obj;
      os << *s;
      break;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, Object& obj){

  os << "{\n";
  std::map<std::string, JsonObject*>::iterator it = obj.obj.begin();
  if(obj.obj.size() != 0){
    os << "\"" << it->first << "\": " << (it->second);
    for(++it; it != obj.obj.end(); ++it){
      os << ",\n" << "\"" << it->first << "\": " << (it->second);
    }
  }
  os << "\n}";
  return os;
}

std::ostream& operator<<(std::ostream& os, Array& obj){
  unsigned int i;
  os << "[ ";

  for(i=0; i < obj.arr.size()-1 ; ++i){
    os << obj.arr[i] << ", ";
  }
  os << obj.arr[i] << " ]";
  return os;
}

std::ostream& operator<<(std::ostream& os, Real& obj){
  os << obj.val;
  return os;
}

std::ostream& operator<<(std::ostream& os, Integer& obj){
  os << obj.val;
  return os;
}

std::ostream& operator<<(std::ostream& os, String& obj){
  os << "\"" << obj.val << "\"";
  return os;
}
