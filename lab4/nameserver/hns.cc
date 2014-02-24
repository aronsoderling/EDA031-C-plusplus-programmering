#include <algorithm> 
#include <functional>
#include <iostream>
#include "hns.h"

using namespace std;

HNS::HNS(int size) : hash_size(size){
	for(int i=0; i<size; i++){
		map.push_back(vector< pair<HostName, IPAddress> >());
	}
}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void HNS::insert(const HostName& name, const IPAddress& addr){
	int hash = myHash(name);
	map[hash].push_back(make_pair(name, addr));
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool HNS::remove(const HostName& name){
	int hash = myHash(name);
	auto it = find_if(map[hash].begin(), map[hash].end(), [name] (const pair<HostName, IPAddress>& n) { return n.first == name; } );

	if(it != map[hash].end()){
		map[hash].erase(it);
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
IPAddress HNS::lookup(const HostName& name) const{
	int hash = myHash(name);
	auto it = find_if(map[hash].begin(), map[hash].end(), [name] (const pair<HostName, IPAddress>& n) { return n.first == name; } );

	if(it != map[hash].end()){
		return it->second;
	}else{
		return NON_EXISTING_ADDRESS;
	}
}

int HNS::myHash(const HostName& name) const{
	string str = name;
	int hash = 0;
	int i = 0;
	for(auto it = str.begin(); it != str.end(); ++it) {
		hash += *it;
		++i;
   	}
   	//cout << name << " gives hash " << hash << endl;
	return hash % hash_size;
}