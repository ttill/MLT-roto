/*
 * repository.h -- provides a map between service and shared objects
 * Copyright (C) 2003-2004 Ushodaya Enterprises Limited
 * Author: Charles Yates <charles.yates@pandora.be>
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

#ifndef _MLT_REPOSITORY_H_
#define _MLT_REPOSITORY_H_

#include "mlt_types.h"

/** Repository structure forward reference.
*/

typedef struct mlt_repository_s *mlt_repository;

/** Public functions.
*/

extern mlt_repository mlt_repository_init( mlt_properties object_list, char *prefix, char *file, char *symbol );
extern void *mlt_repository_fetch( mlt_repository this, char *service, void *input );
extern void mlt_repository_close( mlt_repository this );

#endif
