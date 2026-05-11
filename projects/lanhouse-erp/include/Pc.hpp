#ifndef PC_HPP
#define PC_HPP

#include <cstdlib>
#include <string>

class Pc
{
private:
  size_t id;
  std::string type;
  bool available;

public:
  Pc (size_t id, std::string type, bool available)
      : id (id), type (type), available (available)
  {
  }

  size_t
  getId () const
  {
    return this->id;
  }

  std::string
  getType () const
  {
    return this->type;
  }

  bool
  isAvailable () const
  {
    return this->available;
  }

  void
  setId (size_t id)
  {
    this->id = id;
  }

  void
  setType (const std::string &type)
  {
    this->type = type;
  }

  void
  setAvailable (bool available)
  {
    this->available = available;
  }

};

#endif
