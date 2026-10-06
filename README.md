# Simple C TCP Server

A small TCP server written in C using Linux socket programming.

This project is made for learning how basic network servers work using the C socket API.

## Features

* Creates an IPv4 TCP socket
* Binds to port `8181`
* Listens for incoming connections
* Accepts a client
* Reads data from the client
* Sends a response
* Closes the connection

## Requirements

* Linux
* GCC
* Basic C knowledge

## Compile

```bash
gcc server.c -o server
```

## Run

```bash
./server
```

The server will listen on:

```text
0.0.0.0:8181
```

## Test

Using `curl`:

```bash
curl http://127.0.0.1:8181
```

Or using Netcat:

```bash
nc 127.0.0.1 8181
```

## How It Works

The server follows this basic socket workflow:

```text
socket()
   ↓
bind()
   ↓
listen()
   ↓
accept()
   ↓
read()
   ↓
write()
   ↓
close()
```

### socket()

Creates the TCP socket.

### bind()

Associates the socket with:

```text
0.0.0.0:8181
```

### listen()

Starts waiting for incoming TCP connections.

### accept()

Accepts a client and creates a new socket for that connection.

### read()

Receives data sent by the client.

### write()

Sends data back to the client.

### close()

Closes the client and server sockets.

## Example Response

The current server sends:

```text
httpd v1.0
```

This is a basic TCP response and is not a complete HTTP response.

## Project Structure

```text
.
├── server.c
└── README.md
```

## Learning Goals

This project is useful for learning:

* C socket programming
* TCP
* IPv4
* File descriptors
* `struct sockaddr_in`
* Ports and IP addresses
* `bind()`
* `listen()`
* `accept()`
* `read()`
* `write()`
* `close()`

## License

This project is for learning and experimentation.

# Author 

Deadcode
