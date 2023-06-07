#ifndef EVT_H
#define EVT_H

#include "postgres.h"
#include "utils/builtins.h"

#include "parser/parse_func.h"
#include "parser/parse_node.h"
#include "parser/parse_oper.h"
#include "utils/builtins.h"
#include "utils/lsyscache.h"
#include "utils/selfuncs.h"
#include "utils/syscache.h"
#include "utils/typcache.h"
#include "commands/event_trigger.h"

PG_MODULE_MAGIC;

Datum force_constraint_not_valid_sql(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(force_constraint_not_valid_sql);
void force_constraint_not_valid(Node *parsetree);


#endif							/* EVT_H */
