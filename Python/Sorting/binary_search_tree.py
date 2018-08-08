class Node:
    def __init__(self,key = None,left = None, right = None):
       self.key = key
       self.left = left
       self.right = right
       self.successorArray = []
       self.predecessorArray = []
       self.mark = 0    #For marking key element in successor and predecessor function

class BST :
    def __init__(self,root = None):
        self.root = root 

    def insert(self,key) :
        if self.root == None :
            self.root = Node(key)
            
        else :
            new_node = Node(key)
            self.insert_helper(new_node)
    def insert_helper(self,node) :
        curr_node = self.root
        while(True) :
            if curr_node.key == node.key : 
                break
            if curr_node.key > node.key :
                if curr_node.left is None :
                    curr_node.left = node
                    break
                curr_node = curr_node.left
            if curr_node.key < node.key :
                if curr_node.right is None : 
                    curr_node.right = node
                    break
                curr_node = curr_node.right
	
    def search(self,key) :
        if self.root == None : 
                print("Binary Search Tree Empty")
                return
        curr_node = self.root
        while(True) : 
                if curr_node.key == key :
                    print("Key is present")
                    return
                if curr_node.key > key : 
                    if curr_node.left is not None : 
                        curr_node = curr_node.left
                    else :
                        print("Key Not Found")
                        return 
                else :
                    if curr_node.right is not None : 
                        curr_node = curr_node.right
                    else : 
                        print("Key Not Found")
                        return
    def inOrderTraversal(self) :#Left - Root - Right
        curr_node = self.root
        if curr_node is None : 
            print("Binary Search Tree Empty")
            return
        self.inOrderTraversalHelper(curr_node)
		
    def inOrderTraversalHelper(self,curr_node) :
        if curr_node is None : 
            return
        self.inOrderTraversalHelper(curr_node.left)
        print(curr_node.key, " ",end="")
        self.inOrderTraversalHelper(curr_node.right)
	
    def preOrderTraversal(self) : #Root - Left - Right
        curr_node = self.root
        if curr_node is None : 
            print("Binary Search Tree Empty")
            return
        self.preOrderTraversalHelper(curr_node)
		
    def preOrderTraversalHelper(self,curr_node) : 
        if curr_node is None : 
            return 
        print(curr_node.key, " ",end="")
        self.preOrderTraversalHelper(curr_node.left)
        self.preOrderTraversalHelper(curr_node.right)
	
    def postOrderTraversal(self) : #Left - Right -Root
        curr_node = self.root
        if curr_node is None : 
            print("Binary Search Tree Empty")
            return 
        self.postOrderTraversalHelper(curr_node)

    def postOrderTraversalHelper(self,curr_node) :
        if curr_node is None :
            return 
        self.postOrderTraversalHelper(curr_node.left)
        self.postOrderTraversalHelper(curr_node.right)
        print(curr_node.key, " ",end="")
    def levelOrderTraversal(self) : 
        curr_node = self.root
        if curr_node is None : 
            print("Binary Search Tree Empty")
            return
        self.levelOrderTraversalHelper(curr_node)
	
    def levelOrderTraversalHelper(self,curr_node) :#Same as Breadth First Search
        if curr_node is None : 
            return
        queue = [curr_node]
        while queue : 
            curr_node = queue[0]

            #Push
            if curr_node.left : 
                queue.append(curr_node.left)
            if curr_node.right :
                queue.append(curr_node.right)
            del queue[0] #Pop
            print(curr_node.key, " ",end="")
		
    def minimum(self) : 
        if self.root is None : 
            print("Binary Search Tree Empty")
            return
        curr_node = self.root
        while True : 
            if curr_node.left is not None : 
                curr_node = curr_node.left
            else : 
                print("Minimum is : ",curr_node.key)
                break

    def maximum(self) : 
        if self.root is None : 
            print("Binary Search Tree Empty")
            return 
        curr_node = self.root
        while True : 
            if curr_node.right is not None : 
                curr_node = curr_node.right
            else : 
                print("Maximum is  : ",curr_node.key)
                break
    def inOrderSuccessor(self,key) : 
        if self.root is None : 
            print("BST Empty")
            return
        self.inOrderSuccessorHelper(self.root,key)
    def inOrderSuccessorHelper(self,curr_node,key) : 
        if curr_node is None : 
            return
        self.inOrderSuccessorHelper(curr_node.left,key)
        self.successorArray.append(curr_node.key)
        if self.mark is 1 :
            print("Successor of {} is {}",key, successorArray[-1])
            return 
        if curr_node.key == key : 
            self.mark = 1
        self.inOrderSuccessorHelper(cur_node.right,key)

        
if __name__ == '__main__' : 
    node = int(input("Enter the Number of Nodes : "))
    bst = BST()
    for i in range(node) :
        key = int(input("Enter the key : "))
        bst.insert(key)
    print("Pre-order Traversal : ")
    bst.preOrderTraversal()
    print()
    print("Post-order Traversal : ")
    bst.postOrderTraversal()
    print()
    print("In-order Traversal :")
    bst.inOrderTraversal()
    print()
    print("Level Order Traversal :")
    bst.levelOrderTraversal()
    print()
    bst.inOrderSuccessor(input("Enter a key whose successor need to be found out"))
    print()
