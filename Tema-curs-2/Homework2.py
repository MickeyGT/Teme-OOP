import sys
class derivate:
        givenfunct=""
        def __init__(self,name):
            self.expresie=""
            self.givenfunct=name
        def getexp(string):
            for i in range(0,len(string)):
                if string[i]=='+' or string[i]=='-':
                    funct=string[0:i]
                    return funct
        def precompute(self):
            current = self.getexp(self.givenfunct)

def menu():
    print ('Menu of the problem:')
    print ('Option 1: Read the expression:.')
    print ('Option 2: Calculate and print the derivate equivalent.')
    print ('Option 3: Exit.')
    type = input('Please select an option: ')
    if type == '1':
        print('\n')
        deriv.precompute()
        menu()
    elif type == '2':
        print('\n')
        display()
        menu()
    elif type == '3': 
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
expr='5*X**3+2*X**2+5/(X**2)'
deriv =derivate (expr)
deriv.precompute()
menu()
