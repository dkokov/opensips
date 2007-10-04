/*
 * $Id$
 *
 * sleepycat module, portions of this code were templated using
 * the dbtext and postgres modules.

 * Copyright (C) 2007 Cisco Systems
 *
 * This file is part of openser, a free SIP server.
 *
 * openser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * openser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * History:
 * --------
 * 2007-09-19  genesis (wiquan)
 */


#ifndef _BDB_RES_H_
#define _BDB_RES_H_

#include "../../db/db_op.h"
#include "../../db/db_res.h"
#include "../../db/db_con.h"
#include "bdb_lib.h"
#include "bdb_val.h"

typedef struct _con
{
	database_p con;
	db_res_t*  res;
	row_p row;
} sc_con_t, *sc_con_p;

#define SC_CON_CONNECTION(db_con) (((sc_con_p)((db_con)->tail))->con)
#define SC_CON_RESULT(db_con)     (((sc_con_p)((db_con)->tail))->res)
#define SC_CON_ROW(db_con)        (((sc_con_p)((db_con)->tail))->row)

int sc_get_columns(table_p _tp, db_res_t* _res, int* _lres, int _nc);
int sc_convert_row( db_res_t* _res, char *bdb_result, int* _lres);
int sc_append_row(db_res_t* _res, char *bdb_result, int* _lres, int _rx);
int* sc_get_colmap(table_p _tp, db_key_t* _k, int _n);

db_res_t*  sc_result_new(void);
int sc_free_result(db_res_t* _res);
int sc_free_columns(db_res_t* _res);
int sc_free_rows(db_res_t* _res);
int sc_free_row(db_row_t* _row);

int sc_is_neq_type(db_type_t _t0, db_type_t _t1);
int sc_row_match(db_key_t* _k, db_op_t* _op, db_val_t* _v, int _n, db_res_t* _r, int* lkey );
int sc_cmp_val(db_val_t* _vp, db_val_t* _v);

#endif

