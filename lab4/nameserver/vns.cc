#include <algorithm> 
#include "vns.h"

using namespace std;

VNS::VNS() {}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void VNS::insert(const HostName& name, const IPAddress& addr){
	v.push_back( make_pair(name, addr) );
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool VNS::remove(const HostName& name){
	auto it = find_if(v.begin(), v.end(), [name] (const pair<HostName, IPAddress>& n) { return n.first == name; } );
	if(it != v.end()){
		v.erase(it);
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
IPAddress VNS::lookup(const HostName& name) const{
	auto it = find_if(v.begin(), v.end(), [name] (const pair<HostName, IPAddress>& n) { return n.first == name; } );
	if(it != v.end()){
		return it->second;
	}else{
		return NON_EXISTING_ADDRESS;
	}
}

