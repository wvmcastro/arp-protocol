#ifndef __DEFINES__
#define __DEFINES__


// The purpose of this file is to defines the macros
// Used in all system's parts


// ----------------- General macros -----------------
#define __ERROR__   -1
#define __OK__      0
#define DEFAULT_TTL 60
#define LOOPBACK_IP "127.0.0.1"
#define XARPD_PORT  5050
// -------------- End general macros -----------------

// ---------- Inter program communication ------------

// The protocol looks like that. The protocol has a
// fixed size of 13bytes this is used for most requests
// OPCODE IPADDRESS ETHERADDRESS TTL
// 1 byte   4 bytes    6 bytes   2 bytes

// There is a other possible header used when xifconfig
// changes the parameters of a interface and needs to notify the
// xarpd
// OPCODE IFACE_NAME
// 1 byte n bytes

// OPCODES
#define SHOW_TABLE    0
#define RES_IP        1
#define ADD_LINE      2
#define DEL_LINE      3
#define SET_TTL       4
#define LIST_IFCES    5
#define UPDATE_IFACE  6

// -------- End inter program communication ----------

#endif