import numpy as np
num = int(input("Enter the number of objects your have : "))
wt = [int(input("Enter Weight of object {} : ".format(i+1))) for i in range(num)]
print("Enter the corresponding weights")
val = [int(input("Enter the Value of object {} : ".format(i+1))) for i in range(num)]
total_wt = int(input("Enter the capacity of Knapsack : ")) 

DP = np.zeros((4,8)) 
for i in range(8) : 
    if i < wt[0] : 
        DP[0][i] = 0  
    else : 
        DP[0][i] = val[0]

for i in range(1,4) : 
    for j in range(8) : 
        if j < wt[i] : 
            DP[i][j] = DP[i-1][j]
        else : 
            DP[i][j] = max(val[i] + DP[i-1][j-wt[i]], DP[i-1][j])
print("The maximum value that can be taken is : ",np.max(DP))
"""i, j = np.unravel_index(DP.argmax(), DP.shape)
print("Items picked up : ")
weight = total_wt
picked = []
while weight : 
    if DP[i-1][j] is DP[i][j]  :#This item hasn't been picked up
        j = j - 1
    else : #This item has been picked up
        print("Item {} has been picked up".format(i+1))
        weight = weight - j
        i = i - 1
        j = weight
  """      
        
        
        



