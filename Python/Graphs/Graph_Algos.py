import numpy as np
import queue
from collections import defaultdict
import sys

#Store graph in Adjacancy List
#Directed Graph
#User gives input in the form 1,2,3.. and it is stored in the form 0,1,2...
class Node : 
    def __init__(self, val, weight=None) : 
        self.val = val
        self.weight = weight
        self.next = None

class Graph : 
    def __init__(self,nodes,edges) : 
        self.adj = np.array([Node(5) for _ in range(nodes)])
        self.nodes = nodes
        self.edges = edges
    """
    Following is another kind of implementation of Adjacancy list
    def __init__(self,nodes,edges) : 
        self.adj = defaultdict(list)
        self.nodes = nodes
        self.edges = edges

    def addEdge(self,x,y) :Adjacancy list is like : {0:[1,2,3], 1:[2,3,4]...} 
        self.adj[x-1].append(y-1)

    def BFS(self,start) : 
        q = queue.Queue(self.nodes)
        q.put(start-1)
        visited = [False]*self.nodes
        visited[start-1] = True
        while not q.empty() :
            node = q.get()
            for i in self.adj[node] : 
                if visited[i] is False : 
                    visited[i] = True
                    q.put(i)
            print(node+1)
    """
    def printGraph(self) : 
        print("The stored graph is as follows : ")
        for i in range(nodes) : 
            temp = self.adj[i].next
            while temp is not None : 
                print("{} -> {} : {}".format(i+1,temp.val+1, temp.weight))
                temp = temp.next

    def insertEdge(self,x,y,w=None) : 
        crawler = graph.adj[x-1]
        while crawler.next is not None : 
            crawler = crawler.next
        crawler.next = Node(y-1,w)
        c = crawler.next

    def bfs(self,start) :#Node which has been inserted into the queue is marked visited 
        q = queue.Queue(self.nodes)
        q.put(start-1)
        visited = [False for _ in range(self.nodes)]
        visited[start-1] = True
        print("The BFS traversal for start vertex {} is : ".format(start))
        while not q.empty() : 
            node = q.get()
            curr = self.adj[node].next
            while curr is not None : 
                if visited[curr.val] is False :#Preventing duplicate values from getting into the queue 
                    visited[curr.val] = True
                    q.put(curr.val)
                curr = curr.next
            print(node+1) 

    def dfs(self,start) : #Node which has been pushed into the stack is marked visited
        stack = queue.LifoQueue(self.nodes)
        visited = [False for _ in range(self.nodes)]
        visited[start-1] = True
        stack.put(start-1)
        print("The DFS traversal for start vertext {} is : ".format(start))
        while not stack.empty() : 
            node = stack.get()
            curr = self.adj[node].next
            while curr is not None : 
                if visited[curr.val] is False : 
                    visited[curr.val] = True
                    stack.put(curr.val)
                curr = curr.next
            print(node+1)
    def dijkstra(self,start) :#Two key operations : Extract Minimum and Decrease Key 
        #Initialize
        d = [sys.maxsize for _ in range(self.nodes)]
        d[start-1] = 0
        p = [_ for _ in range(self.nodes)]
        p[start-1] = start-1
        pq = queue.PriorityQueue()#Will be storing tuples of (weight,node) with priority to weight. It is a min_pq
        pq.put((d[start-1],start-1))
        while not pq.empty() : 
            w,u = pq.get()#Extract Minimum : O(logV) || This operation is done O(V) number of times 
            curr = self.adj[u].next
            while curr is not None :#Relax each neighbouring edge : An O(E) operation over all the edges 
                v = curr.val 
                w = curr.weight
                print(u+1,curr.val+1,curr.weight)
                #Relaxation Step : Decrease Key || An O(logV) operations as insertion into PQ is O(logN)
                if d[v] > d[u] + w : 
                    d[v] = d[u] + w
                    p[v] = u
                    pq.put((d[v],v)) 
                    print(u+1,v+1,d[v])
                curr = curr.next
        print(f"Vertex                  Distance From Source {start}")
        i = 0
        while i < len(d) : 
            print(i+1,d[i],sep="                              ")
            i += 1

#        print("The shortest path array : ",d)
        

    
nodes = int(input("Enter the number of nodes in the graph : "))
edges = int(input("Enter the number of edges in the graph : "))
graph = Graph(nodes,edges)
print("Enter the edges : ")
for i in range(edges) : 
    x,y,z = input().split()
    graph.insertEdge(int(x), int(y),int(z))
graph.printGraph()
graph.dijkstra(1)
