from SimpleXMLRPCServer import SimpleXMLRPCServer
import xmlrpclib
def add(n1,n2):
	return int(n1)+int(n2)
class My:
	def __init__(self):
		print "New World"
	def __del__(self):
		print "Dying.."

server = SimpleXMLRPCServer(('localhost',9000), allow_none=True)
print "Listening at the port 9000..."
server.register_multicall_functions()
server.register_function(add,'add')
server.register_instance(My(),'my')
server.register_introspection_functions()
try:
	server.serve_forever()
except KeyboardInterrupt:
	print "Exiting..."
finally:
	server.server_close()
