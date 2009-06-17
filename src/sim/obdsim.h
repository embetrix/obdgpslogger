/** \file
 \brief OBD Simulator Main Entrypoint
*/
#ifndef __OBDSIM_H
#define __OBDSIM_H

#include <getopt.h>
#include <stdlib.h>

/// This is the elm prompt
#define ELM_PROMPT ">"

/// Default hide headers
#define ELM_HEADERS 0

/// Default show spaces
#define ELM_SPACES 1

/// Default echo
#define ELM_ECHO 1

/// ELM Version string
#define ELM_VERSION_STRING "ELM327 v1.3 OBDGPSLogger"

/// ELM "don't know" prompt
#define ELM_QUERY_PROMPT "?\n>"

/// ELM "OK" prompt
#define ELM_OK_PROMPT "?\n>"

/// ELM "NO DATA" prompt
#define ELM_NODATA_PROMPT "NO DATAn>"


/// getopt() long options
static const struct option longopts[] = {
        { "help", no_argument, NULL, 'h' }, ///< Print the help text
	{ "version", no_argument, NULL, 'v' }, ///< Print the version text
        { "db", required_argument, NULL, 'd' }, ///< Database file
        { "launch-logger", no_argument, NULL, 'o' }, ///< Launch obdgpslogger
        { NULL, 0, NULL, 0 } ///< End
};

/// getopt() short options
static const char shortopts[] = "hvd:o";

/// Print Help for --help
/** \param argv0 your program's argv[0]
 */
void printhelp(const char *argv0);

/// Print the version string
void printversion();


#endif //__OBDSIM_H

