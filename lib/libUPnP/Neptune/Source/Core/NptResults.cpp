
/*****************************************************************
|
|   Neptune - Result Code Map
|
|   This file is automatically generated by a script, do not edit!
|
| Copyright (c) 2002-2008, Axiomatic Systems, LLC.
| All rights reserved.
|
| Redistribution and use in source and binary forms, with or without
| modification, are permitted provided that the following conditions are met:
|     * Redistributions of source code must retain the above copyright
|       notice, this list of conditions and the following disclaimer.
|     * Redistributions in binary form must reproduce the above copyright
|       notice, this list of conditions and the following disclaimer in the
|       documentation and/or other materials provided with the distribution.
|     * Neither the name of Axiomatic Systems nor the
|       names of its contributors may be used to endorse or promote products
|       derived from this software without specific prior written permission.
|
| THIS SOFTWARE IS PROVIDED BY AXIOMATIC SYSTEMS ''AS IS'' AND ANY
| EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
| WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
| DISCLAIMED. IN NO EVENT SHALL AXIOMATIC SYSTEMS BE LIABLE FOR ANY
| DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
| (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
| LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
| ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
| (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
| SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
|
 ****************************************************************/

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "Neptune.h"

/*----------------------------------------------------------------------
|   NPT_ResultText
+---------------------------------------------------------------------*/
const char*
NPT_ResultText(NPT_Result result)
{
    switch (result) {
        case NPT_SUCCESS: return "SUCCESS";
        case NPT_FAILURE: return "FAILURE";

        case NPT_ERROR_INVALID_PARAMETERS: return "NPT_ERROR_INVALID_PARAMETERS";
        case NPT_ERROR_PERMISSION_DENIED: return "NPT_ERROR_PERMISSION_DENIED";
        case NPT_ERROR_OUT_OF_MEMORY: return "NPT_ERROR_OUT_OF_MEMORY";
        case NPT_ERROR_NO_SUCH_NAME: return "NPT_ERROR_NO_SUCH_NAME";
        case NPT_ERROR_NO_SUCH_PROPERTY: return "NPT_ERROR_NO_SUCH_PROPERTY";
        case NPT_ERROR_NO_SUCH_ITEM: return "NPT_ERROR_NO_SUCH_ITEM";
        case NPT_ERROR_NO_SUCH_CLASS: return "NPT_ERROR_NO_SUCH_CLASS";
        case NPT_ERROR_OVERFLOW: return "NPT_ERROR_OVERFLOW";
        case NPT_ERROR_INTERNAL: return "NPT_ERROR_INTERNAL";
        case NPT_ERROR_INVALID_STATE: return "NPT_ERROR_INVALID_STATE";
        case NPT_ERROR_INVALID_FORMAT: return "NPT_ERROR_INVALID_FORMAT";
        case NPT_ERROR_INVALID_SYNTAX: return "NPT_ERROR_INVALID_SYNTAX";
        case NPT_ERROR_NOT_IMPLEMENTED: return "NPT_ERROR_NOT_IMPLEMENTED";
        case NPT_ERROR_NOT_SUPPORTED: return "NPT_ERROR_NOT_SUPPORTED";
        case NPT_ERROR_TIMEOUT: return "NPT_ERROR_TIMEOUT";
        case NPT_ERROR_WOULD_BLOCK: return "NPT_ERROR_WOULD_BLOCK";
        case NPT_ERROR_TERMINATED: return "NPT_ERROR_TERMINATED";
        case NPT_ERROR_OUT_OF_RANGE: return "NPT_ERROR_OUT_OF_RANGE";
        case NPT_ERROR_LIST_EMPTY: return "NPT_ERROR_LIST_EMPTY";
        case NPT_ERROR_LIST_OPERATION_ABORTED: return "NPT_ERROR_LIST_OPERATION_ABORTED";
        case NPT_ERROR_LIST_OPERATION_CONTINUE: return "NPT_ERROR_LIST_OPERATION_CONTINUE";
        case NPT_ERROR_NO_SUCH_FILE: return "NPT_ERROR_NO_SUCH_FILE";
        case NPT_ERROR_FILE_NOT_OPEN: return "NPT_ERROR_FILE_NOT_OPEN";
        case NPT_ERROR_FILE_BUSY: return "NPT_ERROR_FILE_BUSY";
        case NPT_ERROR_FILE_ALREADY_OPEN: return "NPT_ERROR_FILE_ALREADY_OPEN";
        case NPT_ERROR_FILE_NOT_READABLE: return "NPT_ERROR_FILE_NOT_READABLE";
        case NPT_ERROR_FILE_NOT_WRITABLE: return "NPT_ERROR_FILE_NOT_WRITABLE";
        case NPT_ERROR_FILE_NOT_DIRECTORY: return "NPT_ERROR_FILE_NOT_DIRECTORY";
        case NPT_ERROR_FILE_ALREADY_EXISTS: return "NPT_ERROR_FILE_ALREADY_EXISTS";
        case NPT_ERROR_FILE_NOT_ENOUGH_SPACE: return "NPT_ERROR_FILE_NOT_ENOUGH_SPACE";
        case NPT_ERROR_DIRECTORY_NOT_EMPTY: return "NPT_ERROR_DIRECTORY_NOT_EMPTY";
        case NPT_ERROR_READ_FAILED: return "NPT_ERROR_READ_FAILED";
        case NPT_ERROR_WRITE_FAILED: return "NPT_ERROR_WRITE_FAILED";
        case NPT_ERROR_EOS: return "NPT_ERROR_EOS";
        case NPT_ERROR_CONNECTION_RESET: return "NPT_ERROR_CONNECTION_RESET";
        case NPT_ERROR_CONNECTION_ABORTED: return "NPT_ERROR_CONNECTION_ABORTED";
        case NPT_ERROR_CONNECTION_REFUSED: return "NPT_ERROR_CONNECTION_REFUSED";
        case NPT_ERROR_CONNECTION_FAILED: return "NPT_ERROR_CONNECTION_FAILED";
        case NPT_ERROR_HOST_UNKNOWN: return "NPT_ERROR_HOST_UNKNOWN";
        case NPT_ERROR_SOCKET_FAILED: return "NPT_ERROR_SOCKET_FAILED";
        case NPT_ERROR_GETSOCKOPT_FAILED: return "NPT_ERROR_GETSOCKOPT_FAILED";
        case NPT_ERROR_SETSOCKOPT_FAILED: return "NPT_ERROR_SETSOCKOPT_FAILED";
        case NPT_ERROR_SOCKET_CONTROL_FAILED: return "NPT_ERROR_SOCKET_CONTROL_FAILED";
        case NPT_ERROR_BIND_FAILED: return "NPT_ERROR_BIND_FAILED";
        case NPT_ERROR_LISTEN_FAILED: return "NPT_ERROR_LISTEN_FAILED";
        case NPT_ERROR_ACCEPT_FAILED: return "NPT_ERROR_ACCEPT_FAILED";
        case NPT_ERROR_ADDRESS_IN_USE: return "NPT_ERROR_ADDRESS_IN_USE";
        case NPT_ERROR_NETWORK_DOWN: return "NPT_ERROR_NETWORK_DOWN";
        case NPT_ERROR_NETWORK_UNREACHABLE: return "NPT_ERROR_NETWORK_UNREACHABLE";
        case NPT_ERROR_NO_SUCH_INTERFACE: return "NPT_ERROR_NO_SUCH_INTERFACE";
        case NPT_ERROR_XML_INVALID_NESTING: return "NPT_ERROR_XML_INVALID_NESTING";
        case NPT_ERROR_XML_TAG_MISMATCH: return "NPT_ERROR_XML_TAG_MISMATCH";
        case NPT_ERROR_HTTP_INVALID_RESPONSE_LINE: return "NPT_ERROR_HTTP_INVALID_RESPONSE_LINE";
        case NPT_ERROR_HTTP_INVALID_REQUEST_LINE: return "NPT_ERROR_HTTP_INVALID_REQUEST_LINE";
        case NPT_ERROR_HTTP_NO_PROXY: return "NPT_ERROR_HTTP_NO_PROXY";
        case NPT_ERROR_HTTP_INVALID_REQUEST: return "NPT_ERROR_HTTP_INVALID_REQUEST";
        case NPT_ERROR_CALLBACK_HANDLER_SHUTDOWN: return "NPT_ERROR_CALLBACK_HANDLER_SHUTDOWN";
        case NPT_ERROR_CALLBACK_NOTHING_PENDING: return "NPT_ERROR_CALLBACK_NOTHING_PENDING";
        case NPT_ERROR_NO_SUCH_SERIAL_PORT: return "NPT_ERROR_NO_SUCH_SERIAL_PORT";
        case NPT_ERROR_SERIAL_PORT_NOT_OPEN: return "NPT_ERROR_SERIAL_PORT_NOT_OPEN";
        case NPT_ERROR_SERIAL_PORT_ALREADY_OPEN: return "NPT_ERROR_SERIAL_PORT_ALREADY_OPEN";
        case NPT_ERROR_SERIAL_PORT_BUSY: return "NPT_ERROR_SERIAL_PORT_BUSY";

        default: return "UNKNOWN";
    }
}
