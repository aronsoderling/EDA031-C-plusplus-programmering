#ifndef UMNS_H
#define UMNS_H

#include <unordered_map>
#include "nameserverinterface.h"

class UMNS : public NameServerInterface {
public:
	UMNS();
	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	virtual void insert(const HostName&, const IPAddress&);

	
	
	/*i
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	virtual bool remove(const HostName&);
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	virtual IPAddress lookup(const HostName&) const;
private:
	std::unordered_map<HostName, IPAddress> map;
};

#endif