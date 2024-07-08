/*
* Copyright 2022-2023 The MathWorks, Inc.
*
* File: stm_ethernet_wrapper.h
*
* Abstract:
*  Ethernet communications header for STM32F7 Discovery.
*/
#ifndef STM_ETHERNET_WRAPPER_H
#define STM_ETHERNET_WRAPPER_H

#include <stdio.h>
#include <string.h>
#include "MW_target_hardware_resources.h"
#include "rtwtypes.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/dhcp.h"
#include "lwip/ip_addr.h"

#include "netif/etharp.h"
#include "ethernetif.h"
#include "SysTickScheduler.h"

#ifdef MW_ARM_CLANG
#define MW_NO_OPTIMIZE
#else
#define MW_NO_OPTIMIZE __attribute__((optimize("O0")))
#endif

//*****************************************************************************
//*****************************************************************************
typedef volatile struct {
    uint32_T tcp_data_offset;
    uint32_T tcp_data_read_offset;
    uint32_T tcp_data_reading;
    uint32_T data_buf_position;
    uint32_T num_rollback;
    uint32_T num_read_rollback;
    uint32_T data_read_location;
    uint32_T LocalIPPort;
    uint8_T *data_buf;
    struct tcp_pcb * pcb_tcp;
    uint8_T BlockingMode;
    uint8_T flag_tcp_present;
} tcp_conn_info;

typedef volatile struct {
    uint32_T LocalIPPort;
    uint32_T RemoteIPPort;
    uint8_T *data_buf;
    uint8_T data_offset;
    uint8_T data_read_offset;
    uint8_T data_reading;
    uint8_T BlockingMode;
    uint8_T flag_udp_present;
    struct udp_pcb * pcb_udp;
} udp_conn_info;


/*
****************************************************************************************************************************************************
* Set a callback for UDP Receive packets
* Input Params
* arg - Arguments that are passed to the Callback function.
* upcb - Pointer to the PCB structure of UDP
* p - Pointer to the pbuf payload
* addr - IP Address
* port - Port number
*
* Output Params
* None
****************************************************************************************************************************************************
*/
void RecvUDPCallBack(void *arg, struct udp_pcb *upcb, struct pbuf *p, ip_addr_t *addr, u16_t port);
/*
****************************************************************************************************************************************************
* Get the Octet Values from a String of IP Address
* Input Params
* IPAddress - String Containing the IP Address with .'s
* Output Params
* Octet Vals - Returns an array of Octet Values
****************************************************************************************************************************************************
*/

void GetIPAddressOctets(char_T *IPAddress,uint8_T *OctetVals);
/*
****************************************************************************************************************************************************
* Configure the Peripherals for using Ethernet port.
****************************************************************************************************************************************************
*/
void EthernetConfigure(void);
/*
****************************************************************************************************************************************************
* Interrupt Handler for the Ethernet peripheral.
****************************************************************************************************************************************************
*/
void ETH_IRQHandler(void);
/*
****************************************************************************************************************************************************
* UDP Wrapper function For UDP Transmit and receive Initialize
* Input Params
* LocalIPPort  - Local IP Port
* RemoteIPAddress - Remote IP Address to build connection with
* RemoteIPPort  - Remote IP Port
****************************************************************************************************************************************************
*/
uint32_T ARM_UDP_Initialize(int32_T LocalIPPort,char_T *RemoteIPAddress,uint32_T RemoteIPPort);
/*
****************************************************************************************************************************************************
* UDP Wrapper function For UDP Transmit Packet
* Input Params
* udp_conn_str - UDP Connection Structure Address
* data  - Pointer to the data
* length  - Length of the data to be transmitted in bytes
* BlockingMode - In Blocking Mode, Wait for previous Data to be transmitted In Blocking Mode, Otherwise just exit if currently data is being sent
****************************************************************************************************************************************************
*/
uint8_T ARM_TransmitUdpPacket(void* udp_conn_addr ,const void *data, uint32_T length,uint32_T BlockingMode);
/*
****************************************************************************************************************************************************
* UDP Wrapper function For UDP Receive Packet
* Input Params
* udp_conn_str - UDP Connection Structure Address
* data  - Pointer to the data
* length  - Length of the data to be transmitted in bytes
* BlockingMode - In Blocking Mode, Wait for Data to be received, Otherwise just exit if not enough data
****************************************************************************************************************************************************
*/
uint32_T ARM_ReceiveUdpPacket(void *udp_conn_addr, void *data, uint32_T length, uint32_T BlockingMode);
/*
****************************************************************************************************************************************************
* TCP Wrapper function For TCP Transmit and receive Initialize
* Input Params
* SendReceiveFlag - Send 0, Receive 1
* isClient - Server 0, Client 1
* LocalIPPort  - Local IP Port
* ServerIPPort  - Server IP Port
* RemoteIPAddress - Remote IP Address to build connection with
****************************************************************************************************************************************************
*/
tcp_conn_info* ARM_TCP_Initialize(uint8_T SendReceiveFlag,uint8_T isClient,uint32_T LocalIPPort,uint32_T ServerPort,char_T *RemoteIPAddress);


/*
****************************************************************************************************************************************************
* TCP Wrapper function For TCP Transmit Packet
* Input Params
* tcp_conn_addr - TCP Connection Address. This will be dereferenced to the tcp_conn_info structure inside the function
* data  - Pointer to the data
* length  - Length of the data to be transmitted in bytes
* BlockingMode - In Blocking Mode, Wait for previous Data to be transmitted In Blocking Mode, Otherwise just exit if currently data is being sent
****************************************************************************************************************************************************
*/
uint8_T  ARM_TransmitTcpPacket(void *tcp_conn_addr, const void *data, uint32_T length, uint32_T BlockingMode);
/*
****************************************************************************************************************************************************
* TCP Wrapper function For TCP Receive Packet
* Input Params
* tcp_conn_addr - Address of the TCP Connection Structure. This will be dereferenced to the tcp_conn_info structure inside the function
* data  - Pointer to the data
* length  - Length of the data to be transmitted in bytes
* BlockingMode - Blocking Mode parameter -> Wait for Data to be received in Blocking Mode, Otherwise just exit from the Receive if no data present
****************************************************************************************************************************************************
*/
uint8_T ARM_ReceiveTcpPacket(void *tcp_conn_addr, void *data, uint32_T length, uint32_T BlockingMode);
/*
****************************************************************************************************************************************************
* Callback for TCP Receive Packet
* Input Params
* arg - Address of the TCP Connection Structure. This will be dereferenced to the tcp_conn_info structure inside the function
* tpcb  - Pointer to the TCP PCB Structure
* p  - Pointer to the data
* err - Error status from the TCP Connection
****************************************************************************************************************************************************
*/
err_t recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);

/*
****************************************************************************************************************************************************
* Callback for TCP when a new server connection is established
* Input Params
* arg - Address of the TCP Connection Structure.
* newpcb  - Pointer to the TCP PCB Structure
* err - Error status from the TCP Connection
****************************************************************************************************************************************************
*/
err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err);
/*
****************************************************************************************************************************************************
* Callback for TCP when a new client connection is established
* Input Params
* arg - Address of the TCP Connection Structure.
* newpcb  - Pointer to the TCP PCB Structure
* err - Error status from the TCP Connection
****************************************************************************************************************************************************
*/
err_t client_connected(void *arg, struct tcp_pcb *newpcb, err_t err);

/*
****************************************************************************************************************************************************
* Callback for TCP to close the connection
* Input Params
* tcp_conn_addr - Address of the TCP Connection Structure. This will be dereferenced to the tcp_conn_info structure inside the function
****************************************************************************************************************************************************
*/
void ARM_TcpClose(void *tcp_conn_addr);

#endif  // STM_ETHERNET_WRAPPER_H


/* LocalWords:  upcb pbuf addr Vals conn TCP tcp tpcb newpcb
*/
