/*
 * spline_handling.h
 * Copyright (C) 2011 Till Theato <root@ttill.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef ROTO_SPLINE_HANDLING_H
#define ROTO_SPLINE_HANDLING_H

#include <framework/mlt_types.h>

#include <stdlib.h>
#include <stdio.h>

#include "deformation.h"
#include "cJSON.h"

typedef struct BPointF
{
    struct PointF h1;
    struct PointF p;
    struct PointF h2;
} BPointF;


void normalizePoints( BPointF *points, int count, int width, int height );
void denormalizePoints( BPointF *points, int count, int width, int height );

/**
 * Calculates points for the cubic Bézier curve defined by \param p1 and \param p2.
 * Points are calculated until the squared distanced between neighbour points is smaller than 2.
 * \param points Pointer to list of points. Will be allocted and filled with calculated points.
 * \param count Number of calculated points in \param points
 * \param size Allocated size of \param points (in elements not in bytes)
 */
void curvePoints( BPointF p1, BPointF p2, PointF **points, int *count, int *size );

int splineAt( cJSON *root, mlt_position time, BPointF **points, int *count );

void setStatic( cJSON *root, BPointF *points );

#endif
