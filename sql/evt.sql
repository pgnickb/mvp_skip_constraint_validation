\unset ECHO

/* setup */
\i test_setup.sql

/* try and create extension */
create extension evt;

/* seed random for consistent dataset */
select setseed(0.2);

select plan(1);
/* tests: */

select pass();
/* comparison operators */

select * from finish();
