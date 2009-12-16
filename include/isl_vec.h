/*
 * Copyright 2008-2009 Katholieke Universiteit Leuven
 *
 * Use of this software is governed by the GNU LGPLv2.1 license
 *
 * Written by Sven Verdoolaege, K.U.Leuven, Departement
 * Computerwetenschappen, Celestijnenlaan 200A, B-3001 Leuven, Belgium
 */

#ifndef ISL_VEC_H
#define ISL_VEC_H

#include <stdio.h>

#include <isl_int.h>
#include <isl_ctx.h>
#include <isl_blk.h>

#if defined(__cplusplus)
extern "C" {
#endif

struct isl_vec {
	int ref;

	struct isl_ctx *ctx;

	unsigned size;
	isl_int *el;

	struct isl_blk block;
};
typedef struct isl_vec isl_vec;

struct isl_vec *isl_vec_alloc(struct isl_ctx *ctx, unsigned size);
struct isl_vec *isl_vec_copy(struct isl_vec *vec);
struct isl_vec *isl_vec_cow(struct isl_vec *vec);
void isl_vec_free(struct isl_vec *vec);

void isl_vec_dump(struct isl_vec *vec, FILE *out, int indent);

void isl_vec_lcm(struct isl_vec *vec, isl_int *lcm);
struct isl_vec *isl_vec_ceil(struct isl_vec *vec);
struct isl_vec *isl_vec_normalize(struct isl_vec *vec);

struct isl_vec *isl_vec_read_from_file(struct isl_ctx *ctx,
		FILE *input, unsigned input_format);

#if defined(__cplusplus)
}
#endif

#endif
