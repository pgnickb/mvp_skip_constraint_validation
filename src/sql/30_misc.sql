/* src/sql/20_misc.sql */

CREATE EVENT TRIGGER force_constraint_not_valid
ON ddl_command_start
EXECUTE FUNCTION force_constraint_not_valid();
