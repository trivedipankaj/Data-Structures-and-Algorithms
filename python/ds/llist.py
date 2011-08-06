class node:
	def __init__(self,data):
		self.data = data
		self.next = None
class llist:
	def __init__(self):
		self.curr_node = None
		self.first_node= None
	def add_node(self,data):
		new_node 		= node(data)
		if self.first_node == None:
			self.first_node = new_node
			self.curr_node  = new_node
		else:
			self.curr_node.next 	= new_node
			self.curr_node		= new_node
	def print_list(self,ll):
		if ll.first_node != None:
			node = ll.first_node
			while node:
				print node.data
				node = node.next
l = llist()
a = [3,5,23,45,43]
for ai in a:
	l.add_node(ai)
l.print_list(l)
