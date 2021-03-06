import sys
global ok
def display():
    #the 2 available options for displaying the graph.
    print ('What kind of display do you want?')
    print ('Option 1: Adjacency Matrix.')
    print ('Option 2: Adjacency List.')
    type = input('Please select an option: ')
    if type == '1':
        print('Displaying the Adjacency Matrix:\n')
        #displaying the adjacency matrix.
        for i in range(1,n+1):
            for j in range(1,n+1):
                if matAdiac[i][j] != 0:
                    #I've used sys.stdout.write here because print would print a newline
                    #everytime I'd use it and I didn't want that.
                    sys.stdout.write('1 ')
                else:
                    sys.stdout.write('0 ')
            print('\n')
    elif type == '2':
        print('Displaying the Adjacency List:\n')
        #displaying the adjacency list for each node.
        for i in range(1,n+1):
             print('Node ',i,':',*list[i], sep=' ')
    else:
        #case for when the user picks an invalid option.
        print('Chosen option is invalid. Please pick again.\n')
        #calling the function again so the user can re-pick.
        display()
    print('\n')

def dfs(nod):
    #Standard dfs recursive function
    for i in list[nod]:
        if viz[i]==0:
            viz[i]=1
            #comp is a list that will hold the 
            #elements in the current conex component.
            comp.append(i)
            dfs(i)

def findcycle(nod):
    global ok
    #for each node connected to nod
    for i in list[nod]:
        #if it hasn't been visited.
        if viz[i]==0:
            #we mark it as visited.
            viz[i]=1
            #for each node connected to i
            for j in list[i]:
                #if it has been visited before and not by nod, then we have a cycle.
                if viz[j]==1 and j!=nod:
                    ok=1
                    #ok is the value that will tell us if we have a cycle or not.
            findcycle(i)
             
def displaycompconx():
    #comp will hold the nodes that are in the current conex component.
    global viz,comp
    comp=[]
    #We store 1 in viz[i] if i has been visited and 0 if it hasn't been visited.
    viz=[0 for x in range(100)]
    #nr will hold how many conex components we have.
    nr=0
    for i in range(1,n+1):
        if viz[i]==0:
            viz[i]=1
            dfs(i)
            comp.append(i)
            nr=nr+1
            #displaying the current conex component with its nodes.
            print('The connected conex component with the number ',nr,'is: ',*comp,sep=' ')
            #clearing the list so we can use it again.
            del comp[:]
    print('\n')

def graphisconex():
    global viz,comp
    comp=[]
    viz=[0 for x in range(100)]
    #nr will tell us how many conex components there are.
    nr=0
    for i in range(1,n+1):
        if viz[i]==0:
            viz[i]=1
            dfs(i)
            nr=nr+1
    #if there is exactly one conex component, then the graph is conex, otherwise it is not.
    if nr==1:
        print('The graph is a conex one.\n')
    else:
        print('The graph is NOT a conex one.\n')
    print('\n')    

def create():
    global n,m,list,matAdiac
    #n will hold the number of nodes our graph will have.
    n = input('How many nodes will the graph have? ')
    n = int (n)
    #list will hold the adjacency list for all our nodes.
    list=[[]for y in range(100)]
    #matAdiac will hold the adjacency matrix for all our nodes.
    #(1 if we have a path from i to j and 0 if not)
    matAdiac=[[0 for x in range(100)]for y in range(100)]
    #m will hold the number of edges our graph will have.
    m = input('How many edges will the graph have? ')
    m = int(m)
    print ('Reading the ',m,' edges:')
    for i in range(1,m+1):
        print('Node x will be tied to node y:')
        x = int(input('x = '))
        y = int(input('y = '))
        #we add the node y in x's adjacency list and matrix
        list[x].append(y)
        matAdiac[x][y]=1
        #we add the node x in y's adjacency list and matrix
        list[y].append(x)
        matAdiac[y][x]=1 
    print('\n')   
        
def menu():
    print ('Menu of the problem:')
    print ('Option 1: Creating the graph.')
    print ('Option 2: Displaying the graph.')
    print ('Option 3: Finding out if the graph is conex.')
    print ('Option 4: Finding the conex components of the graph.')
    print ('Option 5: Finding out if the graph contains cycles.')
    print ('Option 6: Exit.')
    type = input('Please select an option: ')
    if type == '1':
        print('\n')
        #the function create will create our graph's adjacency list and matrix.
        create()
        menu()
    elif type == '2':
        print('\n')
        #the function display will display either the graph's adjacency list or matrix.
        display()
        menu()
    elif type == '3':
        print('\n')
        #the function graphisconex will tell us if our graph is conex or not.
        graphisconex()
        menu()
    elif type == '4':
        print('\n')
        #the function displaycompconx will display the conex components of the graph.
        displaycompconx()
        menu()
    elif type == '5':
        print('\n')
        global ok,viz
        #ok is the variabile that will hold the answer to the question if the graph has any cycles. 
        ok=0
        viz=[0 for x in range(100)]
        #we have to do this for every node that has not been visited 
        #because we could find a cycle inside another conex component of the graph.
        for k in range(1,n+1):
            if viz[k]==0:
                viz[k]=1
                findcycle(k)
        if ok==1:
            print('The graph contains at least 1 cycle.\n')
        else:
            print('The graph does NOT contain any cycles.\n') 
        menu()
    elif type == '6': 
        print('Program will now close.')
        #not re-calling the menu the way we did with the 
        #other options so the program can now close.
    else:
        #menu for when an invalid option is picked.
        print('\n')
        print('Chosen option is invalid. Please pick again.\n')
        menu()
    print('\n')

#first call of the menu function. 
#It only needs to be called once because after 
#each operation the menu just gets called again.
menu()
