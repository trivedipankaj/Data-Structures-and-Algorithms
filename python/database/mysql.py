import MySQLdb as mdb
import sys
try:
	conn = mdb.connect (host = "localhost",
                        user = "root",
                        passwd = "root123",
                        db = "python")
	cursor = conn.cursor ()
	cursor.execute ("INSERT INTO python.users (firstname,lastname,email,password) values('fbuser','lname','email@gmail.com',md5(123456))");
	cursor.execute("SELECT * FROM python.users");
	row = cursor.fetchall ()
	for r in row:
		print r
	cursor.execute("SELECT firstname FROM python.users WHERE email=%s","email@gmail.com");
	row = cursor.fetchall();
	print row;
	cursor.close ()
	conn.close ()
except mdb.OperationalError, e:
	print "Error %d: %s" %(e.args[0],e.args[1])
	sys.exit(1)
