def TOH(n,start,end,aux):
    if n is 0 : 
        return
    TOH(n-1,start,aux,end)
    print("Move Disk {} from {} to  {}".format(n,start,end))
    TOH(n-1,aux,end,start)

TOH(int(input()),'A','C','B')
    
