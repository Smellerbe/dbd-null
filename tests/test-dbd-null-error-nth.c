#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dbi/dbi.h>

int
main (int argc, char *argv[])
{
  dbi_conn conn;
  dbi_result result;
  const char *err_msg;
  int err_code;

  if (argc < 2)
    {
      fprintf (stderr, "%s: Need a libdir as argument!\n", argv[0]);
      return 1;
    }

  dbi_initialize (argv[1]);

  conn = dbi_conn_new ("null");
  dbi_conn_connect (conn);

  dbi_conn_set_option_numeric (conn, "null.error.query.nth", 2);

  result = dbi_conn_query (conn, "SELECT * FROM DUAL");
  assert (result != NULL);
  dbi_result_free (result);

  result = dbi_conn_query (conn, "SELECT * FROM DUAL");
  assert (result == NULL);

  result = dbi_conn_query (conn, "SELECT * FROM DUAL");
  assert (result != NULL);
  dbi_result_free (result);

  /*
   * Cleanup
   */
  dbi_conn_close (conn);

  dbi_shutdown ();

  return 0;
}
