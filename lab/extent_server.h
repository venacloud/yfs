// this is the extent server

#ifndef extent_server_h
#define extent_server_h

#include <string>
#include <map>
#include "extent_protocol.h"

class extent_server {

private:
    std::map<extent_protocol::extentid_t,
            std::pair<std::string, extent_protocol::attr> > fs;

    struct debug {
        unsigned int nput;
        unsigned int nget;
        unsigned int ngetattr;
        unsigned int nremove;

        debug():
            nput(), nget(), ngetattr(), nremove()
        {}

        void putInc() {
            nput++;
        }
        void getInc() {
            nget++;
        }
        void getattrInc() {
            ngetattr++;
        }
        void removeInc() {
            nremove++;
        }
    };

    debug stats;

 public:
  extent_server();

  int put(extent_protocol::extentid_t id, std::string, int &);
  int get(extent_protocol::extentid_t id, std::string &);
  int getattr(extent_protocol::extentid_t id, extent_protocol::attr &);
  int remove(extent_protocol::extentid_t id, int &);
};

#endif







