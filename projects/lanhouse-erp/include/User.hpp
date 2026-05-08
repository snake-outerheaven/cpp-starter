#ifndef USER_HPP
#define USER_HPP

#include <cstdlib>
#include <string>

class User
{
private:
  size_t id;
  std::string name;
  bool online;

public:
  User (size_t id, std::string name, bool online)
    : id (id), name (name), online (online)
  {
  }

  size_t
  getId () const
  {
    return id;
  }
  std::string
  getName () const
  {
    return name;
  }
  bool
  isOnline () const
  {
    return online;
  }

  void
  setId (size_t id)
  {
    this->id = id;
  }
  void
  setName (std::string name)
  {
    this->name = name;
  }
  void
  setOnline (bool online)
  {
    this->online = online;
  }
};

#endif
