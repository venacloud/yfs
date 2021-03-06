// this is the lock server
// the lock client has a similar interface

#ifndef lock_server_h
#define lock_server_h

#include <string>
#include "rsm.h"
#include "lock_protocol.h"
#include "rsm_state_transfer.h"
#include "lock_client.h"
#include "rpc.h"

class lock_server : rsm_state_transfer {

private:
    class rsm *rsm;

protected:
    int nacquire;

public:
    lock_server(class rsm *rsm=0);

    lock_protocol::status stat(int clt, lock_protocol::lockid_t lid, int &);
    lock_protocol::status acquire(int clt, lock_protocol::lockid_t, int &);
    lock_protocol::status release(int clt, lock_protocol::lockid_t, int &);

    // fix me; bad inheritance
    std::string marshal_state();
    void unmarshal_state(std::string);
};

#endif







