/*
 * vim:expandtab:shiftwidth=8:tabstop=8:
 *
 * Copyright CEA/DAM/DIF  (2008)
 * contributeur : Philippe DENIEL   philippe.deniel@cea.fr
 *                Thomas LEIBOVICI  thomas.leibovici@cea.fr
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * ---------------------------------------
 */

/**
 * @file    nfs4_op_reclaim_complete.c
 * @brief   Routines used for managing the NFS4 COMPOUND functions.
 *
 * Routines used for managing the NFS4 COMPOUND functions.
 *
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef _SOLARIS
#include "solaris_port.h"
#endif

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/file.h>           /* for having FNDELAY */
#include "HashTable.h"
#include "log.h"
#include "ganesha_rpc.h"
#include "nfs23.h"
#include "nfs4.h"
#include "mount.h"
#include "nfs_core.h"
#include "cache_inode.h"
#include "nfs_exports.h"
#include "nfs_creds.h"
#include "nfs_proto_functions.h"
#include "nfs_file_handle.h"
#include "nfs_tools.h"

/**
 *
 * @brief The NFS4_OP_RECLAIM_COMPLETE4 operation.
 *
 * This function implements the NFS4_OP_RECLAIM_COMPLETE4 operation.
 *
 * @param[in]     op    Arguments for the nfs4_op
 * @param[in,out] data  Compound request's data
 * @param[out]    resp  Retuls for the nfs4_op
 *
 * @return per RFC5661 p. 372
 *
 * @see nfs4_Compound
 *
 */

#define arg_RECLAIM_COMPLETE4 op->nfs_argop4_u.opreclaim_complete
#define res_RECLAIM_COMPLETE4 resp->nfs_resop4_u.opreclaim_complete

int nfs4_op_reclaim_complete(struct nfs_argop4 *op,
                             compound_data_t *data,
                             struct nfs_resop4 *resp)
{
  resp->resop = NFS4_OP_RECLAIM_COMPLETE;

  res_RECLAIM_COMPLETE4.rcr_status = NFS4_OK;
  if (data->minorversion == 0)
    {
      return (res_RECLAIM_COMPLETE4.rcr_status = NFS4ERR_INVAL);
    }
  return res_RECLAIM_COMPLETE4.rcr_status;
} /* nfs41_op_reclaim_complete */

/**
 * @brief Free memory allocated for RECLAIM_COMPLETE result
 *
 * This function frees anty memory allocated for the result of the
 * NFS4_OP_RECLAIM_COMPLETE operation.
 */
void nfs4_op_reclaim_complete_Free(RECLAIM_COMPLETE4res *resp)
{
  return;
} /* nfs41_op_reclaim_complete_Free */