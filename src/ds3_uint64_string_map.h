/*
 * ******************************************************************************
 *   Copyright 2014-2017 Spectra Logic Corporation. All Rights Reserved.
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

#ifndef __DS3_UINT64_T_STRING_MAP__
#define __DS3_UINT64_T_STRING_MAP__

#include <stdlib.h>

#include "stdint.h"
#include "ds3_bool.h"
#include "ds3_string.h"
#include "ds3_library_exports.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ds3_uint64_string_map ds3_uint64_string_map;

LIBRARY_API ds3_uint64_string_map* ds3_uint64_string_map_init(void);
LIBRARY_API ds3_bool ds3_uint64_string_map_insert(ds3_uint64_string_map* map, const uint64_t* key, const ds3_str* value);
LIBRARY_API ds3_bool ds3_uint64_string_map_contains(ds3_uint64_string_map* map, uint64_t* key);
LIBRARY_API ds3_str* ds3_uint64_string_map_lookup(ds3_uint64_string_map* map, uint64_t* key);
LIBRARY_API void     ds3_uint64_string_map_free(ds3_uint64_string_map* map);
LIBRARY_API uint64_t    ds3_uint64_string_map_size(ds3_uint64_string_map* map);

typedef struct _ds3_uint64_string_map_iter ds3_uint64_string_map_iter;

// Used to encapsulate a safe key-value pair of the ds3_uint64_string_map during iteration.
struct _ds3_uint64_string_pair {
    uint64_t key;
    ds3_str* value;
};

typedef struct _ds3_uint64_string_pair ds3_uint64_string_pair;

LIBRARY_API void ds3_uint64_string_pair_free(ds3_uint64_string_pair* pair);

LIBRARY_API ds3_uint64_string_map_iter* ds3_uint64_string_map_iter_init(ds3_uint64_string_map* map);
LIBRARY_API ds3_uint64_string_pair* ds3_uint64_string_map_iter_next(ds3_uint64_string_map_iter* iter);
LIBRARY_API void     ds3_uint64_string_map_iter_free(ds3_uint64_string_map_iter* iter);

#ifdef __cplusplus
}
#endif
#endif
