/* Copyright 2011 Gary Briggs

This file is part of obdgpslogger.

obdgpslogger is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

obdgpslogger is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with obdgpslogger.  If not, see <http://www.gnu.org/licenses/>.
*/

/** \file
  \brief Tools to open the sim port
*/

#ifndef __FDSIMPORT_H
#define __FDSIMPORT_H

#include "simport.h"

/// Base class for virtual ports
class FDSimPort : public OBDSimPort {
public:
	/// Get a string representing the port as it's exposed
	/** Take a copy if you care - the memory won't stay valid */
	virtual char *getPort();

	/// Read a line from the virtual port
	/** Take a copy if you care - the memory won't stay valid */
	virtual char *readLine();

	/// Write some data to the virtual port
	virtual void writeData(const char *data, int log=1);

protected:
	/// Constructor. Can't construct one of these
	FDSimPort();

	/// Destructor. Can't destroy one of these
	virtual ~FDSimPort();

	/// Wait for a connection
	/** \return >0 on success */
	virtual int tryConnection() = 0;

	/// Whether or not it's connected
	virtual int isConnected();

	/// Close one connection, but not entire process
	virtual void closeCurrentConnection() = 0;

	/// The connected client
	int fd;

	/// Whether or not it's connected
	int connected;

	/// Last line read [returned by readLine]
	char lastread[4096];

	/// Current char buf [while reading]
	char readbuf[4096];

	/// String returned by getPort
	char portname[4096];

	/// Current position in the read buffer
	int readbuf_pos;

private:
	/// In case we need to set status
	virtual void setConnected(int yes);

};

#endif //__FDSIMPORT_H

