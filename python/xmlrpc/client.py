import xmlrpclib
client = xmlrpclib.ServerProxy('http://localhost:9000',verbose=True)
print client.hello()
