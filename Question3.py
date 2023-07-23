'''
@author
Name: Muhammad Yameen
Email: yameenmuhammad960@gmail.com

'''

import psycopg2
from psycopg2.extras import JSONConnection


def connect():
    """ Connect to the PostgreSQL database server """
    conn = None
    # read connection parameters
    db_host = "localhost"
    db_name = "test"
    db_user = "postgres"
    db_password = "Yameen@123"
    try:

        # Create a cursor using the custom JsonCursor class
        conn = psycopg2.connect(
            host=db_host,
            dbname=db_name,
            user=db_user,
            password=db_password,
            connection_factory=JSONConnection
        )

        cur = conn.cursor()
        # Execute a query and fetch the results
        cur.execute("SELECT * FROM public.user_table")
        rows = cur.fetchall()
        # Print the JSON string
        for row in rows:
            print(row)
        # Close the cursor and the database connection
        cur.close()
    except (Exception, psycopg2.DatabaseError) as error:
        print(error)
    finally:
        if conn is not None:
            conn.close()
            print('Database connection closed.')


if __name__ == '__main__':
    connect()
