#include <evt.h>

Datum
force_constraint_not_valid_sql(PG_FUNCTION_ARGS)
{
	EventTriggerData *trigdata;

	if (!CALLED_AS_EVENT_TRIGGER(fcinfo))  /* internal error */
		elog(ERROR, "not fired by event trigger manager");

	trigdata = (EventTriggerData *) fcinfo->context;
	force_constraint_not_valid(trigdata->parsetree);

	PG_RETURN_NULL();
}

void
force_constraint_not_valid(Node *parsetree)
{
	AlterTableStmt *at_stmt;
	ListCell	   *lcmd;

	/* FIXME: Same thing might need to be handled within CREATE TABLE command */
	if (nodeTag(parsetree) == T_AlterTableStmt)
	{
		at_stmt=castNode(AlterTableStmt, parsetree);

		/* ADD CONSTRAINT requires parse transformation */
		foreach(lcmd, at_stmt->cmds)
		{
			AlterTableCmd *cmd = (AlterTableCmd *) lfirst(lcmd);

			if (cmd->subtype == AT_AddConstraint)
			{
				Constraint *con = (Constraint *) cmd->def;
				Assert(IsA(con, Constraint));

				if (con->contype == CONSTR_FOREIGN)
				{
					con->skip_validation = true;
					con->initially_valid = false;
					elog(WARNING, "Foreign key constraint \"%s\" will skip validation!", con->conname);
				}
			}

			continue;
		}
	}



}
