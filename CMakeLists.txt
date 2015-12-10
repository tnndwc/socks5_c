cmake_minimum_required(VERSION 3.3)
project(socks5_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories( "${socks5_c}/openssl" )

set(SOURCE_FILES
        buffer.c
        buffer.h
        debug.h
        encrypt.c
        encrypt.h
        list.h
        local.c
        rc4.c
        rc4.h
        socket_wrap.c
        socket_wrap.h
        socks.c
        socks.h
        socks5_protocol.h
        xor.c
        xor.h
        aes_cfb.c aes_cfb.h aes_cfb.c aes_cfb.h)
add_executable(socks5_c ${SOURCE_FILES})