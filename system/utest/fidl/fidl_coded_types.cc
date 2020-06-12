// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "fidl_coded_types.h"

#include <lib/fidl/internal.h>

#include "fidl_structs.h"

namespace {

// All sizes in fidl encoding tables are 32 bits. The fidl compiler
// normally enforces this. Check manually in manual tests.
template <typename T, size_t N>
uint32_t ArrayCount(T const (&array)[N]) {
  static_assert(N < UINT32_MAX, "Array is too large!");
  return N;
}

}  // namespace

// Handle types.
const FidlCodedHandle nonnullable_handle = {
    .tag = kFidlTypeHandle,
    .nullable = kFidlNullability_Nonnullable,
    .handle_subtype = ZX_OBJ_TYPE_NONE,
    .handle_rights = ZX_RIGHT_SAME_RIGHTS,
};
const FidlCodedHandle nullable_handle = {
    .tag = kFidlTypeHandle,
    .nullable = kFidlNullability_Nullable,
    .handle_subtype = ZX_OBJ_TYPE_NONE,
    .handle_rights = 0,
};
const FidlCodedHandle nullable_channel_handle = {
    .tag = kFidlTypeHandle,
    .nullable = kFidlNullability_Nullable,
    .handle_subtype = ZX_OBJ_TYPE_CHANNEL,
    .handle_rights = ZX_RIGHT_READ | ZX_RIGHT_WRITE,
};
const FidlCodedHandle nullable_vmo_handle = {
    .tag = kFidlTypeHandle,
    .nullable = kFidlNullability_Nullable,
    .handle_subtype = ZX_OBJ_TYPE_VMO,
    .handle_rights = 0,
};
const FidlCodedHandle nonnullable_channel_handle = {
    .tag = kFidlTypeHandle,
    .nullable = kFidlNullability_Nonnullable,
    .handle_subtype = ZX_OBJ_TYPE_CHANNEL,
    .handle_rights = ZX_RIGHT_READ | ZX_RIGHT_WRITE,
};
const FidlCodedHandle nonnullable_vmo_handle = {
    .tag = kFidlTypeHandle,
    .nullable = kFidlNullability_Nonnullable,
    .handle_subtype = ZX_OBJ_TYPE_VMO,
    .handle_rights = 0,
};

// Array types.
const FidlCodedArray array_of_two_nonnullable_handles = {
    .tag = kFidlTypeArray,
    .element_size = sizeof(zx_handle_t),
    .array_size = 2 * sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedArray array_of_four_nonnullable_handles = {
    .tag = kFidlTypeArray,
    .element_size = sizeof(zx_handle_t),
    .array_size = 4 * sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedArray array_of_five_nullable_handles = {
    .tag = kFidlTypeArray,
    .element_size = sizeof(zx_handle_t),
    .array_size = 5 * sizeof(zx_handle_t),
    .element = &nullable_handle,
};
const FidlCodedArray array_of_three_arrays_of_four_nonnullable_handles = {
    .tag = kFidlTypeArray,
    .element_size = 4 * sizeof(zx_handle_t),
    .array_size = 3 * 4 * sizeof(zx_handle_t),
    .element = &array_of_four_nonnullable_handles,
};
const FidlCodedArray array_of_two_arrays_of_two_nonnullable_handles = {
    .tag = kFidlTypeArray,
    .element_size = 2 * sizeof(zx_handle_t),
    .array_size = 2 * 2 * sizeof(zx_handle_t),
    .element = &array_of_two_nonnullable_handles,
};

// String types.
const FidlCodedString unbounded_nonnullable_string = {
    .tag = kFidlTypeString,
    .nullable = kFidlNullability_Nonnullable,
    .max_size = FIDL_MAX_SIZE,
};
const FidlCodedString unbounded_nullable_string = {
    .tag = kFidlTypeString,
    .nullable = kFidlNullability_Nullable,
    .max_size = FIDL_MAX_SIZE,
};
const FidlCodedString bounded_32_nonnullable_string = {
    .tag = kFidlTypeString,
    .nullable = kFidlNullability_Nonnullable,
    .max_size = 32,
};
const FidlCodedString bounded_32_nullable_string = {
    .tag = kFidlTypeString,
    .nullable = kFidlNullability_Nullable,
    .max_size = 32,
};
const FidlCodedString bounded_4_nonnullable_string = {
    .tag = kFidlTypeString,
    .nullable = kFidlNullability_Nonnullable,
    .max_size = 4,
};
const FidlCodedString bounded_4_nullable_string = {
    .tag = kFidlTypeString,
    .nullable = kFidlNullability_Nullable,
    .max_size = 4,
};

// Vector types.
const FidlCodedVector unbounded_nonnullable_vector_of_handles = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nonnullable,
    .max_count = FIDL_MAX_SIZE,
    .element_size = sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedVector unbounded_nullable_vector_of_handles = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nullable,
    .max_count = FIDL_MAX_SIZE,
    .element_size = sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedVector bounded_32_nonnullable_vector_of_handles = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nonnullable,
    .max_count = 32,
    .element_size = sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedVector bounded_32_nullable_vector_of_handles = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nullable,
    .max_count = 32,
    .element_size = sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedVector bounded_2_nonnullable_vector_of_handles = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nonnullable,
    .max_count = 2,
    .element_size = sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};
const FidlCodedVector bounded_2_nullable_vector_of_handles = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nullable,
    .max_count = 2,
    .element_size = sizeof(zx_handle_t),
    .element = &nonnullable_handle,
};

const FidlCodedVector unbounded_nonnullable_vector_of_uint32 = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nonnullable,
    .max_count = FIDL_MAX_SIZE,
    .element_size = sizeof(uint32_t),
    .element = nullptr,
};
const FidlCodedVector unbounded_nullable_vector_of_uint32 = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nullable,
    .max_count = FIDL_MAX_SIZE,
    .element_size = sizeof(uint32_t),
    .element = nullptr,
};
const FidlCodedVector bounded_32_nonnullable_vector_of_uint32 = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nonnullable,
    .max_count = 32,
    .element_size = sizeof(uint32_t),
    .element = nullptr,
};
const FidlCodedVector bounded_32_nullable_vector_of_uint32 = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nullable,
    .max_count = 32,
    .element_size = sizeof(uint32_t),
    .element = nullptr,
};
const FidlCodedVector bounded_2_nonnullable_vector_of_uint32 = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nonnullable,
    .max_count = 2,
    .element_size = sizeof(uint32_t),
    .element = nullptr,
};
const FidlCodedVector bounded_2_nullable_vector_of_uint32 = {
    .tag = kFidlTypeVector,
    .nullable = kFidlNullability_Nullable,
    .max_count = 2,
    .element_size = sizeof(uint32_t),
    .element = nullptr,
};

// Handle messages.
static const FidlStructField nonnullable_handle_message_fields[] = {
    FidlStructField(&nonnullable_handle,
                    offsetof(nonnullable_handle_message_layout, inline_struct.handle), 4),
};
const FidlCodedStruct nonnullable_handle_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(nonnullable_handle_message_fields),
    .size = sizeof(nonnullable_handle_inline_data),
    .fields = nonnullable_handle_message_fields,
    .name = "nonnullable_handle_message",
};

static const FidlStructField nonnullable_channel_message_fields[] = {
    FidlStructField(&nonnullable_channel_handle,
                    offsetof(nonnullable_handle_message_layout, inline_struct.handle), 4),
};
const FidlCodedStruct nonnullable_channel_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(nonnullable_channel_message_fields),
    .size = sizeof(nonnullable_handle_inline_data),
    .fields = nonnullable_channel_message_fields,
    .name = "nonnullable_channel_message",
};

static const FidlStructField multiple_nonnullable_handles_fields[] = {
    FidlStructField(&nonnullable_handle,
                    offsetof(multiple_nonnullable_handles_message_layout, inline_struct.handle_0),
                    0),
    FidlStructField(&nonnullable_channel_handle,
                    offsetof(multiple_nonnullable_handles_message_layout, inline_struct.handle_1),
                    0),
    FidlStructField(&nonnullable_vmo_handle,
                    offsetof(multiple_nonnullable_handles_message_layout, inline_struct.handle_2),
                    0),
};
const FidlCodedStruct multiple_nonnullable_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nonnullable_handles_fields),
    .size = sizeof(multiple_nonnullable_handles_inline_data),
    .fields = multiple_nonnullable_handles_fields,
    .name = "multiple_nonnullable_handles_message",
};

static const FidlStructField nullable_handle_fields[] = {
    FidlStructField(&nullable_handle,
                    offsetof(nullable_handle_message_layout, inline_struct.handle), 4),

};
const FidlCodedStruct nullable_handle_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(nullable_handle_fields),
    .size = sizeof(nullable_handle_inline_data),
    .fields = nullable_handle_fields,
    .name = "nullable_handle_message",
};

static const FidlStructField multiple_nullable_handles_fields[] = {
    FidlStructField(&nullable_handle,
                    offsetof(multiple_nullable_handles_message_layout, inline_struct.handle_0), 0),
    FidlStructField(&nullable_channel_handle,
                    offsetof(multiple_nullable_handles_message_layout, inline_struct.handle_1), 0),
    FidlStructField(&nullable_vmo_handle,
                    offsetof(multiple_nullable_handles_message_layout, inline_struct.handle_2), 0),
};
const FidlCodedStruct multiple_nullable_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nullable_handles_fields),
    .size = sizeof(multiple_nullable_handles_inline_data),
    .fields = multiple_nullable_handles_fields,
    .name = "multiple_nullable_handles_message",
};

// Array messages.
static const FidlStructField array_of_nonnullable_handles_fields[] = {
    FidlStructField(&array_of_four_nonnullable_handles,
                    offsetof(array_of_nonnullable_handles_message_layout, inline_struct.handles),
                    0),
};
const FidlCodedStruct array_of_nonnullable_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(array_of_nonnullable_handles_fields),
    .size = sizeof(array_of_nonnullable_handles_inline_data),
    .fields = array_of_nonnullable_handles_fields,
    .name = "array_of_nonnullable_handles_message",
};

static const FidlStructField array_of_nullable_handles_fields[] = {
    FidlStructField(&array_of_five_nullable_handles,
                    offsetof(array_of_nullable_handles_message_layout, inline_struct.handles), 0),
};
const FidlCodedStruct array_of_nullable_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(array_of_nullable_handles_fields),
    .size = sizeof(array_of_nullable_handles_inline_data),
    .fields = array_of_nullable_handles_fields,
    .name = "array_of_nullable_handles_message",
};

static const FidlStructField array_of_array_of_nonnullable_handles_fields[] = {
    FidlStructField(
        &array_of_three_arrays_of_four_nonnullable_handles,
        offsetof(array_of_array_of_nonnullable_handles_message_layout, inline_struct.handles), 0),
};
const FidlCodedStruct array_of_array_of_nonnullable_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(array_of_array_of_nonnullable_handles_fields),
    .size = sizeof(array_of_array_of_nonnullable_handles_inline_data),
    .fields = array_of_array_of_nonnullable_handles_fields,
    .name = "array_of_array_of_nonnullable_handles_message",
};

static const FidlStructField out_of_line_fields[] = {
    FidlStructField(&array_of_four_nonnullable_handles,
                    offsetof(array_of_nonnullable_handles, handles), 0),

};
static const FidlCodedStruct out_of_line_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(out_of_line_fields),
    .size = sizeof(array_of_nonnullable_handles),
    .fields = out_of_line_fields,
    .name = "out_of_line",
};
static const FidlCodedStructPointer out_of_line_pointer_type = {
    .tag = kFidlTypeStructPointer,
    .struct_type = &out_of_line_type.coded_struct(),
};

static const FidlStructField out_of_line_array_of_nonnullable_handles_fields[] = {
    FidlStructField(&out_of_line_pointer_type,
                    offsetof(out_of_line_array_of_nonnullable_handles_message_layout,
                             inline_struct.maybe_array),
                    0),
};
const FidlCodedStruct out_of_line_array_of_nonnullable_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(out_of_line_array_of_nonnullable_handles_fields),
    .size = sizeof(out_of_line_array_of_nonnullable_handles_inline_data),
    .fields = out_of_line_array_of_nonnullable_handles_fields,
    .name = "out_of_line_array_of_nonnullable_handles_message",
};

// String messages.
static const FidlStructField unbounded_nonnullable_string_fields[] = {
    FidlStructField(&unbounded_nonnullable_string,
                    offsetof(unbounded_nonnullable_string_message_layout, inline_struct.string), 0),

};
const FidlCodedStruct unbounded_nonnullable_string_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(unbounded_nonnullable_string_fields),
    .size = sizeof(unbounded_nonnullable_string_inline_data),
    .fields = unbounded_nonnullable_string_fields,
    .name = "unbounded_nonnullable_string_message",
};

static const FidlStructField unbounded_nullable_string_fields[] = {
    FidlStructField(&unbounded_nullable_string,
                    offsetof(unbounded_nullable_string_message_layout, inline_struct.string), 0),

};
const FidlCodedStruct unbounded_nullable_string_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(unbounded_nullable_string_fields),
    .size = sizeof(unbounded_nullable_string_inline_data),
    .fields = unbounded_nullable_string_fields,
    .name = "unbounded_nullable_string_message",
};

static const FidlStructField bounded_32_nonnullable_string_fields[] = {
    FidlStructField(&bounded_32_nonnullable_string,
                    offsetof(bounded_32_nonnullable_string_message_layout, inline_struct.string),
                    0),

};
const FidlCodedStruct bounded_32_nonnullable_string_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(bounded_32_nonnullable_string_fields),
    .size = sizeof(bounded_32_nonnullable_string_inline_data),
    .fields = bounded_32_nonnullable_string_fields,
    .name = "bounded_32_nonnullable_string_message",
};

static const FidlStructField bounded_32_nullable_string_fields[] = {
    FidlStructField(&bounded_32_nullable_string,
                    offsetof(bounded_32_nullable_string_message_layout, inline_struct.string), 0),
};
const FidlCodedStruct bounded_32_nullable_string_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(bounded_32_nullable_string_fields),
    .size = sizeof(bounded_32_nullable_string_inline_data),
    .fields = bounded_32_nullable_string_fields,
    .name = "bounded_32_nullable_string_message",
};

static const FidlStructField multiple_nonnullable_strings_fields[] = {
    FidlStructField(&bounded_32_nonnullable_string,
                    offsetof(multiple_nonnullable_strings_message_layout, inline_struct.string), 0),

    FidlStructField(&bounded_32_nonnullable_string,
                    offsetof(multiple_nonnullable_strings_message_layout, inline_struct.string2),
                    0),
};
const FidlCodedStruct multiple_nonnullable_strings_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nonnullable_strings_fields),
    .size = sizeof(multiple_nonnullable_strings_inline_data),
    .fields = multiple_nonnullable_strings_fields,
    .name = "multiple_nonnullable_strings_message",
};

static const FidlStructField multiple_nullable_strings_fields[] = {
    FidlStructField(&bounded_32_nullable_string,
                    offsetof(multiple_nullable_strings_message_layout, inline_struct.string), 0),

    FidlStructField(&bounded_32_nullable_string,
                    offsetof(multiple_nullable_strings_message_layout, inline_struct.string2), 0),
};
const FidlCodedStruct multiple_nullable_strings_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nullable_strings_fields),
    .size = sizeof(multiple_nullable_strings_inline_data),
    .fields = multiple_nullable_strings_fields,
    .name = "multiple_nullable_strings_message",
};

static const FidlStructField multiple_short_nonnullable_strings_fields[] = {
    FidlStructField(
        &bounded_4_nonnullable_string,
        offsetof(multiple_short_nonnullable_strings_message_layout, inline_struct.string), 0),

    FidlStructField(
        &bounded_32_nonnullable_string,
        offsetof(multiple_short_nonnullable_strings_message_layout, inline_struct.string2), 0),
};
const FidlCodedStruct multiple_short_nonnullable_strings_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_short_nonnullable_strings_fields),
    .size = sizeof(multiple_short_nonnullable_strings_inline_data),
    .fields = multiple_short_nonnullable_strings_fields,
    .name = "multiple_short_nonnullable_strings_message",
};

static const FidlStructField multiple_short_nullable_strings_fields[] = {
    FidlStructField(&bounded_4_nullable_string,
                    offsetof(multiple_short_nullable_strings_message_layout, inline_struct.string),
                    0),

    FidlStructField(&bounded_32_nullable_string,
                    offsetof(multiple_short_nullable_strings_message_layout, inline_struct.string2),
                    0),
};
const FidlCodedStruct multiple_short_nullable_strings_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_short_nullable_strings_fields),
    .size = sizeof(multiple_short_nullable_strings_inline_data),
    .fields = multiple_short_nullable_strings_fields,
    .name = "multiple_short_nullable_strings_message",
};

// Vector messages.
static const FidlStructField unbounded_nonnullable_vector_of_handles_fields[] = {
    FidlStructField(
        &unbounded_nonnullable_vector_of_handles,
        offsetof(unbounded_nonnullable_vector_of_handles_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct unbounded_nonnullable_vector_of_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(unbounded_nonnullable_vector_of_handles_fields),
    .size = sizeof(unbounded_nonnullable_vector_of_handles_inline_data),
    .fields = unbounded_nonnullable_vector_of_handles_fields,
    .name = "unbounded_nonnullable_vector_of_handles_message",
};

static const FidlStructField unbounded_nullable_vector_of_handles_fields[] = {
    FidlStructField(
        &unbounded_nullable_vector_of_handles,
        offsetof(unbounded_nullable_vector_of_handles_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct unbounded_nullable_vector_of_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(unbounded_nullable_vector_of_handles_fields),
    .size = sizeof(unbounded_nullable_vector_of_handles_inline_data),
    .fields = unbounded_nullable_vector_of_handles_fields,
    .name = "unbounded_nullable_vector_of_handles_message",
};

static const FidlStructField bounded_32_nonnullable_vector_of_handles_fields[] = {
    FidlStructField(
        &bounded_32_nonnullable_vector_of_handles,
        offsetof(bounded_32_nonnullable_vector_of_handles_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct bounded_32_nonnullable_vector_of_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(bounded_32_nonnullable_vector_of_handles_fields),
    .size = sizeof(bounded_32_nonnullable_vector_of_handles_inline_data),
    .fields = bounded_32_nonnullable_vector_of_handles_fields,
    .name = "bounded_32_nonnullable_vector_of_handles_message",
};

static const FidlStructField bounded_32_nullable_vector_of_handles_fields[] = {
    FidlStructField(
        &bounded_32_nullable_vector_of_handles,
        offsetof(bounded_32_nullable_vector_of_handles_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct bounded_32_nullable_vector_of_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(bounded_32_nullable_vector_of_handles_fields),
    .size = sizeof(bounded_32_nullable_vector_of_handles_inline_data),
    .fields = bounded_32_nullable_vector_of_handles_fields,
    .name = "bounded_32_nullable_vector_of_handles_message",
};

static const FidlStructField multiple_nonnullable_vectors_of_handles_fields[] = {
    FidlStructField(
        &bounded_2_nonnullable_vector_of_handles,
        offsetof(multiple_nonnullable_vectors_of_handles_message_layout, inline_struct.vector), 0),
    FidlStructField(
        &unbounded_nonnullable_vector_of_handles,
        offsetof(multiple_nonnullable_vectors_of_handles_message_layout, inline_struct.vector2), 0),
};
const FidlCodedStruct multiple_nonnullable_vectors_of_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nonnullable_vectors_of_handles_fields),
    .size = sizeof(multiple_nonnullable_vectors_of_handles_inline_data),
    .fields = multiple_nonnullable_vectors_of_handles_fields,
    .name = "multiple_nonnullable_vectors_of_handles_message",
};

static const FidlStructField multiple_nullable_vectors_of_handles_fields[] = {
    FidlStructField(
        &bounded_2_nullable_vector_of_handles,
        offsetof(multiple_nullable_vectors_of_handles_message_layout, inline_struct.vector), 0),
    FidlStructField(
        &unbounded_nullable_vector_of_handles,
        offsetof(multiple_nullable_vectors_of_handles_message_layout, inline_struct.vector2), 0),
};
const FidlCodedStruct multiple_nullable_vectors_of_handles_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nullable_vectors_of_handles_fields),
    .size = sizeof(multiple_nullable_vectors_of_handles_inline_data),
    .fields = multiple_nullable_vectors_of_handles_fields,
    .name = "multiple_nullable_vectors_of_handles_message",
};

static const FidlStructField unbounded_nonnullable_vector_of_uint32_fields[] = {
    FidlStructField(
        &unbounded_nonnullable_vector_of_uint32,
        offsetof(unbounded_nonnullable_vector_of_uint32_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct unbounded_nonnullable_vector_of_uint32_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(unbounded_nonnullable_vector_of_uint32_fields),
    .size = sizeof(unbounded_nonnullable_vector_of_uint32_inline_data),
    .fields = unbounded_nonnullable_vector_of_uint32_fields,
    .name = "unbounded_nonnullable_vector_of_uint32_message",
};

static const FidlStructField unbounded_nullable_vector_of_uint32_fields[] = {
    FidlStructField(
        &unbounded_nullable_vector_of_uint32,
        offsetof(unbounded_nullable_vector_of_uint32_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct unbounded_nullable_vector_of_uint32_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(unbounded_nullable_vector_of_uint32_fields),
    .size = sizeof(unbounded_nullable_vector_of_uint32_inline_data),
    .fields = unbounded_nullable_vector_of_uint32_fields,
    .name = "unbounded_nullable_vector_of_uint32_message",
};

static const FidlStructField bounded_32_nonnullable_vector_of_uint32_fields[] = {
    FidlStructField(
        &bounded_32_nonnullable_vector_of_uint32,
        offsetof(bounded_32_nonnullable_vector_of_uint32_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct bounded_32_nonnullable_vector_of_uint32_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(bounded_32_nonnullable_vector_of_uint32_fields),
    .size = sizeof(bounded_32_nonnullable_vector_of_uint32_inline_data),
    .fields = bounded_32_nonnullable_vector_of_uint32_fields,
    .name = "bounded_32_nonnullable_vector_of_uint32_message",
};

static const FidlStructField bounded_32_nullable_vector_of_uint32_fields[] = {
    FidlStructField(
        &bounded_32_nullable_vector_of_uint32,
        offsetof(bounded_32_nullable_vector_of_uint32_message_layout, inline_struct.vector), 0),

};
const FidlCodedStruct bounded_32_nullable_vector_of_uint32_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(bounded_32_nullable_vector_of_uint32_fields),
    .size = sizeof(bounded_32_nullable_vector_of_uint32_inline_data),
    .fields = bounded_32_nullable_vector_of_uint32_fields,
    .name = "bounded_32_nullable_vector_of_uint32_message",
};

static const FidlStructField multiple_nonnullable_vectors_of_uint32_fields[] = {
    FidlStructField(
        &bounded_2_nonnullable_vector_of_uint32,
        offsetof(multiple_nonnullable_vectors_of_uint32_message_layout, inline_struct.vector), 0),
    FidlStructField(
        &unbounded_nonnullable_vector_of_uint32,
        offsetof(multiple_nonnullable_vectors_of_uint32_message_layout, inline_struct.vector2), 0),
};
const FidlCodedStruct multiple_nonnullable_vectors_of_uint32_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nonnullable_vectors_of_uint32_fields),
    .size = sizeof(multiple_nonnullable_vectors_of_uint32_inline_data),
    .fields = multiple_nonnullable_vectors_of_uint32_fields,
    .name = "multiple_nonnullable_vectors_of_uint32_message",
};

static const FidlStructField multiple_nullable_vectors_of_uint32_fields[] = {
    FidlStructField(
        &bounded_2_nullable_vector_of_uint32,
        offsetof(multiple_nullable_vectors_of_uint32_message_layout, inline_struct.vector), 0),
    FidlStructField(
        &unbounded_nullable_vector_of_uint32,
        offsetof(multiple_nullable_vectors_of_uint32_message_layout, inline_struct.vector2), 0),
};
const FidlCodedStruct multiple_nullable_vectors_of_uint32_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(multiple_nullable_vectors_of_uint32_fields),
    .size = sizeof(multiple_nullable_vectors_of_uint32_inline_data),
    .fields = multiple_nullable_vectors_of_uint32_fields,
    .name = "multiple_nullable_vectors_of_uint32_message",
};


// Struct messages.
static const FidlStructField struct_level_3_fields[] = {
    FidlStructField(&nonnullable_handle, offsetof(struct_level_3, handle_3), 0),
};
static const FidlCodedStruct struct_level_3_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_level_3_fields),
    .size = sizeof(struct_level_3),
    .fields = struct_level_3_fields,
    .name = "struct_level_3",
};
static const FidlStructField struct_level_2_fields[] = {
    FidlStructField(&struct_level_3_struct, offsetof(struct_level_2, l3), 0),
    FidlStructField(&nonnullable_handle, offsetof(struct_level_2, handle_2), 4),
};
static const FidlCodedStruct struct_level_2_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_level_2_fields),
    .size = sizeof(struct_level_2),
    .fields = struct_level_2_fields,
    .name = "struct_level_2",
};
static const FidlStructField struct_level_1_fields[] = {
    FidlStructField(&nonnullable_handle, offsetof(struct_level_1, handle_1), 4),
    FidlStructField(&struct_level_2_struct, offsetof(struct_level_1, l2), 0),
};
static const FidlCodedStruct struct_level_1_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_level_1_fields),
    .size = sizeof(struct_level_1),
    .fields = struct_level_1_fields,
    .name = "struct_level_1",
};
static const FidlStructField struct_level_0_fields[] = {
    FidlStructField(&struct_level_1_struct, offsetof(struct_level_0, l1), 0),
    FidlStructField(&nonnullable_handle, offsetof(struct_level_0, handle_0), 4),
};
const FidlCodedStruct struct_level_0_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_level_1_fields),
    .size = sizeof(struct_level_0),
    .fields = struct_level_0_fields,
    .name = "struct_level_0",
};
static const FidlStructField nested_structs_fields[] = {
    FidlStructField(&struct_level_0_struct,
                    offsetof(nested_structs_message_layout, inline_struct.l0), 0),

};
const FidlCodedStruct nested_structs_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(nested_structs_fields),
    .size = sizeof(nested_structs_inline_data),
    .fields = nested_structs_fields,
    .name = "nested_structs_message",
};

// Struct pointer messages.
static const FidlStructField struct_ptr_level_3_fields[] = {
    FidlStructField(&nonnullable_handle, offsetof(struct_ptr_level_3, handle_3), 0),
};
static const FidlCodedStruct struct_ptr_level_3_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_ptr_level_3_fields),
    .size = sizeof(struct_ptr_level_3),
    .fields = struct_ptr_level_3_fields,
    .name = "struct_ptr_level_3",
};
static const FidlCodedStructPointer struct_ptr_level_3_struct_pointer = {
    .tag = kFidlTypeStructPointer,
    .struct_type = &struct_ptr_level_3_struct.coded_struct(),
};
static const FidlStructField struct_ptr_level_2_fields[] = {
    FidlStructField(&struct_ptr_level_3_struct_pointer, offsetof(struct_ptr_level_2, l3_present),
                    0),
    FidlStructField(&struct_ptr_level_3_struct_pointer, offsetof(struct_ptr_level_2, l3_absent), 0),
    FidlStructField(&struct_ptr_level_3_struct, offsetof(struct_ptr_level_2, l3_inline), 0),
    FidlStructField(&nonnullable_handle, offsetof(struct_ptr_level_2, handle_2), 4),
};
static const FidlCodedStruct struct_ptr_level_2_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_ptr_level_2_fields),
    .size = sizeof(struct_ptr_level_2),
    .fields = struct_ptr_level_2_fields,
    .name = "struct_ptr_level_2",
};
static const FidlCodedStructPointer struct_ptr_level_2_struct_pointer = {
    .tag = kFidlTypeStructPointer,
    .struct_type = &struct_ptr_level_2_struct.coded_struct(),
};
static const FidlStructField struct_ptr_level_1_fields[] = {
    FidlStructField(&nonnullable_handle, offsetof(struct_ptr_level_1, handle_1), 4),
    FidlStructField(&struct_ptr_level_2_struct_pointer, offsetof(struct_ptr_level_1, l2_present),
                    0),
    FidlStructField(&struct_ptr_level_2_struct, offsetof(struct_ptr_level_1, l2_inline), 0),
    FidlStructField(&struct_ptr_level_2_struct_pointer, offsetof(struct_ptr_level_1, l2_absent), 0),
};
static const FidlCodedStruct struct_ptr_level_1_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_ptr_level_1_fields),
    .size = sizeof(struct_ptr_level_1),
    .fields = struct_ptr_level_1_fields,
    .name = "struct_ptr_level_1",
};
static const FidlCodedStructPointer struct_ptr_level_1_struct_pointer = {
    .tag = kFidlTypeStructPointer,
    .struct_type = &struct_ptr_level_1_struct.coded_struct(),
};
static const FidlStructField struct_ptr_level_0_fields[] = {
    FidlStructField(&struct_ptr_level_1_struct_pointer, offsetof(struct_ptr_level_0, l1_absent), 0),
    FidlStructField(&struct_ptr_level_1_struct, offsetof(struct_ptr_level_0, l1_inline), 0),
    FidlStructField(&nonnullable_handle, offsetof(struct_ptr_level_0, handle_0), 4),
    FidlStructField(&struct_ptr_level_1_struct_pointer, offsetof(struct_ptr_level_0, l1_present),
                    0),
};
static const FidlCodedStruct struct_ptr_level_0_struct = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(struct_ptr_level_0_fields),
    .size = sizeof(struct_ptr_level_0),
    .fields = struct_ptr_level_0_fields,
    .name = "struct_ptr_level_0",
};
const FidlCodedStructPointer struct_ptr_level_0_struct_pointer = {
    .tag = kFidlTypeStructPointer,
    .struct_type = &struct_ptr_level_0_struct.coded_struct(),
};
static const FidlStructField nested_struct_ptrs_fields[] = {
    FidlStructField(&struct_ptr_level_0_struct, offsetof(nested_struct_ptrs_inline_data, l0_inline),
                    0),
    FidlStructField(&struct_ptr_level_0_struct_pointer,
                    offsetof(nested_struct_ptrs_inline_data, l0_absent), 0),
    FidlStructField(&struct_ptr_level_0_struct_pointer,
                    offsetof(nested_struct_ptrs_inline_data, l0_present), 0),
};
const FidlCodedStruct nested_struct_ptrs_message_type = {
    .tag = kFidlTypeStruct,
    .field_count = ArrayCount(nested_struct_ptrs_fields),
    .size = sizeof(nested_struct_ptrs_inline_data),
    .fields = nested_struct_ptrs_fields,
    .name = "nested_struct_ptrs_message",
};
