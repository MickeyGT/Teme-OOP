import sys
class derivate:

        givenfunct=""

        #initialization function that will prepare for the precompute function.
        def __init__(self,name):
            #expresie will hold the final derivate espression.
            self.expresie=""
            #givenfunct is the function that has been given to us in the input
            self.givenfunct=name

        #function that will recognize what function we deal with and calculate the derivate.
        def recognize(self,string):   
            #case for when we have something like 1/(X**n)     
            if string[0:2]=='1/':
                    self.expresie=self.expresie+str(int(self.coef)*-1*int(string[6:len(string)-1]))+'/(X**'+str(int(string[6:len(string)-1])+1)+')'
            #case for when we only have X
            elif string=='X':
                self.expresie=self.expresie+str(int(self.coef)*1)
                return
            #case for when we have something like X**n
            elif string[0:3]=='X**':
                #int(string[3:6]) actually is the power of n.
                self.coef=int(self.coef)*int(string[3:6])
                if self.coef!=1:
                    #the following if is needed for when the power n equals to 1.
                    if int(string[3:6])-1!=1:
                        self.expresie=self.expresie+str(self.coef)+'*X**'+str(int(string[3:6])-1)
                    else:
                        self.expresie=self.expresie+str(self.coef)+'*X'
                else:
                     self.expresie=self.expresie+'X**'+str(int(string[3:6])-1)
            #the case for + and - are covered by the main function since they do not require to be derivated.

        #this function gets us the coefficient and the function so we can derivate the function after
        def getCoefAndFunction(self,string):
            if string[0]!='X':
                for i in range(0,len(string)):
                    #our function will be consisted of X and one of the two operators
                    #however, if it doesn't contain an operator then we consider the entire string as a function.
                    if string[i]=='*':
                        #if the coeficient is multiplied to the function, then the coeficient is the 
                        #first part of the string until * and the function is the part after the *
                        self.coef=string[0:i]
                        self.funct=string[i+1:len(string)]
                        return 
                    elif string[i]=='/':
                        #if however we have / then the coeficient is the first part of the string until /
                        #but the function is going to be something like this '/(x+1)' so we have to add a 1.
                        self.coef=string[0:i]
                        self.funct="1"+string[i:len(string)]
                        return
                #in case there is no function, the coef will be 1 and the function will be the entire string
                self.coef='1'
                self.funct=string
                return
            else:
            #this case is for when we are dealing with a constant.
                self.coef='1'
                self.funct=string
                return
 
        #this function will get us the current function and coefficient we're going to derivate.
        def getexp(self,string):
            for i in range(0,len(string)):
                #we use + and - to separate simple functions between each other for when we derivate them.
                if string[i]=='+' or (string[i]=='-'and i!=0):
                    funct=string[0:i]
                    self.givenfunct=self.givenfunct[i:len(string)]
                    return funct
            self.givenfunct=""
            return string

        def precompute(self):
            #while we still have something that needs to be derivated
            while(self.givenfunct):
                #current will hold the function and coefficient that will be derivated.
                current = self.getexp(self.givenfunct)
                #coef will be 1 at first
                self.coef='1'
                #we call this function so that we can separate the coefficient from the function.
                self.getCoefAndFunction(current)
                #the recognize function will now recognize what derivate it is 
                #and apply the respective formula while keeping in mind the coef
                self.recognize(self.funct)
                #this if is so we don't have 2 signs one after another if we have derivates equal to 0
                if self.expresie!='' and (self.expresie[len(self.expresie)-1]!='+' and self.expresie[len(self.expresie)-1]!='-'):
                    self.expresie=self.expresie + self.givenfunct[0:1]
                #this deletes the first character which is the sign between 2 functions that will need to be derivated
                self.givenfunct=self.givenfunct[1:len(self.givenfunct)]
            #this for is needed in case we have 2 consecutive signs due to number signs and operation sign
            for i in range(0,len(self.expresie)-1):
                if self.expresie[i:i+2]=='+-':
                    self.expresie=self.expresie[:i]+self.expresie[i+1:len(self.expresie)]
                elif self.expresie[i:i+2]=='-+' or self.expresie[i:i+2]=='--':
                    self.expresie=self.expresie[:i+1]+self.expresie[i+2:len(self.expresie)]
            
#menu function that will take care of handling the input.
def menu():
    print ('Menu of the problem:')
    print ('Option 1: Read the expression: ')
    print ('Option 2: Calculate and print the derivate equivalent.')
    print ('Option 3: Exit.')
    type = input('Please select an option: ')
    if type == '1':
        #expr will hold the function only with "X"
        global expr
        expr=''
        #we will convert all the "x" from the inpt string to "X" and store the resoult in expr.
        inpt=input('Write the expression: ')
        #this is needed in case the user writes the function with "x" 
        #because the program only works with "X"
        for i in range(0,len(inpt)):
            if inpt[i]=='x':
                expr+='X'
            else:
                expr+=inpt[i]
        print('\n')
        menu()
    elif type == '2':
        print('\n')
        #creating the object we will be working with.
        deriv =derivate (expr)
        #calling the precompute function that will derivate the function and store it in expresie
        deriv.precompute()
        print('The derivated expression is: ')
        #in case the given function only consisted of constants and its derivate is nothing.
        if(deriv.expresie==''):
            print('0')
        else:
            print (deriv.expresie)
        print('\n')
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
menu()
