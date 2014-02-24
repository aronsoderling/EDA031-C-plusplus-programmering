#include <algorithm> 
#include "umns.h"

using namespace std;

UMNS::UMNS() {}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void UMNS::insert(const HostName& name, const IPAddress& addr){
	map.insert({name,addr});
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool UMNS::remove(const HostName& name){
	if(map.erase(name) > 0){
		return true;
	}else{
		return false;
	}
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress UMNS::lookup(const HostName& name) const{
	auto it = map.find(name);
	if(it != map.end()){
		return it->second;
	}else{
		return NON_EXISTING_ADDRESS;
	}
}

