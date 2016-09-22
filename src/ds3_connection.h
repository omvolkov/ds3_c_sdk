
/*
 * ******************************************************************************
 *   Copyright 2014-2016 Spectra Logic Corporation. All Rights Reserved.
 *   Licensed under the Apache License, Version 2.0 (the "License"). You may not use
 *   this file except in compliance with the License. A copy of the License is located at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *   or in the "license" file accompanying this file.
 *   This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 *   CONDITIONS OF ANY KIND, either express or implied. See the License for the
 *   specific language governing permissions and limitations under the License.
 * ****************************************************************************
 */

#ifndef __DS3_CONNECTION_H__
#define __DS3_CONNECTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <curl/curl.h>
#include <glib.h>

#define CONNECTION_POOL_SIZE 100

typedef GMutex _ds3_mutex;
typedef GCond _ds3_condition;

typedef CURL _ds3_connection;

//-- Opaque struct
struct _ds3_connection_pool{
    _ds3_connection* connections[CONNECTION_POOL_SIZE];
    int head;
    int tail;
    _ds3_mutex mutex;
    _ds3_condition available_connections;
};

#ifdef __cplusplus
}
#endif
#endif
