/*
 * The MySQL C API is a C-based API that client applications written in C can use to communicate with MySQL Server.
 * Client programs refer to C API header files at compile time and link to a C API library file at link time.
 * The library comes in two versions, depending on how the application is intended to communicate with the server:
 *
 * libmysqlclient:
 * The client version of the library, used for applications that communicate over a network connection as a client of a standalone server process.
 * 
 * libmysqld:
 * The embedded server version of the library, used for applications intended to include an embedded MySQL server within the application itself.
 * The application communicates with its own private server instance.
 * 
 * note:
 * The libmysqld embedded server library is deprecated as of MySQL 5.7.19 and will be removed in MySQL 8.0.
 * 
 * The names of the library files to use when linking C API client applications depend on the library type and platform for which a distribution is built:
 * 
 * On Unix (and Unix-like) systems, the static library is libmysqlclient.a. The dynamic library is libmysqlclient.so on most Unix systems and libmysqlclient.dylib on macOS.
 * 
 * For distributions that include embedded server libraries, the corresponding library names begin with libmysqld rather than libmysqlclient.
 * 
 * On Windows, the static library is mysqlclient.lib and the dynamic library is libmysql.dll. Windows distributions also include libmysql.lib, a static import library needed for using the dynamic library.
 */