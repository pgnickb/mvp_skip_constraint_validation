/* src/sql/10_functions.sql */

CREATE OR REPLACE FUNCTION force_constraint_not_valid()
RETURNS event_trigger
LANGUAGE c AS 'MODULE_PATHNAME','force_constraint_not_valid_sql';

