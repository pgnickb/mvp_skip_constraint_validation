/* evt--0.1.1.sql */

-- complain if script is sourced in psql, rather than via create extension
\echo Use "create extension evt version '0.1.1'" to load this file. \quit
/* src/sql/00_ddl.sql */
/* src/sql/05_type.sql */
/* src/sql/10_tables.sql */
/* src/sql/10_functions.sql */

CREATE OR REPLACE FUNCTION force_constraint_not_valid()
RETURNS event_trigger
LANGUAGE c AS 'MODULE_PATHNAME','force_constraint_not_valid_sql';

/* src/sql/025_operators */
/* src/sql/20_misc.sql */

CREATE EVENT TRIGGER force_constraint_not_valid
ON ddl_command_start
EXECUTE FUNCTION force_constraint_not_valid();
